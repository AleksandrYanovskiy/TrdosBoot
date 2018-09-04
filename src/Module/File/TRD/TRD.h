/*
 * TRD.h
 *
 *  Created on: Nov. 2017
 *      Author: aleksandr.yanovskiy
 */

#ifndef MODULE_FILE_TRD_TRD_H_
#define MODULE_FILE_TRD_TRD_H_

#include "../File.h"

namespace graf {

class TRD: public File {
public:
	TRD(std::string fileName);
	virtual ~TRD();
	void rename();

private:
	//signature
	struct strDataSpecification: public strctData{
		unsigned char diskType;		  //22 or 23 or 24 or 25
		unsigned char fileCount;
		unsigned char freeSectors[2];
		unsigned char trdosId;		  //16
	};

	//directory type
	struct strDataDirectory: public strctData{
		char fileName[8];
		char fileExt;
		unsigned char fileParams[4];
		unsigned char fileLength;
		unsigned char startSector;
		unsigned char startTrack;
	};

	strDataSpecification strDataSpecification_;
	strDataDirectory strDataDirectory_;
};

} /* namespace graf */

#endif /* MODULE_FILE_TRD_TRD_H_ */ 
