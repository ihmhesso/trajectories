/**
 * @brief Init function sdefinition
 * @file ihmcapture_init.cpp
 * @author gregory.medwed@geig-vd.ch
 * @date Dec. 2013
 */

#include "ihmcapture.h"


/**
 * Init CaptureParam structure
 * @param param OUT
 */
void CIHMCapture::CaptureParam_init(CaptureParam& param)
{
	param.inputType = kType_Unknown;
	param.mode = kMode_Stop;
	param.img = Mat::zeros(100, 100, CV_8UC3);
	param.frameCount = 0;

	param.hThread = 0;
	param.isRunning = false;
	param.terminateThread = false;
	param.pCallback = 0;
	param.pUserData = 0;
} // CaptureParam_init

