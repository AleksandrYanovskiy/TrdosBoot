/*
 * Help.cpp
 *
 *  Created on: Nov. 2017
 *      Author: aleksandr.yanovskiy
 */

#include "Help.h"

namespace graf {

void Help::show(const char* ProgName, bool error) {
	if (!error) {
		std::cout << "TrdosBoot ver. 1.10" << std::endl;
		std::cout << "Find first Basic file with extension B, and rename it to boot.B in image file TRD or SCL." << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "Parameters error!" << std::endl;
	}

	std::cout << "Usage: " << ProgName << " [path]" << std::endl;

	if (!error) {
		std::cout << "\t-h | --help \t\tshow help information" << std::endl;
		std::cout << "\tpath \t\t\tpath name or file name where are tr-dos image files (extension SCL or TRD is required)" << std::endl;
		std::cout << std::endl;
		std::cout << "Writen by Aleksandr Yanovskiy. Nov. 2017" << std::endl;
		std::cout << "https://github.com/AleksandrYanovskiy/TrdosBoot/" << std::endl;
	}
}


} /* namespace graf */ 
