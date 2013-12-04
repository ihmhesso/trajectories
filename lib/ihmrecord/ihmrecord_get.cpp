/**
 * @brief Get/set functions definition
 * @file ihmrecord.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmrecord.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMRecord::version_get(void) const
{
	stringstream out;

	int major = kCIHMRecord_VERSION_MAJOR_NUMBER;
	int minor = kCIHMRecord_VERSION_MINOR_NUMBER;
	int patch = kCIHMRecord_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


