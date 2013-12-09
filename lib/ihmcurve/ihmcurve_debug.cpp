/**
 * @brief Debug/print functions
 * @file ihmcurve_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmcurve.h"


/**
 * Class print data (formated output)
 * @param out
 * @param curve IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMCurve& curve)
{
	out << "CIHMCurve, " <<  curve.version_get() << endl;

	return(out);
}

