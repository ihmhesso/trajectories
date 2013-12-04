/**
 * @brief Get/set functions definition
 * @file ihmperspective.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmperspective.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMPerspective::version_get(void) const
{
	stringstream out;

	int major = kCIHMPerspective_VERSION_MAJOR_NUMBER;
	int minor = kCIHMPerspective_VERSION_MINOR_NUMBER;
	int patch = kCIHMPerspective_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


