/**
 * @brief On-Screen Display functions definition
 * @file pathsimulator_osd.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */

#include "pathsimulator.h"


/**
 * Display trajectory type
 * @param pPath IN
 * @param pos IN
 * @param color IN
 * @param img OUT
 * @return true if succeed
 */
bool type_display(const CMISPath* pPath, Point pos, Scalar color, Mat& img)
{
	if (img.empty())
		return(false);

	string txt("Trajectory: ");

	txt += pPath->type_print();
	putText(img, txt, pos, FONT_HERSHEY_SIMPLEX, 0.6, color);

	return(true);
} // type_display


/**
 * Display average speed
 * @param pPath IN
 * @param pos IN
 * @param color IN
 * @param img OUT
 * @return true if succeed
 */
bool speed_display(const CMISPath* pPath, Point pos, Scalar color, Mat& img)
{
	if (img.empty())
		return(false);

	double avg = 0.0;
	double max = 0.0;
	pPath->speed_get(avg, max);

	stringstream txt1;
	txt1 << "Avg speed: ";
	txt1 << avg;
	txt1 << " [pixel/s]";
	putText(img, txt1.str(), pos, FONT_HERSHEY_SIMPLEX, 0.6, color);

	stringstream txt2;
	txt2 << "Max speed: ";
	txt2 << max;
	txt2 << " [pixel/s]";
	putText(img, txt2.str(), Point(pos.x, pos.y+30), FONT_HERSHEY_SIMPLEX, 0.6, color);

	return(true);
} // speed_display


/**
 * Display total distance
 */
bool distance_display(const CMISPath* pPath, Point pos, Scalar color, Mat& img)
{
	if (img.empty())
		return(false);

	stringstream txt;
	double dist = 0.0;

	txt << "Distance:  ";
	dist = pPath->distance_get();
	txt << dist;
	txt << " [pixel]";
	putText(img, txt.str(), pos, FONT_HERSHEY_SIMPLEX, 0.6, color);

	return(true);
} // distance_display
