/**
 * @brief Thread function definition
 * @file ihmcapture_thread.cpp
 * @author samoa.schor@heig-vd.ch
 * @date November 2013
 */


#include "ihmcapture.h"


/** 
 * Thread core
 * @param pData OUT
 */
void* CIHMCapture::thread_core(void* pData)
{ 
	// Init
	pCaptureParam pParam = (pCaptureParam)pData;
	double tNow = 0;
	double tRef = 0;
	double frameTime = 1.0/(double)kCIHMCapture_DEFAULT_FRAME_RATE;	// [second] */

	pParam->isRunning = true;
	cout << "[CIHMCapture]: THREAD is ALIVE!" << endl;

	if ((pParam->inputType == kType_USB_Device) ||
		(pParam->inputType == kType_Ethernet_Stream))
		pParam->mode = kMode_Play;

	// If video file, update frameRate, display first image, and stop
	if (pParam->inputType == kType_Video_File)
	{
		// Update frameRate and frameTime
		pParam->frameRate = pParam->capture.get(CAP_PROP_FPS);
		if (pParam->frameRate < 1.0)
			pParam->frameRate = kCIHMCapture_DEFAULT_FRAME_RATE;
			
		frameTime = 1.0/(double)pParam->frameRate;
//DEBUG:
		cout << "[CIHMCapture]: frameRate: " << pParam->frameRate;
		cout << " [fps], frameTime: " << frameTime*1000 << " [ms]" << endl;

		// Display first image of file
		pParam->capture.grab();
		pParam->capture.retrieve(pParam->img);
		pParam->frameCount++;

		if (pParam->pCallback)
		{
			pParam->pCallback(pParam->img, pParam->frameCount, pParam->pUserData);
		}
	}

	// Clock start ticking
	tNow = (double)getTickCount()/(double)getTickFrequency();
	tRef = tNow;

	// Loop
	do
	{

		// Get current time
		tNow = (double)getTickCount()/(double)getTickFrequency();

		// Compute elapsed time since tRef [ms]
		double delta = (tNow-tRef)*1000.0;

//DEBUG
//		cout << "tNow = " << tNow << ", tRef = " << tRef << ", delta = " << delta << endl;

		// Is it time to do something
		if (delta >= frameTime*1000.0)
		{
			// Update tRef
			tRef += frameTime;

			switch (pParam->mode)
			{
			case kMode_Play:
				pParam->capture.grab();
				pParam->capture.retrieve(pParam->img);
				pParam->frameCount++;

				if (pParam->pCallback)
				{
					pParam->pCallback(pParam->img, pParam->frameCount, pParam->pUserData);
				}
				break;
			default:
			case kMode_Stop:
				//Do Nothing
				break;
			}
		}
		usleep(1);

	} while (!pParam->terminateThread);

	// Therminate thread
	pParam->terminateThread = false;
	pParam->isRunning = false;

	cout << "[CIHMCapture]: THREAD is DEAD!" << endl;
	return 0; 
} // thread_core

