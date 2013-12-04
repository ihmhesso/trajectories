/**
 * @brief Class header file
 * @file ihmperspective.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_PERSPECTIVE_H_
#define _IHM_PERSPECTIVE_H_

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#define kCIHMPerspective_VERSION_MAJOR_NUMBER	(0)
#define kCIHMPerspective_VERSION_MINOR_NUMBER	(1)
#define kCIHMPerspective_VERSION_PATCH_NUMBER	(0)


using namespace std;
using namespace cv;


/**
 * CIHMPerspective Class 
 */
class CIHMPerspective
{
public:
	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMPerspective(int coordCount=4);
	~CIHMPerspective(void);

	// Get/set
	string version_get(void) const;
//	bool src_point_set(int index, Point2f p);
//	bool dst_point_set(int index, Point2f p);
//	bool src_points_set(Point2f srcPoints[]);
//	bool dst_points_set(Point2f dstPoints[]);

//	bool perspective_matrice_get(Mat& persp);
//	bool perspective_matrice_set(const Mat& persp);
//	bool perspective_inv_matrice_get(Mat& perspInv);
//	bool perspective_inv_matrice_set(const Mat& perspInv);
	
//	bool warp(const Mat& src, Mat& out, Size sizeOut, bool inverse=false);

	// Draw
//	bool srcPoints_draw(Mat& img, Scalar color, int radius);
//	bool square_draw(Mat& img, Scalar color, int nbSquare);

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMPerspective& persp);

private:
	/*
	 * PRIVATE Objects
	 */
	int coordCount_;
	Point2f srcPoints_[4];
	Point2f dstPoints_[4];
	Mat persp_;
	Mat perspInv_;
	bool perspMartixCompute_;
	bool perspInvMartixCompute_;
	

}; // CIHMPerspective


#endif // _IHM_PERSPECTIVE_H_
