/*
 * File.cpp
 *
 *  Created on: Nov. 2017
 *      Author: aleksandr.yanovskiy
 */

#include "File.h"

namespace graf {

File::File(std::string fileName): fileName_(fileName),
  	  	          	  	  	  	  oldTrdosName_(""),
								  nameBoot_("boot    ") {


}

File::~File() {

}



/**
 *
 */
void File::read(strctHeadData& strHeadData, int position) {
	std::ifstream infile(fileName_.c_str(), std::ios::binary);
	if (!infile)
		throw std::runtime_error("Error open file");

	infile.seekg(position);
	infile.read(reinterpret_cast<char*>(strHeadData.pStrctData), strHeadData.size);
	infile.close();
}

/**
 *
 */
void File::write(strctHeadData& strHeadData, int position) {
	std::ofstream outfile(fileName_.c_str(), std::ios::in | std::ios::binary); //да-да, для тогда чтобы добавлять запись в середину, не стирая весь файл, нужно указать ios::in | ios::out (ios::out указан по умолчанию для ofstream)
	if (!outfile)
		throw std::runtime_error("Error open file");

	outfile.seekp(position);
	outfile.write(reinterpret_cast<char*>(strHeadData.pStrctData), strHeadData.size);
	outfile.close();
}


/**
 * check 2 names with size
 * name can be without \0 ends
 */
bool File::compareUppName(const char* firstName, const char* secondName, unsigned int sizeName) {
	unsigned char firstUpperChar;
	unsigned char secondUpperChar;
	for (unsigned int i = 0; i < sizeName; i++) {
		firstUpperChar = firstName[i];
		if (firstUpperChar >= 97)
			firstUpperChar = firstUpperChar - 32;

		secondUpperChar = secondName[i];
		if (secondUpperChar >= 97)
			secondUpperChar = secondUpperChar - 32;

		if (firstUpperChar != secondUpperChar)
			return false;
	}
	return true;
}

/**
 *
 */
bool File::compareName(const char* firstName, const char* secondName, unsigned int sizeName) {
	for (unsigned int i = 0; i < sizeName; i++) {
		if (firstName[i] != secondName[i])
			return false;
	}
	return true;
}


std::string File::getOldName() {
	return oldTrdosName_;
}

} /* namespace graf */
