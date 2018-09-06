/*
 * TRD.cpp
 *
 *  Created on: Nov. 2017
 *      Author: aleksandr.yanovskiy
 */

#include "TRD.h"

namespace graf {


TRD::TRD(std::string fileName): File(fileName) {
}

TRD::~TRD() {
	// TODO Auto-generated destructor stub
}


/**
 *
 */
void TRD::rename() {
	//get disk header and check it
	//description signature
	strHeadData_.start = 2048 + 227;
	strHeadData_.size = sizeof(strDataSpecification_);
	strHeadData_.pStrctData = &strDataSpecification_;

	read(strHeadData_, strHeadData_.start);
	if (strDataSpecification_.diskType != 22 && strDataSpecification_.diskType != 23 && strDataSpecification_.diskType != 24 && strDataSpecification_.diskType != 25 && strDataSpecification_.trdosId != 16)
		throw std::runtime_error("Disk type is not TR_DOS");

	if (strDataSpecification_.fileCount == 0)
		throw std::runtime_error("Sinclair file count is zero");

	//read file structure
	//description file structure
	strHeadData_.start = 0;
	strHeadData_.size = sizeof(strDataDirectory_);
	strHeadData_.pStrctData = &strDataDirectory_;
	//search boot.B and first basic file
	bool isfileFound = false;
	for (unsigned int i = 0; i < 128; i++) {

		//read directory structure
		read(strHeadData_, strHeadData_.start + (strHeadData_.size * i) );

		//search boot
		if ( compareName(nameBoot_, strDataDirectory_.fileName, sizeof(strDataDirectory_.fileName) + sizeof(strDataDirectory_.fileExt)) ) {
			throw std::runtime_error("boot.B already present");
		}

		if (strDataDirectory_.fileName[0] == '\0') {
			break;
		}

		//search first Basic file - is basic and not erased
		if ( (strDataDirectory_.fileExt == 'B') && (strDataDirectory_.fileName[0] != '\1') ) {
			isfileFound = true;

			//rename file
			for (unsigned int k = 0; k < sizeof(strDataDirectory_.fileName); k++) {
				oldTrdosName_ += strDataDirectory_.fileName[k];
				strDataDirectory_.fileName[k] = nameBoot_[k];
			}

			//write changes
			write(strHeadData_, strHeadData_.start  + (strHeadData_.size * i));

			break;
		}
	}

	if (!isfileFound )
		throw std::runtime_error("Basic file not found");

}

} /* namespace graf */ 
