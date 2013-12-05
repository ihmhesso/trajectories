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

	pParam->isRunning = true;
	cout << "[CIHMCapture]: THREAD is ALIVE!" << endl;

	if ((pParam->inputType == kType_USB_Device) ||
		(pParam->inputType == kType_Ethernet_Stream))
		pParam->mode = kMode_Play;

	// Loop
	do
	{
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
		usleep(1);

	} while (!pParam->terminateThread);

	// Therminate thread
	pParam->terminateThread = false;
	pParam->isRunning = false;

	cout << "[CIHMCapture]: THREAD is DEAD!" << endl;
	return 0; 
} // thread_core

