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
		kMode_MAX		/** MUST BE LAST */
	} EFriend_Mode;


	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMFriend(void);
	~CIHMFriend(void);

	// Get/set
	string version_get(void) const;
	void draw_friend(Mat &image,const Point &current_pos);


	CIHMFriend::EFriend_Mode   mode_get(void) const;
	bool  mode_set(EFriend_Mode newMode);

	// Action

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMFriend& fr);

private:

	void overlayImage(const cv::Mat &background, const cv::Mat &foreground,
	  cv::Mat &output, cv::Point2i location);
	void rotate(cv::Mat& src, double angle, cv::Mat& dst);
	float get_angle(Point from, Point to);
	void get_image_filename(char *filename);
	int get_difftime();
	void navigate(int deltat);
	void turn(int deltat,Point current_pos);
	/*
	 * PRIVATE Objects
	 */
	/*
	 * Programm data structure
	 */
	typedef struct _CIHMFriendData
	{
		EFriend_Mode mode;
		Point pos;
		Point waypoint;
		float angle;
		float speed;
		int radius;
		bool onradius;
		struct timeval last_time;
	} CIHMFriendData, *pCIHMFriendData;

	CIHMFriendData appdata;


}; // CIHMFriend


#endif // _IHM_FRIEND_H_
