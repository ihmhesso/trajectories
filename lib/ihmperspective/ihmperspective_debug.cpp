/**
 * @brief Debug/print functions
 * @file ihmperspective_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmperspective.h"


/**
 * Class print data (formated output)
 * @param out
 * @param persp IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMPerspective& persp)
{
	out << "CIHMPerspective, " <<  persp.version_get() << endl;
	out << "  coordCount_: " << persp.coordCount_ << endl;

	return(out);
}

