/*
 * SCL.h
 *
 *  Created on: Nov. 2017
 *      Author: aleksandr.yanovskiy
 */

#ifndef MODULE_FILE_SCL_SCL_H_
#define MODULE_FILE_SCL_SCL_H_

#include "../File.h"

namespace graf {

class SCL: public File {
public:
	SCL(std::string fileName);
	virtual ~SCL();
	void rename();

private:

	//signature
	struct strDataSignature: public strctData{
		char labelSinclair[8];
		unsigned char fileCount;
	};

	//directory type
	struct strDataDirectory: public strctData{
		char fileName[8];
		char fileExt;
		unsigned char fileParams[4];
		unsigned char fileLength;
	};

	strDataSignature strDataSignature_;
	strDataDirectory strDataDirectory_;

	const char labelSCL_[9];

};

} /* namespace graf */

#endif /* MODULE_FILE_SCL_SCL_H_ */ 
