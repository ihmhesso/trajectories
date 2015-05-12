/**
 * @brief Bezier test header file
 * 	Main test application to draw a Bezier curve. A number of random points can be added
 * 	to draw a Bezier curve. The number of points of the Bezier curve can be set.
 * @file bezier_test.h
 * @author rodolfo.horta@master.hes-so.ch
 * @author christopher.metrailler@master.hes-so.ch
 * @date 26 December 2013
 */
#ifndef _BEZIERTEST_H_
#define _BEZIERTEST_H_

#include <iostream>
#include <ostream>
#include <vector>

// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

/** Application name */
#define APP_NAME "Bezier_Curve_Test"


/**
 * Bezier curve generation structure
 */
typedef struct _BezierTestApp
{

	// List of points to draw
	vector<Point> fixedPoints;
	vector<Point> bezierPoints;

	int cols;
	int rows; // Window size

} BezierTestApp, *pBezierTestApp;


/*
 * Functions prototype
 */
// BesierTest.cpp
void InitRandomPoints(pBezierTestApp app, int nbrOfPoints, Mat *img);
void AddRandomPoint(pBezierTestApp app);
bool CheckPointClicked(pBezierTestApp app, Point coord, int *pointNumber);
bool MovePoint(pBezierTestApp app, Point newCoord, unsigned int pointIndex);

// MouseCallback.cpp
void mouse_callback(int event, int x, int y, int flags, void* param);
bool ClickedPoint(void);

// Plot.cpp
bool PlotPoints(vector<Point> *points, Mat img, int radius = 5, Scalar color = Scalar(255, 0, 0));
bool PlotPoint(Point point, Mat img, int radius = 5, Scalar color = Scalar(255, 0, 0));


#endif // _BEZIERTEST_H_
