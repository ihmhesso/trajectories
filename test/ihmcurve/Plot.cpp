#include "Plot.h"

/**
 * This function draws a filled circle for each points of a given list.
 *
 * @param points IN	list of points to plot
 * @param img IN matrice where the function plots
 * @param radius IN	radius of the filled circle
 * @param color IN	color of the circle
 * @return true if successful, false if img is empty
 */
bool PlotPoints(vector<Point> *points, Mat img, int radius, Scalar color) {
	if (img.empty())
		return false;	// Image cannot be empty

	// Draw a filled circle for each points
	for (vector<Point>::iterator it = points->begin(); it != points->end(); ++it)
		PlotPoint(*it, img, radius, color);
	return true;
}

bool PlotPoint(Point point, Mat img, int radius, Scalar color) {
	if (img.empty())
			return false;	// Image cannot be empty

	circle(img, point, radius, color, CV_FILLED);
	return true;
}

