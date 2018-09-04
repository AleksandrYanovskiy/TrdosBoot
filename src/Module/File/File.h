/*
 * File.h
 *
 *  Created on: Nov. 2017
 *      Author: aleksandr.yanovskiy
 */

#ifndef MODULE_FILE_FILE_H_
#define MODULE_FILE_FILE_H_

#include <iostream>
#include <fstream>


namespace graf {

class File {
public:
	File(std::string fileName);
	virtual ~File();

	virtual void rename() = 0;
	std::string getOldName();

protected:
	//structure for different types of data
	struct strctData{

	};

	//main structure description
	struct strctHeadData{
		int start;
		int size;
		strctData* pStrctData;
	};

	strctHeadData strHeadData_;
	std::string fileName_;
	std::string oldTrdosName_;
	const char nameBoot_[9];
	void read(strctHeadData& strHeadData, int position = 0);
	void write(strctHeadData& strHeadData, int position = 0);
	bool compareUppName(const char* firstName, const char* secondName, unsigned int sizeName);
	bool compareName(const char* firstName, const char* secondName, unsigned int sizeName);

};

} /* namespace graf */

#endif /* MODULE_FILE_FILE_H_ */ 
