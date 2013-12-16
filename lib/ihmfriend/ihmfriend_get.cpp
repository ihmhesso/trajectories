/**
 * @brief Get/set functions definition
 * @file ihmfriend_get.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmfriend.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMFriend::version_get(void) const
{
	stringstream out;

	int major = kCIHMFriend_VERSION_MAJOR_NUMBER;
	int minor = kCIHMFriend_VERSION_MINOR_NUMBER;
	int patch = kCIHMFriend_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


