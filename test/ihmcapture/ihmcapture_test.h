/**
 * @brief Program header
 * @file ihmcapture_test.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_CAPTURE_TEST_H_
#define _IHM_CAPTURE_TEST_H_


#include <ihmcapture.h>


/*
 * Application parameters structure
 */
typedef struct _ApplicationParam
{
	string fileName;
	int devId;

	Mat src;
	bool newFrame;

	string winName;

	bool exitProgram;
} ApplicationParam, *pApplicationParam;






#endif // _IHM_CAPTURE_TEST_H_

