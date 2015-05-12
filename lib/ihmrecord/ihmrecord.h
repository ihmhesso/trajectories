/**
 * @brief Class header file
 * @file ihmrecord.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_RECORD_H_
#define _IHM_RECORD_H_

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#define kCIHMRecord_VERSION_MAJOR_NUMBER	(0)
#define kCIHMRecord_VERSION_MINOR_NUMBER	(1)
#define kCIHMRecord_VERSION_PATCH_NUMBER	(0)


#define kCIHMRecord_CODEC_DEFAULT	(CV_FOURCC('X','V','I','D'))


using namespace std;
using namespace cv;


/**
 * CIHMRecord Class 
 */
class CIHMRecord
{
public:
	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMRecord(void);
	~CIHMRecord(void);

	// Get/set
	string version_get(void) const;
//	float frameRate_get(void) const;
//	bool  frameRate_set(float frameRate);
//	int   frameCount_get(void) const;

	// Action
//	bool open(const string& filename, int fourcc, double fps, Size frameSize);
//	bool is_open(void) const;
//	bool write(const Mat& img);

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMRecord& rec);

private:
	/*
	 * PRIVATE Objects
	 */
	VideoWriter record_;


}; // CIHMRecord


#endif // _IHM_RECORD_H_
