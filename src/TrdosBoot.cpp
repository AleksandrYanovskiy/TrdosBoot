//============================================================================
// Name        : TrdosBoot.cpp
// Author      : Aleksandr Yanovskiy
// Version     : 1.00
// Copyright   : GPLv3
// Description : Find and rename Basic falie in TRD or SCL files to boot.B
// 				 for autoran them in tr-dos Zx Spectrum
//
// www.zx-modules.de
//
// scl format:
//		speccy.info/SCL
//		http://www.zx-modules.de/fileformats/sclformat.html
//
// trd format:
//		speccy.info/TRD
//		www.zx-modules.de/fileformats/trdformat.html
//============================================================================

#include <iostream>
#include <string.h>
#include "Module/Help/Help.h"
#include "Processing/Processing.h"

#define APP_NAME "TrdosBoot"

using namespace std;

int main(int argc, char* argv[]) {

	//check arguments
	if (argc > 1) {
		char* cParam = argv[1];

		//showhelp
		if ( (strcmp(cParam, "-h") == 0) || (strcmp(cParam, "--help") == 0) ) {
			graf::Help::show(APP_NAME);
		}
		else {
			//run file processing
			try {
				graf::Processing::run(cParam);
			}
			catch (std::exception &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}

		}
	}
	else {
		graf::Help::show(APP_NAME);
	}

	return 0;
} 
