/**
 * @brief Application header file
 * @file trajectories.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _TRAJECTORIES_H_
#define _TRAJECTORIES_H_


#include <ihmbackground.h>
#include <ihmcapture.h>
#include <ihmfootprint.h>
#include <ihmperspective.h>
#include <ihmrecord.h>
#include <ihmtracking.h>
#include <ihmfootprint.h>
#include <mispath.h>


/**
 * Application Parameters structure
 */
typedef struct _ApplicationParam
{
	Mat src;

	CIHMCapture capture;
	CIHMPerspective persp;
	CIHMBackground bg;
	CIHMTracking track;
	CMISPath path;
	CIHMFootprint footPrint;
	CIHMRecord record;

	bool exitProgram;
} ApplicationParam, *pApplicationParam;


/*
 * Functions prototypes
 */



#endif // _TRAJECTORIES_H_

