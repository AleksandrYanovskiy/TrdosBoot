//============================================================================
// Name        : TrdosBoot.cpp
// Author      : Aleksandr Yanovskiy
// Version     : 1.10
// License     : GPLv3
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
	char* cParam;
	char* cPath;

	bool isParamErros = false;
	bool isProcessing = false;

	//check arguments
	if (argc == 2) {
		cParam  = argv[1];

		if ( (strcmp(cParam, "-h") == 0) || (strcmp(cParam, "--help") == 0) ) {
			graf::Help::show(APP_NAME, false);
		}
		else if (cParam[0] == '-') {
			isParamErros = true;
		}
		else {
			cPath = cParam;
			isProcessing = true;
		}
	}
	else
		isParamErros = true;


	if (isProcessing) {
	//run file processing
		try {
			graf::Processing::run(cPath);
		}
		catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	else if (isParamErros) {
		graf::Help::show(APP_NAME, true);
		return 1;
	}

	return 0;
} 
