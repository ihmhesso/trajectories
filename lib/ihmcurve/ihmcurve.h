/**
 * @brief	CIHMCurve class header file
 * 			Bezier curve algorithm. The number of points for the Bezier curve
 * 			can be set. Algorithm info here: http://en.wikipedia.org/wiki/B%C3%A9zier_curve
 * @file	ihmcurve.h
 *
 * @version	1.0
 * @date	26 December 2013
 * @author	Rodolfo Horta (rodolfo.horta@master.hes-so.ch)
 * @author	Christopher Métrailler (christopher.metrailler@master.hes-so.ch)
 */
#ifndef _IHM_CURVE_H_
#define _IHM_CURVE_H_

#include <iostream>
#include <ostream>

// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

// Version 1.0.0, December 2013

/** Major number */
#define kCIHMCurve_VERSION_MAJOR_NUMBER	(1)
/** Minor number */
#define kCIHMCurve_VERSION_MINOR_NUMBER	(0)
/** Patch number */
#define kCIHMCurve_VERSION_PATCH_NUMBER	(0)

/**
 * CIHMCurve Class 
 */
class CIHMCurve
{
public:
	// Constructor/destructor
	CIHMCurve(void);
	~CIHMCurve(void);


	// List of Bezier Points
	void curveGenerator(vector<Point> *fixedPoints, Point *curvePoints, int nbrBezierPoints);

	// Get/set
	string version_get(void) const;

	// Debug
	friend ostream& operator<<(ostream& out, const CIHMCurve& curve);

private:

	// Bezier algorithme for 1 Point generation
	Point pointGenerator(vector<Point> *bezierPoints, float step);

}; // CIHMCurve


#endif // _IHM_CURVE_H_
