/*
 * Help.cpp
 *
 *  Created on: Nov. 2017
 *      Author: aleksandr.yanovskiy
 */

#include "Help.h"

namespace graf {

void Help::show(const char* ProgName) {
	std::cout << "TrdosBoot ver. 1.00" << std::endl;
	std::cout << "usage: " << ProgName << " filename" << std::endl;
	std::cout << "Find first Basic file with extension B, and rename it to boot in image file TRD or SCL." << std::endl;
	std::cout << "filename - name, or extension: src or trd" << std::endl;
	std::cout << "if set extension, processing all files with this extension" << std::endl;
	std::cout << "Writen by Aleksandr Yanovskiy. November 2017" << std::endl;
}


} /* namespace graf */ 
