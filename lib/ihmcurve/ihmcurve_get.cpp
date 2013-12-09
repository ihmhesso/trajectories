/**
 * @brief Get/set functions definition
 * @file ihmcurve.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmcurve.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMCurve::version_get(void) const
{
	stringstream out;

	int major = kCIHMCurve_VERSION_MAJOR_NUMBER;
	int minor = kCIHMCurve_VERSION_MINOR_NUMBER;
	int patch = kCIHMCurve_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


