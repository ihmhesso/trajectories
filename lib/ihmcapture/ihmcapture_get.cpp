/**
 * @brief Get/set functions definition
 * @file ihmcapture.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmcapture.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMCapture::version_get(void) const
{
	stringstream out;

	int major = kCIHMCapture_VERSION_MAJOR_NUMBER;
	int minor = kCIHMCapture_VERSION_MINOR_NUMBER;
	int patch = kCIHMCapture_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


