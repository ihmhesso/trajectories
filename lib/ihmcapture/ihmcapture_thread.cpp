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
	double frameTime = 1.0/(double)kCIHMCapture_DEFAULT_FRAME_RATE;

	pParam->isRunning = true;
	cout << "[CIHMCapture]: THREAD is ALIVE!" << endl;

	if ((pParam->inputType == kType_USB_Device) ||
		(pParam->inputType == kType_Ethernet_Stream))
		pParam->mode = kMode_Play;

	// If video file display first image and stop
	if (pParam->inputType == kType_Video_File)
	{
		pParam->capture.grab();
		pParam->capture.retrieve(pParam->img);
		pParam->frameCount++;

		if (pParam->pCallback)
		{
			pParam->pCallback(pParam->img, pParam->frameCount, pParam->pUserData);
		}
	}

	if (pParam->frameRate != 0)
		frameTime = 1.0/(double)pParam->frameRate;

	tNow = (double)getTickCount()/(double)getTickFrequency();
	tRef = tNow;



	// Loop
	do
	{

		tNow = (double)getTickCount()/(double)getTickFrequency();

		// Is it time to do something
		double delta = (tNow-tRef)*1000.0;

//DEBUG
//		cout << "tNow = " << tNow << ", tRef = " << tRef << ", delta = " << delta << endl;

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

