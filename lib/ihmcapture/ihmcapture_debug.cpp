/**
 * @brief Debug/print functions
 * @file ihmcapture_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmcapture.h"


/**
 * Class print data (formated output)
 * @param out
 * @param cap IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMCapture& cap)
{
	out << "CIHMCapture, " <<  cap.version_get() << endl;

	return(out);
}

