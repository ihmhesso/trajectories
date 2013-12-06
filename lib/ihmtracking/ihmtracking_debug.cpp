/**
 * @brief Debug/print functions
 * @file ihmtracking_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmtracking.h"


/**
 * Class print data (formated output)
 * @param out OUT
 * @param tracking IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMTracking& tracking)
{
	out << "CIHMTracking, " <<  tracking.version_get() << endl;

	return(out);
}

