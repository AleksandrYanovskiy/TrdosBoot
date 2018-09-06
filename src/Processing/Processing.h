/*
 * Processing.h
 *
 *  Created on: Nov. 2017
 *      Author: aleksandr.yanovskiy
 */

#ifndef PROCESSING_PROCESSING_H_
#define PROCESSING_PROCESSING_H_

#include <iomanip>
#include <iostream>
#include <dirent.h>
#include <libgen.h>
#include <string.h>
#include <string>
#include <algorithm>
#include "../Module/File/File.h"
#include "../Module/File/SCL/SCL.h"
#include "../Module/File/TRD/TRD.h"
#include "../Module/File/BAD/BAD.h"

#include <stdexcept>

namespace graf {

class Processing {
public:
	static void run(char* filePath);

protected:
	template<typename T>
	static void log(T msg);

	template<typename T>
	static void logln(T msg);

	template<typename T>
	static void logt(T msg, char adj = 0, int tab = 16);

	static std::string getDirName(std::string fileName);
	static std::string getFileName(std::string fileName);
	static std::string getFileExt(std::string fileName);
	static std::string upperCase(std::string lowerString);
	static bool compareFileName(std::string filePattern, std::string fileName);

};

} /* namespace graf */

#endif /* PROCESSING_PROCESSING_H_ */ 
