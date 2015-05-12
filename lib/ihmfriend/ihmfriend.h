/**
 * @brief Class header file
 * @file ihmfriend.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_FRIEND_H_
#define _IHM_FRIEND_H_

#include <iostream>
#include <sstream>
#include <stdio.h>	// sprintf()
#include <math.h>
#include <sys/time.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#define kCIHMFriend_VERSION_MAJOR_NUMBER	(0)
#define kCIHMFriend_VERSION_MINOR_NUMBER	(1)
#define kCIHMFriend_VERSION_PATCH_NUMBER	(0)


using namespace std;
using namespace cv;


/**
 * CIHMFriend Class 
 */
class CIHMFriend
{
public:
	typedef enum _EFriend_Mode
	{
		kMode_Idle = 0,
		kMode_Walking,
		//...
		kMode_MAX	/** MUST BE LAST */
	} EFriend_Mode;


	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMFriend(void);
	~CIHMFriend(void);

	// Get/set
	string version_get(void) const;
	void draw_friend(Mat& image, const Point& currentPos);


	CIHMFriend::EFriend_Mode mode_get(void) const;
	bool  mode_set(EFriend_Mode newMode);

	// Action

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMFriend& fr);

private:
	typedef struct _CIHMFriendData
	{
		EFriend_Mode mode;
		Point pos;
		Point waypoint;
		float angle;
		float speed;
		int radius;
		bool onRadius;
		struct timeval lastTime;
	} CIHMFriendData, *pCIHMFriendData;

	/*
	 * PRIVATE Objects
	 */
	CIHMFriendData data;

	/*
	 * PRIVATE Functions
	 */
	void overlay_image(const Mat& background, const Mat& foreground,
	  Mat& output, Point2i location);
	void rotate(Mat& src, double angle, Mat& dst);
	float angle_get(Point from, Point to);
	void image_filename_get(char *filename);
	int  difftime_get(void);
	void navigate(int deltat);
	void turn(int deltat, Point currentPos);

}; // CIHMFriend


#endif // _IHM_FRIEND_H_
