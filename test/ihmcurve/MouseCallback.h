/**
 * @brief	MouseCallback header file
 * 			Mouse callback to get right click and mouse position.
 * @file	MouseCallback.h
 *
 * @version	1.0
 * @date	26 December 2013
 * @author	Rodolfo Horta (rodolfo.horta@master.hes-so.ch)
 * @author	Christopher Métrailler (christopher.metrailler@master.hes-so.ch)
 */
#ifndef _MOUSECALLBACK_H_
#define _MOUSECALLBACK_H_

#include <iostream>
#include <ostream>
#include <vector>

// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "BezierTest.h"

using namespace std;
using namespace cv;

// Mouse callback function
void mouse_callback(int event, int x, int y, int flags, void* param);

// Is a point clicked or not
bool ClickedPoint(void);

#endif //_MOUSECALLBACK_H_
