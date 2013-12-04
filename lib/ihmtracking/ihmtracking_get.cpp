/**
 * @brief Get/set functions definition
 * @file ihmtracking.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmtracking.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMTracking::version_get(void) const
{
	stringstream out;

	int major = kCIHMTracking_VERSION_MAJOR_NUMBER;
	int minor = kCIHMTracking_VERSION_MINOR_NUMBER;
	int patch = kCIHMTracking_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


