/**
 * @brief Class header file
 * @file ihmfootprint.h
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

#include <mispath.h>

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
//	bool footPrint_get(Mat& img);
//	bool footPrint_set(string imgName);
//	Size size_get(void);
//	bool size_set(Size size);
//	bool path_set(const vector<CMISPath::PathData>& path);

	// Draw
//	bool draw(const Mat& src, Mat& out);

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMFootprint& footprint);

private:
	/*
	 * PRIVATE Objects
	 */
	Mat footPrint1_;	/** Single print (one foot) */
	Mat footPrint2_;	/** Full print (both feet) */
	Size size_;		/** Size of the footprint */
	vector<CMISPath::PathData> path_;	/** Path to draw using footprints */

}; // CIHMFootprint


#endif // _IHM_FOOTPRINT_H_
