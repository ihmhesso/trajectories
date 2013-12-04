/**
 * @brief Debug/print functions
 * @file ihmtracking_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmtracking.h"


/**
 * Class print data (formated output)
 * @param out
 * @param track IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMTracking& track)
{
	out << "CIHMTracking, " <<  track.version_get() << endl;

	return(out);
}

