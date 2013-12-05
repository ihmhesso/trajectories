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
	string videoName;
	string ipAddr;
	int devId;
	CIHMCapture capture;

	Mat src;
	bool newFrame;

	string winName;

	bool exitProgram;
} ApplicationParam, *pApplicationParam;


/*
 * Function prototypes
 */
// ihmcapture_test_args.cpp
void help_print(void);
bool args_check(int argc, char* argv[], ApplicationParam& app);




#endif // _IHM_CAPTURE_TEST_H_

