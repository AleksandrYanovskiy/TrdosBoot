/*
 * BAD.h
 *
 *  Created on: 05 Sept. 2018 г.
 *      Author: aleksandr.yanovskiy
 */

#ifndef MODULE_FILE_BAD_BAD_H_
#define MODULE_FILE_BAD_BAD_H_

#include "../File.h"

namespace graf {

class BAD: public File {
public:
	BAD(std::string fileName);
	virtual ~BAD();
	void rename();
};

} /* namespace graf */

#endif /* MODULE_FILE_BAD_BAD_H_ */
