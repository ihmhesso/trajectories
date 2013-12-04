/**
 * @brief Debug/print functions
 * @file ihmfootprint_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmfootprint.h"


/**
 * Class print data (formated output)
 * @param out
 * @param footprint IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMFootprint& footprint)
{
	out << "CIHMFootprint, " <<  footprint.version_get() << endl;

	return(out);
}

