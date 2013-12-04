/**
 * @brief Get/set functions definition
 * @file ihmbackground.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmbackground.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMBackground::version_get(void) const
{
	stringstream out;

	int major = kCIHMBackground_VERSION_MAJOR_NUMBER;
	int minor = kCIHMBackground_VERSION_MINOR_NUMBER;
	int patch = kCIHMBackground_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


