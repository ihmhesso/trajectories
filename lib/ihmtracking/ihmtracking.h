/**
 * @brief Class header file
 * @file ihmtracking.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_TRACKING_H_
#define _IHM_TRACKING_H_

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#define kCIHMTracking_VERSION_MAJOR_NUMBER	(0)
#define kCIHMTracking_VERSION_MINOR_NUMBER	(1)
#define kCIHMTracking_VERSION_PATCH_NUMBER	(0)


using namespace std;
using namespace cv;


/**
 * CIHMTracking Class 
 */
class CIHMTracking
{
public:
	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMTracking(void);
	~CIHMTracking(void);

	// Get/set
	string version_get(void) const;

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMTracking& track);

private:
	/*
	 * PRIVATE Objects
	 */

}; // CIHMTracking


#endif // _IHM_TRACKING_H_
