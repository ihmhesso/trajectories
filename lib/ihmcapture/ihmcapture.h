/**
 * @brief Class header file
 * @file ihmcapture.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_CAPTURE_H_
#define _IHM_CAPTURE_H_

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#define kCIHMCapture_VERSION_MAJOR_NUMBER	(0)
#define kCIHMCapture_VERSION_MINOR_NUMBER	(1)
#define kCIHMCapture_VERSION_PATCH_NUMBER	(0)


using namespace std;
using namespace cv;


/**
 * CIHMCapture Class 
 */
class CIHMCapture
{
public:
	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMCapture(void);
	~CIHMCapture(void);

	// Get/set
	string version_get(void) const;


	// Debug
	friend ostream& operator<<(ostream& out, const CIHMCapture& cap);

private:
	/*
	 * PRIVATE Objects
	 */
	VideoCapture capture_;

}; // CIHMCapture


#endif // _IHM_CAPTURE_H_
