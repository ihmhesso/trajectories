/**
 * @brief Compute functions used in check
 * @file ihmtracking_compute.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date Dec. 2013
 */


#include "ihmtracking.h"


/**
 * comparison operator ==
 * @param lRect
 * @param rRect
 * @return true/false
 */
bool operator==(const Rect& lRect, const Rect& rRect)
{
	return ((lRect.x == rRect.x) && (lRect.y == rRect.y) &&
		(lRect.width == rRect.width) && (lRect.height == rRect.height));
}


/**
 * comparison operator !=
 * @param lRect
 * @param rRect
 * @return true/false
 */
bool operator!=(const Rect& lRect, const Rect& rRect)
{
	return (!(lRect == rRect));
}


/**
 * Compute delta between two Rect
 * @param r1 IN
 * @param r2 IN
 * @return delta values
 */
Rect CIHMTracking::Rect_delta(Rect r1, Rect r2)
{
	Rect delta(0,0,0,0);

	delta.x = abs(r1.x-r2.x);
	delta.y = abs(r1.y-r2.y);
	delta.width = abs(r1.width-r2.width);
	delta.height = abs(r1.height-r2.height);

	return(delta);
}


/**
 * Compute Rect center
 * @param roi IN
 * @return center point coordonates
 */
Point CIHMTracking::Rect_center(Rect roi)
{
	Point center(0, 0);

	center.x = roi.x + roi.width/2;
	center.y = roi.y + roi.height/2;

	return(center);
}


/**
 * Set Rect from two points
 * @param p1 IN
 * @param p2 IN
 * @return rect
 */
Rect CIHMTracking::Rect_set(Point p1, Point p2)
{
	Rect roi(0, 0, 0, 0);

	roi.x = p1.x;
	roi.y = p1.y;
	roi.width = p2.x-p1.x;
	roi.height = p2.y-p1.y;

	return(roi);
}


/**
 * Print Rect values
 * @param roi IN
 * @return string
 */
string CIHMTracking::Rect_print(Rect roi)
{
	stringstream out;

	out << "[" << roi.x << ", ";
	out << roi.y << ", ";
	out << roi.width << ", ";
	out << roi.height << "]";

	return(out.str());
}


/**
 * Average two Rect
 * @param r1 IN
 * @param r2 IN
 * @return average Rect
 */
Rect CIHMTracking::Rect_average(Rect r1, Rect r2)
{
	Rect avg(0, 0, 0, 0);

	avg.x = abs((int)(r1.x+r2.x)/2);
	avg.y = abs((int)(r1.y+r2.y)/2);
	avg.width = abs((int)(r2.width+r2.width)/2);
	avg.height = abs((int)(r2.height+r2.height)/2);

	return(avg);
}


/**
 * Check valid Rect
 * @param img IN
 * @param roi OUT
 * @return true when done
 */
bool CIHMTracking::Rect_limit(int cols, int rows, int margin, Rect& roi)
{
	// Check min values
	if (roi.x <= 0)
		roi.x = 1;
	if (roi.y <= 0)
		roi.y = 1;
	if (roi.width <= 0)
		roi.width = 1;
	if (roi.height <= 0)
		roi.height = 1;

	// Check max values
	if (roi.x > cols-1)
		roi.x = cols-1-margin;
	if (roi.y > rows-1)
		roi.y = rows-1-margin;
	if (roi.width > cols-1-roi.x)
		roi.width = cols-1-roi.x-margin;
	if (roi.height > rows-1-roi.y)
		roi.height = rows-1-roi.y-margin;

	return(true);
} // Rect_limit

#if 0
/**
 * Compute direction base on last x points
 * @param img IN
 * @param frameCount IN
 * @param obj IN
 * @param vect OUT
 * @return true when done
 */
bool CIHMTracking::compute_direction_vector(const Mat& img, int frameCount,
	const MISBlobObject& obj, Rect& vect)
{
	const int minPointsStored = 4;

	vect.x = 1;
	vect.y = 1;
	vect.width = 1;
	vect.height = 1;

	// Check enough points
	int pointsCount = obj.data.size();
	if (pointsCount < minPointsStored)
		return(false);

	MISBlobData dataK = obj.data[pointsCount-minPointsStored];
	MISBlobData data0 = obj.data.back();


	// Compute delta in frame
	int deltaFrame = frameCount-data0.frameNumber;

	// Compute variation per frame (moving distance) [pixel] 
	Point cK = Rect_center(dataK.roi);
	Point c0 = Rect_center(data0.roi);

	Rect v0 = Rect_set(cK, c0);

	// step average...
	float stepX = (float)v0.width/minPointsStored;
	float stepY = (float)v0.height/minPointsStored;
//DEBUG:
//	cout << "step(x, y) = (" << stepX << ", " << stepY << ")" << endl;

	// Update position
	vect.x = data0.roi.x+stepX*deltaFrame;
	vect.y = data0.roi.y+stepY*deltaFrame;
	// Keep blob size
	vect.width = data0.roi.width;
	vect.height = data0.roi.height;

	Rect_limit(img.cols, img.rows, 20, vect);
//DEBUG:
//	cout << "vect = " << Rect_print(vect) << endl;

	return(true);
} // compute_direction_vector

#endif

