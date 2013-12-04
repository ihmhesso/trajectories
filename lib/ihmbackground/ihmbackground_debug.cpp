/**
 * @brief Debug/print functions
 * @file ihmbackground_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmbackground.h"


/**
 * Class print data (formated output)
 * @param out
 * @param bg IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMBackground& bg)
{
	out << "CIHMBackground, " <<  bg.version_get() << endl;

	return(out);
}

