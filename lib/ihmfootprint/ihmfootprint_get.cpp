/**
 * @brief Get/set functions definition
 * @file ihmfootprint.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmfootprint.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMFootprint::version_get(void) const
{
	stringstream out;

	int major = kCIHMFootprint_VERSION_MAJOR_NUMBER;
	int minor = kCIHMFootprint_VERSION_MINOR_NUMBER;
	int patch = kCIHMFootprint_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


