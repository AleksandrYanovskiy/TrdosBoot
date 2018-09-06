/*
 * BAD.cpp
 *
 *  Created on: 05 Sept. 2018 г.
 *      Author: aleksandr.yanovskiy
 */

#include "BAD.h"

namespace graf {

BAD::BAD(std::string fileName): File(fileName) {
	// TODO Auto-generated constructor stub

}

BAD::~BAD() {
	// TODO Auto-generated destructor stub
}

void BAD::rename() {
	throw std::runtime_error("File is not supported!");
}

} /* namespace graf */
