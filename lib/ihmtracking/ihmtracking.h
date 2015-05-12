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
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>

#include "misblob.h"


#define kCIHMTracking_VERSION_MAJOR_NUMBER	(0)
#define kCIHMTracking_VERSION_MINOR_NUMBER	(1)
#define kCIHMTracking_VERSION_PATCH_NUMBER	(0)

#define kCIHMTracking_LIB_DEBUG_NAME		"[MISTRACKING]: "


#define kCIHMTracking_MINIMUM_SIZE		(1.5f)	/** [%] */
#define kCIHMTracking_MAXIMUM_DISTANCE		(100)	/** [pixel], 100 better then 50 */
#define kCIHMTracking_DELTA_FRAME_IN_RANGE_MAX	(20)	// 20 better then 10

//#define kCIHMTracking_BORDER_MARGIN_MIN		(50)	/** not enough */
#define kCIHMTracking_BORDER_MARGIN_MIN		(60)	/** min distance from image border [px] */


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
//	bool overlapping_set(bool value);
//	bool is_overlapping(void) const;

	int check(const Mat& img, int frameCount, const Mat& fgClean, const Mat& fgColor,
		CMISBlob& currentList);

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMTracking& tracking);

	// Operator
	friend bool operator==(const Rect& lRect, const Rect& rRect);
	friend bool operator!=(const Rect& lRect, const Rect& rRect);

private:
	/*
	 * PRIVATE vatiables
	 */
	float minSize_;		/** Blob minimum size, default=1.0, [%] */
	int   maxDistance_;	/** Blob maximum distance between two frame, default=100, [pixel] */
//	bool  overLapEnable_;	/** Overlapping detection and tracking enable */

//	bool blobsOverlap_;	/** Blobs are overlapping */
//	int  overlapId1_;	/** Blobs overlapping id */
//	int  overlapId2_;	/** Blobs overlapping id */
//	bool incMaxDistance_;	/** After overlapping, need to increase maxDistance */

	/*
	 * PRIVATE Functions
	 */
	// misblobdetect_compute.cpp
	Rect Rect_delta(Rect r1, Rect r2);
	Point Rect_center(Rect roi);
	Rect Rect_set(Point p1, Point p2);
	string Rect_print(Rect roi);
	Rect Rect_average(Rect r1, Rect r2);
	bool compute_direction_vector(const Mat& img, int frameCount,
		const CMISBlob::BlobObject& obj, Rect& vect);
	bool Rect_limit(int cols, int rows, int margin, Rect& r1);

	// misblobdetect_check.cpp
	bool detect_position_in_range(int frameNumber, CMISBlob::BlobData lastData,
		Rect currentPos, int maxDistance);

	// misblobdetect_overlapping.cpp
//	bool overlapping_enter(int frameCount, CMISBlob& currentList, int validContour);
//	bool overlapping_exit(CMISBlob& currentList, const Mat& img, int validContour,
//		const Mat& fgClean, const Mat&fgColor, int& updateBlob);
//	bool estimate_position_draw(Mat& img, const CMISBlob& currentList);


}; // CIHMTracking

#endif // _IHM_TRACKING_H_

