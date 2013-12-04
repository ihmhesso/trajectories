/**
 * @brief Class header file
 * @file ihmbackground.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_BACKGROUND_H_
#define _IHM_BACKGROUND_H_

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>


#define kCIHMBackground_VERSION_MAJOR_NUMBER	(0)
#define kCIHMBackground_VERSION_MINOR_NUMBER	(1)
#define kCIHMBackground_VERSION_PATCH_NUMBER	(0)


using namespace std;
using namespace cv;


/**
 * CIHMBackground Class 
 */
class CIHMBackground
{
public:
	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMBackground(void);
	~CIHMBackground(void);

	// Get/set
	string version_get(void) const;


	// Debug
	friend ostream& operator<<(ostream& out, const CIHMBackground& bg);

private:
	/*
	 * PRIVATE Objects
	 */
	

}; // CIHMBackground


#endif // _IHM_BACKGROUND_H_
