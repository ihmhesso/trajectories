/**
 * @brief Debug/print functions
 * @file ihmfriend_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmfriend.h"


/**
 * Class print data (formated output)
 * @param out
 * @param fr IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMFriend& fr)
{
	out << "CIHMFriend, " <<  fr.version_get() << endl;

	return(out);
}

