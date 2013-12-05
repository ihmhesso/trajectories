/**
 * @brief Get/set functions definition
 * @file ihmcapture_open.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date Dec 2013
 */


#include "ihmcapture.h"


/**
 * Open video file
 * @param videoName IN
 * @return true if succeed
 */
bool CIHMCapture::open(const string& videoName)
{
	//TODO: Detect and open Ethernet stream

	if (!param_.capture.open(videoName))
	{
		cout << "[CIHMCapture]: ERROR can't open video file!" << endl;
		return false;
	}
	
	// Create thread
	pthread_create(&param_.hThread, NULL, &CIHMCapture::thread_core, (void*)&param_);
	if (!param_.hThread)
	{
		cout << "[CIHMCapture]: ERROR can't create thrad!" << endl;
		return false;
	}


	param_.inputType = kType_Video_File;
	return(true);
} // open


/**
 * Open usd device
 * @param deviceId IN
 * @return true if succeed
 */
bool CIHMCapture::open(int deviceId)
{
	// Check parameter
	if (deviceId < 0)
	{
		cout << "[CIHMCapture]: ERROR invalid device id " << deviceId << endl;
		return(false);
	}

	// Try to open video device
	if (!param_.capture.open(deviceId))
	{
		cout << "[CIHMCapture]: ERROR can't open device " << deviceId << endl;
		return(false);
	}
	
	// Create thread
	pthread_create(&param_.hThread, NULL, &CIHMCapture::thread_core, (void*)&param_);
	if (!param_.hThread)
	{
		cout << "[CIHMCapture]: ERROR can't create thrad!" << endl;
		return(false);
	}

	param_.inputType = kType_USB_Device;
	return(true);
} // open


/**
 * Therminate thread
 * @return true when done
 */
bool CIHMCapture::close(void)
{
	// Check if thread is runing
	if (param_.isRunning)
	{
		// Ask thread to terminate
		param_.terminateThread = true;
		usleep(1);

		// Wait for thread to finish
		for (int i = 0; i < 1000; ++i)
		{
			if (!param_.isRunning)
			{
				param_.hThread = 0;
				break; // Exit for
			}
			usleep(1);
		}
	}

	return(true);
} // close

