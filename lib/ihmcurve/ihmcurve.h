/**
 * @brief Class header file
 * @file ihmcurve.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_CURVE_H_
#define _IHM_CURVE_H_

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#define kCIHMCurve_VERSION_MAJOR_NUMBER	(0)
#define kCIHMCurve_VERSION_MINOR_NUMBER	(1)
#define kCIHMCurve_VERSION_PATCH_NUMBER	(0)



using namespace std;
using namespace cv;


/**
 * CIHMCurve Class 
 */
class CIHMCurve
{
public:
	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMCurve(void);
	~CIHMCurve(void);

	// Get/set
	string version_get(void) const;

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMCurve& curve);

private:
	/*
	 * PRIVATE Objects
	 */


}; // CIHMCurve


#endif // _IHM_CURVE_H_
