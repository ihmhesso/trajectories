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


/*
 * Properties Parameters:	
 * CV_CAP_PROP_POS_MSEC		Current position of the video file in milliseconds or
 *				video capture timestamp.
 * CV_CAP_PROP_POS_FRAMES 	0-based index of the frame to be decoded/captured next.
 * CV_CAP_PROP_POS_AVI_RATIO 	Relative position of the video file: 0-start of the film,
 *				1-end of the film.
 * CV_CAP_PROP_FRAME_WIDTH	Width of the frames in the video stream.
 * CV_CAP_PROP_FRAME_HEIGHT	Height of the frames in the video stream.
 * CV_CAP_PROP_FPS		Frame rate.
 * CV_CAP_PROP_FOURCC		4-character code of codec.
 * CV_CAP_PROP_FRAME_COUNT	Number of frames in the video file.
 * CV_CAP_PROP_FORMAT		Format of the Mat objects returned by retrieve() .
 * CV_CAP_PROP_MODE		Backend-specific value indicating the current capture mode.
 * CV_CAP_PROP_BRIGHTNESS 	Brightness of the image (only for cameras).
 * CV_CAP_PROP_CONTRAST 	Contrast of the image (only for cameras).
 * CV_CAP_PROP_SATURATION 	Saturation of the image (only for cameras).
 * CV_CAP_PROP_HUE		Hue of the image (only for cameras).
 * CV_CAP_PROP_GAIN		Gain of the image (only for cameras).
 * CV_CAP_PROP_EXPOSURE		Exposure (only for cameras).
 * CV_CAP_PROP_CONVERT_RGB	Boolean flags indicating whether images should be converted to RGB.
 * CV_CAP_PROP_WHITE_BALANCE	Currently not supported
 * CV_CAP_PROP_RECTIFICATION	Rectification flag for stereo cameras
 *				(note: only supported by DC1394 v 2.x backend currently)
 */


/*
 * Callback function prototype
 */
typedef void (*CIHMCaptureCallback)(const Mat& img, int frameCount, void* pUserData);


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
//	CIHMCapture(string videoName);
//	CIHMCapture(int cameraId);
	~CIHMCapture(void);

	// Get/set
	string version_get(void) const;
//	bool open(string videoName);
//	bool open(int cameraId);
//	bool is_open(void);

//	double camera_prop_get(int propld);
//	bool camera_prop_set(int propld, double value);
	
//	bool callback_set(CIHMCaptureCallback pFunction, void* pData);

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMCapture& cap);

private:
	/*
	 * Capture parameters structure
	 */
	typedef struct _CaptureParam
	{
		VideoCapture capture;
		bool isOpen;
		Mat img;

		// Thread 
		pthread_t hThread;	/** Thread handle */
		bool isRunning;
		bool terminateThread;	/** command */

		// Callback
		CIHMCaptureCallback pCallback;
		void* pUserData;
	} CaptureParam, *pCaptureParam;

	/*
	 * PRIVATE Objects
	 */
	CaptureParam param_;

	/*
	 * PRIVATE Functions
	 */
//	static void* thread_core(void* pData);

}; // CIHMCapture


#endif // _IHM_CAPTURE_H_
