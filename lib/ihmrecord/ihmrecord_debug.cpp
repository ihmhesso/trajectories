/**
 * @brief Debug/print functions
 * @file ihmrecord_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmrecord.h"


/**
 * Class print data (formated output)
 * @param out
 * @param rec IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMRecord& rec)
{
	out << "CIHMRecord, " <<  rec.version_get() << endl;

	return(out);
}

