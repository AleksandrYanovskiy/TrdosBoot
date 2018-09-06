/*
 * Processing.cpp
 *
 *  Created on: Nov. 2017
 *      Author: aleksandr.yanovskiy
 */

#include "Processing.h"

namespace graf {


/**
 * processing file or files...
 * filename - single file
 *
 */
//void Processing::run(std::string fileName) {
void Processing::run(char* filePath) {

	std::string upperFileName;
	std::string upperFileExt;
	std::string dirName;


	//std::cout << "File path: " << filePath << std::endl;


	//get file name
	upperFileName = upperCase(getFileName(filePath));

	if ( upperFileName.empty() )
		throw std::runtime_error("The file name must be specified!");

	//std::cout << "upper file name: " << upperFileName << std::endl;

	//get extension
	upperFileExt = upperCase(getFileExt(filePath));

	//std::cout << "Upper file ext: " << upperFileExt << std::endl;

	if ( (upperFileExt != "SCL") && (upperFileExt != "TRD") ) {
		throw std::runtime_error("File extension must be SCL or TRD!");
	}

	dirName = getDirName(filePath);
	if (dirName.empty())
		dirName = "./";

	//std::cout << "Dir name: " << dirName << std::endl;

	DIR* pDir;
	struct dirent* entry;
	std::string upperCurrFileName;
	std::string currFileName;
	graf::File* pFileMod;
	unsigned int fileCountAll = 0;
	unsigned int fileCountOk = 0;
	unsigned int fileCountNo = 0;

	if ( (pDir = opendir(dirName.c_str())) != NULL ) {
		logln("Processing...");
		while ( (entry = readdir(pDir)) != NULL ) {

			//std::cout << "entry->d_name=" << entry->d_name << std::endl;

			 if( ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) || (entry->d_type == DT_DIR) ) {
				 continue;
			 }

			 upperCurrFileName = upperCase(entry->d_name);
			 currFileName = entry->d_name;

			 //compare name
			 if ( ( (upperFileName + "." + upperFileExt) == upperCurrFileName) || ((upperFileName == "*") && (upperFileExt == getFileExt(currFileName)) ) ) {
				 fileCountAll++;
				 log("\trename > ");
				 logt(entry->d_name, 0, 20);

				 if (upperFileExt == "SCL")
					 pFileMod = new graf::SCL(dirName + entry->d_name);
				 else if (upperFileExt == "TRD")
					 pFileMod = new graf::TRD(dirName + entry->d_name);
				 else
					 pFileMod = new graf::BAD(dirName + entry->d_name);

				 try {
					 pFileMod->rename();
					 fileCountOk++;
					 log(" <OK>  ");
					 logt("Renamed file \"", 2, 0);
					 log(pFileMod->getOldName().c_str());
					 logln("\"");
				 }
				 catch (std::exception &e) {
					 fileCountNo++;
					 log(" <NO>  ");
					 log("Error: ");
					 logln(e.what());
				 }
				 delete pFileMod;
			 }

		}
		closedir(pDir);
		logln("Processed: ");
		logt("\tok: ", 0, 6);
		logln(fileCountOk);
		logt("\tno: ", 0, 6);
		logln(fileCountNo);
		logt("\tall: ", 0, 6);
		logln(fileCountAll);

	}
	else {
		throw std::runtime_error("ERROR open directory: " + dirName);
	}

}


std::string Processing::getDirName(std::string fileName) {
	std::string cRes = fileName.substr(0, fileName.find_last_of('/') + 1);
	return cRes;
}

/**
 *
 */
std::string Processing::getFileName(std::string fileName) {
	std::size_t foundDelem = fileName.find_last_of('/') + 1;
	std::size_t foundDote = fileName.find_last_of('.');

	//std::cout << "foundDelem = " << foundDelem << std::endl;
	//std::cout << "foundDote = " << foundDote << std::endl;

	std::string cRes = fileName.substr(foundDelem, foundDote - foundDelem );

	//std::cout << "cRes=" << cRes << std::endl;

	return cRes;
}

/**
 *
 */
std::string Processing::getFileExt(std::string fileName) {
	std::string cRes = "";
	std::size_t found = fileName.find_last_of('.');
	if (found != std::string::npos)
	  cRes = fileName.substr(found + 1);
	return cRes;
}

template<typename T>
void Processing::log(T msg) {
	std::cout << msg;
}

template<typename T>
void Processing::logln(T msg) {
	std::cout << msg << std::endl;
}

/**
 * tabulated print
 * adj - 0-left, 1-internal, 2-right
 * tab - setw interval
 */
template<typename T>
void Processing::logt(T msg, char adj, int tab) {
	switch (adj) {
	case 0:
		std::cout << std::left << std::setw(tab) << msg;
		break;
	case 1:
		std::cout << std::internal << std::setw(tab) << msg;
		break;
	case 2:
		std::cout << std::right << std::setw(tab) << msg;
		break;
	}
}

/**
 * upper case
 */
std::string Processing::upperCase(std::string lowerString) {
	std::string sRes = lowerString;
	std::transform(sRes.begin(), sRes.end(), sRes.begin(), ::toupper);
	return sRes;
}

/**
 * compare file pattern with file name
 */
bool Processing::compareFileName(std::string filePattern, std::string fileName) {
	if (filePattern.length() == 3) {
		//find by extension only
		std::string sExt = getFileExt(fileName);
		if (sExt == filePattern)
			return true;
	}
	else {
		//find by file name
		if (fileName == filePattern)
			return true;
	}

	return false;
}

} /* namespace graf */ 
