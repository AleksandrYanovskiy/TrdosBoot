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
void Processing::run(std::string fileName) {

	std::string upperFileName = upperCase(fileName);

	if ( (upperFileName.length() == 3) && ( (upperFileName != "TRD") && upperFileName != "SCL") ) {
		throw std::runtime_error("File extension must be SCL or TRD !");
	}

	//get extension
	std::string fileExt = getFileExt(upperFileName);
	if ( (fileExt.empty()) || ((fileExt != "SCL") && (fileExt != "TRD")) ) {
		throw std::runtime_error("File extension must be SCL or TRD !");
	}

	std::string dirName = ".";

	DIR* pDir;
	struct dirent* entry;
	std::string upperCurrFileName;
	graf::File* pFileMod;
	unsigned int fileCountAll = 0;
	unsigned int fileCountOk = 0;
	unsigned int fileCountNo = 0;
	//todo распарсить директорию, если она понадобиться
	if ( (pDir = opendir(dirName.c_str())) != NULL ) {
		logln("Processing...");
		while ( (entry = readdir(pDir)) != NULL ) {
			 if( ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) || (entry->d_type == DT_DIR) ) {
				 continue;
			 }

			 upperCurrFileName = upperCase(entry->d_name);
			 //compare name
			 if (compareFileName(upperFileName, upperCurrFileName)) {
				 fileCountAll++;
				 log("\trename > ");
				 logt(entry->d_name);

				 if (fileExt == "SCL")
					 pFileMod = new graf::SCL(entry->d_name);
				 else /*if (fileExt == "TRD")*/
					 pFileMod = new graf::TRD(entry->d_name);

				 try {
					 pFileMod->rename();
					 fileCountOk++;
					 log("<OK>  ");
					 log("Renamed file \"");
					 log(pFileMod->getOldName().c_str());
					 logln("\"");
				 }
				 catch (std::exception &e) {
					 fileCountNo++;
					 log("<NO>  ");
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


/**
 *
 */
std::string Processing::getFileName(std::string fileName) {
	std::string cRes = fileName.substr(0, fileName.find_last_of('.'));
	return cRes;
}

/**
 *
 */
std::string Processing::getFileExt(std::string fileName) {
	std::string cRes = fileName.substr(fileName.find_last_of('.') + 1);
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
