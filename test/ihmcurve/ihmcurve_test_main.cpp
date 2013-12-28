/**
 * @brief	Main application file
 * 			Bezier application test using OpenCV.
 * 			MSE IHM, December 2013
 * @file	Main.cpp
 *
 * @version	1.0
 * @date	26 December 2013
 * @author	Rodolfo Horta (rodolfo.horta@master.hes-so.ch)
 * @author	Christopher Métrailler (christopher.metrailler@master.hes-so.ch)
 */
#include <ihmcurve.h>

#include "BezierTest.h"
#include "MouseCallback.h"
#include "Plot.h"

// Application settings :
#define NUMBER_OF_FIXED_POINTS 		4		// Fixed points to modify the curve (>= 2)
#define BEZIER_CURVE_NBR_OF_PTS 	1000	// Number of points for the Bezier curve (> 1)

/**
 * Main function
 */
int main() {

	// Check input parameters range
	// TODO: Set these parameters with arguments
	if (NUMBER_OF_FIXED_POINTS < 2) {
		cout << "ERROR: The number of fixed points must be >= 2 !" << endl;
		return -1;
	} else if (BEZIER_CURVE_NBR_OF_PTS < 1) {
		cout << "ERROR: The number of Bezier points must be > 0 !" << endl;
		return -1;
	}

	// Bezier test application
	BezierTestApp app;

	Mat img(600, 800, CV_8UC3, Scalar(0, 200, 255));
	namedWindow(APP_NAME);

	setMouseCallback(APP_NAME, mouse_callback, &app);

	// Add some random points on the window to draw a Bezier curve
	InitRandomPoints(&app, NUMBER_OF_FIXED_POINTS, &img);

	CIHMCurve bezier;
	Point curvePts[1000]; // Bezier curve points
	bezier.curveGenerator(&app.fixedPoints, &curvePts[0], BEZIER_CURVE_NBR_OF_PTS);

	cout << "\"" << APP_NAME << "\"" << " MSE IHM, December 2013" << endl;
	cout << "Rodolfo Horta & Christopher Métrailler" << endl << endl;
	cout << "Press on any point and move it to update the Bezier curve." << endl;
	cout << " - The start point is in blue." << endl;
	cout << " - The end point is in green." << endl;
	cout << "Press 'a' to add a new point." << endl;
	cout << "Press 'Esc' key to exit the application." << endl;

	/*
	 * Main program loop
	 */
	short ch = 0;
	bool bezierUpdate = true;
	do {
		// Clear image
		img = Mat::zeros(img.rows, img.cols, CV_8UC3);
		img = Scalar(0, 200, 255);

		// A point has been moved
		if(ClickedPoint())
			bezierUpdate = true;

		// Add a new random point and update the Bezier curve
		if(ch == 'a') {
			AddRandomPoint(&app);	// Update the end point
			bezierUpdate = true;
		}

		// Update the Bezier curve only if necessary
		if(bezierUpdate) {
			bezierUpdate = false;
			bezier.curveGenerator(&app.fixedPoints, &curvePts[0], BEZIER_CURVE_NBR_OF_PTS);
		}

		// Draw Bezier curve points in black
		for (int i = 0; i < BEZIER_CURVE_NBR_OF_PTS; i++)
			PlotPoint(curvePts[i], img, 2, Scalar(0, 0, 0));

		// Draw all fixed points, start and end points with a different appearance
		PlotPoints(&app.fixedPoints, img, 5, Scalar(0, 0, 255));
		PlotPoint(app.fixedPoints.front(), img, 8, Scalar(255, 0, 0)); // Start point
		PlotPoint(app.fixedPoints.back(), img, 8, Scalar(0, 255, 0)); // End point

		// Display image
		imshow(APP_NAME, img);

		ch = waitKey(20);

	} while (ch != 27);	// 'Esc'

	// Free resources
	destroyAllWindows();

	return (0);

} // main
