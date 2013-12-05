/**
 * @brief Get/set functions definition
 * @file ihmcapture_get.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date Dec 2013
 */


#include "ihmcapture.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMCapture::version_get(void) const
{
	stringstream out;

	int major = kCIHMCapture_VERSION_MAJOR_NUMBER;
	int minor = kCIHMCapture_VERSION_MINOR_NUMBER;
	int patch = kCIHMCapture_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


/**
 * Set callback function (call each time a new frame is ready)
 * @param pFunction IN
 * @param pData IN
 * @return true if succeed
 */
bool CIHMCapture::callback_set(CIHMCaptureCallback pFunction, void* pData)
{
	if (!pFunction)
		return(false);

	// pData could be NULL
	param_.pCallback = pFunction;
	param_.pUserData = pData;

	return(true);
} // callback_set


/**
 * Input type get
 * @return input type
 */
CIHMCapture::ECapture_Type CIHMCapture::type_get(void)
{
	return(param_.inputType);
}


/**
 * Get current "plaback" mode
 * @return current mode
 */
CIHMCapture::ECapture_Mode CIHMCapture::mode_get(void)
{
	return(param_.mode);
}


/**
 * Set "plaback" mode
 * @param newMode IN
 * @return true if succeed 
 */
bool CIHMCapture::mode_set(ECapture_Mode newMode)
{
	// Check parameter
	if (newMode >= kMode_MAX)
		return(false);

	param_.mode = newMode;
//DEBUG:
	cout << "[CIHMCapture]: " << param_.mode << endl;
	return(true);
} // mode_set


/**
 * Get curent image and frame count
 * @param img OUT
 * @param frameCount OUT
 * @return true if succeed
 */
bool CIHMCapture::img_get(Mat& img, int frameCount)
{
	param_.img.copyTo(img);
	frameCount = param_.frameCount;
	return(true);
}



