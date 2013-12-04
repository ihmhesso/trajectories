/**
 * @brief Class header file
 * @file ihmrecord.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_FOOTPRINT_H_
#define _IHM_FOOTPRINT_H_

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#define kCIHMFootprint_VERSION_MAJOR_NUMBER	(0)
#define kCIHMFootprint_VERSION_MINOR_NUMBER	(1)
#define kCIHMFootprint_VERSION_PATCH_NUMBER	(0)


using namespace std;
using namespace cv;


/**
 * CIHMFootprint Class 
 */
class CIHMFootprint
{
public:
	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMFootprint(void);
	~CIHMFootprint(void);

	// Get/set
	string version_get(void) const;

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMFootprint& footPrint);

private:
	/*
	 * PRIVATE Objects
	 */
	Mat src_;

}; // CIHMFootprint


#endif // _IHM_FOOTPRINT_H_
