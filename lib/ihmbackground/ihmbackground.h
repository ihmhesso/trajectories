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
 * Background Substraction parameters structure
 */
typedef struct _Mog2Param
{
	int mixtures;		/** Maximum allowed number of mixture components.
				Actual number is determined dynamically per pixel. */
	float bgRatio;		/** Threshold defining whether the component is significant
				enough to be included into the background model */
	float varThreshold;	/** Threshold for the squared Mahalanobis distance that helps
				decide when a sample is close to the existing components */
	float varInit;		/** Initial variance for the newly generated components.
				It affects the speed of adaptation. */
	float varMin;		/** Parameter used to further control the variance. */
	float varMax;		/** Parameter used to further control the variance. */
	float ct;		/** Complexity reduction parameter. This parameter defines
				the number of samples needed to accept to prove the component exists. */
	unsigned char shadowValue; /** The value for marking shadow pixels in the output foreground mask.
				Default value is 127. */
	float shadowThreshold;	/** Shadow threshold. The shadow is detected if the pixel is
				a darker version of the background. */
	bool shadowEnable;	/*  Parameter defining whether shadow detection should be enabled. */
} Mog2Param, *pMog2Param;


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
//	void param_get(Mog2Param& param);
//	bool param_set(const Mog2Param& param);
//	bool img_get(Mat& bgImg);

	// Background/foreground detection
//	bool sub(const Mat& src, Mat& bgImg);

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMBackground& bg);
	void Mog2Param_print(const Mog2Param& param);

private:
	/*
	 * PRIVATE Objects
	 */
	BackgroundSubtractorMOG2 bg_;
	bool paramChanged_;

}; // CIHMBackground


#endif // _IHM_BACKGROUND_H_
