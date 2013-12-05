/**
 * @brief Class header file
 * @file ihmcapture.h
 * @author samoa.schor@heig-vd.ch
 * @date Dec 2013
 */
#ifndef _IHM_CAPTURE_H_
#define _IHM_CAPTURE_H_

#include <iostream>
#include <sstream>
#include <unistd.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#define kCIHMCapture_VERSION_MAJOR_NUMBER	(0)
#define kCIHMCapture_VERSION_MINOR_NUMBER	(1)
#define kCIHMCapture_VERSION_PATCH_NUMBER	(0)

#define kCIHMCapture_DEFAULT_FRAME_RATE		(30) /** [fps] */


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


/**
 * Callback function prototype (call everytime a new image is available)
 * @param img IN new image
 * @param frameCount IN actual frame count
 * @param pUserData OUT can be used to pass additionnal data
 */
typedef void (*CIHMCaptureCallback)(const Mat& img, int frameCount, void* pUserData);


/**
 * CIHMCapture Class 
 */
class CIHMCapture
{
public:
	/*
	 * "Playback" mode
	 */
	typedef enum _ECapture_Mode
	{
		kMode_Stop = 0,
		kMode_Play,
//		kMode_Step_Forward,
//		kMode_Step_Backward,
		kMode_MAX		/** MUST be last */
	} ECapture_Mode;

	/*
	 * Input "type"
	 */
	typedef enum _ECapture_Type
	{
		kType_Unknown = 0,
		kType_USB_Device,
		kType_Video_File,
		kType_Ethernet_Stream,
		kType_MAX		/** MUST be last */
	} ECapture_Type;

	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMCapture(void);
//	CIHMCapture(string videoName);
//	CIHMCapture(int deviceId);
	~CIHMCapture(void);

	// Get/set
	string version_get(void) const;
	bool   is_open(void);
	bool   callback_set(CIHMCaptureCallback pFunction, void* pData);
	ECapture_Type type_get(void);
	bool   type_set(ECapture_Type newType);
	ECapture_Mode mode_get(void);
	bool   mode_set(ECapture_Mode mode);
	bool   img_get(Mat& img, int frameCount);
//	double property_get(int propId);
//	bool   property_set(int propId, double value);

	// Action
	bool open(const string& videoName);
	bool open(int cameraId);
	bool close(void);
	
	// Debug
	friend ostream& operator<<(ostream& out, const CIHMCapture& cap);
	friend ostream& operator<<(ostream& out, const CIHMCapture::ECapture_Mode& mode);

private:
	/*
	 * Capture parameters structure
	 */
	typedef struct _CaptureParam
	{
		VideoCapture capture;
		Mat img;
		ECapture_Type inputType;
		ECapture_Mode mode;
		int frameCount;
		double frameRate;	/** [fps] */

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
	static void* thread_core(void* pData);
	void CaptureParam_init(CaptureParam& param);

}; // CIHMCapture


#endif // _IHM_CAPTURE_H_
