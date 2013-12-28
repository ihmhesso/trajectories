/**
 * @brief	Plot header file
 * 			Used to plot a list of points on an image. Each points on the image are represented by a circle.
 * @file	Plot.h
 *
 * @version	1.0
 * @date	26 December 2013
 * @author	Rodolfo Horta (rodolfo.horta@master.hes-so.ch)
 * @author	Christopher Métrailler (christopher.metrailler@master.hes-so.ch)
 */
#ifndef _PLOT_H_
#define _PLOT_H_

#include <iostream>
#include <ostream>
#include <vector>

// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

// Draw each points of a given list
bool PlotPoints(vector<Point> *points, Mat img, int radius = 5, Scalar color = Scalar(255, 0, 0));

// Draw a single point
bool PlotPoint(Point point, Mat img, int radius = 5, Scalar color = Scalar(255, 0, 0));

#endif //_PLOT_H_
