/**
 * @brief	BezierTest header file
 * 			Main test application to draw a Bezier curve. A number of random points can be added
 * 			to draw a Bezier curve. The number of points of the Bezier curve can be set.
 * @file	BezierTest.h
 *
 * @version	1.0
 * @date	26 December 2013
 * @author	Rodolfo Horta (rodolfo.horta@master.hes-so.ch)
 * @author	Christopher Métrailler (christopher.metrailler@master.hes-so.ch)
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
typedef struct _BezierTestApp {

	// List of points to draw
	vector<Point> fixedPoints, bezierPoints;

	int cols, rows; // Window size

} BezierTestApp, *pBezierTestApp;

// Fill the points list with some random coordinates
void InitRandomPoints(pBezierTestApp app, int nbrOfPoints, Mat *img);

// Add a random point
void AddRandomPoint(pBezierTestApp app);

// Check if the click (x,y point) corresponds to the position of a point in the array
bool CheckPointClicked(pBezierTestApp app, Point coord, int *pointNumber);

// Move the position of a point
bool MovePoint(pBezierTestApp app, Point newCoord, unsigned int pointIndex);

#endif // _BEZIERTEST_H_
