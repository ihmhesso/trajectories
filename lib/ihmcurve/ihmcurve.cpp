#include "ihmcurve.h"

/**
 * Constructor
 */
CIHMCurve::CIHMCurve(void)
{
	// Not used...
}


/**
 * Generates a number of points that correspond to a Bezier curve.
 *
 * @param fixedPoints IN list of fixed points of the curve
 * @param curvePoints OUT Bezier curve points
 * @param nbrBezierPoints IN Number of Bezier points to generate
 */
void CIHMCurve::curveGenerator(vector<Point> *fixedPoints, Point *curvePoints, int nbrBezierPoints) {
	float step = 0.0;

	// Do it for all Bezier points (typically 1000 points)
	for(int idx = 0; idx < nbrBezierPoints; idx ++) {
		curvePoints[idx] = pointGenerator(fixedPoints, step);
		step = float(step + 1.0f / float(nbrBezierPoints));
	}
}

/**
 * Bezier Curve algorithm.
 *
 * @param bezierPoints IN list of fixed points
 * @param step IN step of Bezier algorithm
 */
Point CIHMCurve::pointGenerator(vector<Point> *bezierPoints, float step) {
	if (bezierPoints->size() == 1) {
		return bezierPoints->at(0);	// End
	} else {
		vector<Point> temp;
		unsigned int j = 0;
		while (j < (bezierPoints->size() - 1)) {
			// Calculate point coordinates
			int ptX = (int) ((1.0 - step) * bezierPoints->at(j).x + step * bezierPoints->at(j + 1).x);
			int ptY = (int) ((1.0 - step) * bezierPoints->at(j).y + step * bezierPoints->at(j + 1).y);
			temp.push_back(Point(ptX, ptY));
			j++;
		}
		// Recursive algorithm
		return pointGenerator(&temp, step);
	}
}

/**
 * Destructor
 */
CIHMCurve::~CIHMCurve(void)
{
	// Not used...
}

