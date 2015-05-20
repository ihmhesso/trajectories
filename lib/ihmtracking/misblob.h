/**
 * @brief Class header
 * @file misblob.h
 * @author gregory.medwed@heig-vd.ch
 * @date Dec 2013
 */
#ifndef _MIS_BLOB_H_
#define _MIS_BLOB_H_


#include <sstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <syslog.h>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>


using namespace std;
using namespace cv;


// Version
#define kMISBLOB_VERSION_MAJOR_NUMBER		(0)
#define kMISBLOB_VERSION_MINOR_NUMBER		(1)
#define kMISBLOB_VERSION_PATCH_NUMBER		(0)

#define kMISBLOB_LIB_DEBUG_NAME			"[IHMBLOB]: "

#define kMISBLOB_COUNT_MAX			(20)
#define kMISBLOB_FLOOR_CONTACT_POINT_DEFAULT	(0.8f)	/** 80 % of blob height */



/**
 * CMISBlob class definition
 * This class handles blob objects
 */
class CMISBlob
{
public:
	/**
	 * Blob Data structure
	 */
	typedef struct _BlobData
	{
		int frameNumber;	/** frame number */
		Rect roi;		/** Region Of Interest, blob position and size */
	} BlobData, *pBlobData;

	/**
	 * Blob Object structure
	 */
	typedef struct _BlobObject
	{
		int actorId;	/** Actor ID, default = -1, not assigned */
		vector<BlobData> data;
//		Mat shapeImg;	/** Normalized ~200x200, 8-bit B/W blob shape */
//		Mat colorImg;	/** Normalized ~200x200, 8-bit RGB blob color */
	} BlobObject, *pBlobObject;

	/*
	 * PUBLIC Variables
	 */
	vector<BlobObject> blobsList;

	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CMISBlob(void);
	~CMISBlob(void);

	// Get/Set Functions
	string version_get(void);
	string count_get(int& count, int& maxCount);
	bool   data_set(BlobData& data, int frameNumber, const Rect& roi);
	Point  floor_contact_get(const BlobData& data);

	bool add(int frameCount, Rect blobRect, const Mat& fgClean, const Mat& fgColor, int& newId);
	bool remove(int id);
	bool remove_all(void);
	bool update(BlobObject& blob, int frameCount, Rect& roi, const Mat& fgClean, const Mat& fgColor);

	// Draw Functions
	bool box(Mat& img, int id, Scalar color);

	// Debug
	friend ostream& operator<<(ostream& out, const Rect& roi);
	friend ostream& operator<<(ostream& out, const BlobData& data);
	friend ostream& operator<<(ostream& out, const BlobObject& object);
	friend ostream& operator<<(ostream& out, const vector<BlobObject>& objList);
	friend ostream& operator<<(ostream& out, const CMISBlob& blob);

private:
	/*
	 * PRIVATE Variables
	 */
	int maxCount_;		/** Total blobs found (may be different then current blob count) */
	float floorPOC_;	/** Set blob point of contact with the floor [%] */

	/*
	 * PRIVATE Functions
	 */
//	bool extract_blob_image(const Mat& fgImg, Rect& roi, Mat& blobImg);
}; // CMISBlob

#endif // _MIS_BLOB_H_

