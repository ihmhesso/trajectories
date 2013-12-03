/**
 * @brief Init functions definition
 * @file mispath_init.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */


#include "mispath.h"


/**
 * Init
 * @param path OUT
 */
void CMISPath::path_init(vector<PathData>& path)
{
	switch (type_)
	{
	case kTrajectory_Type_Circle:
		for (int i = 0; i < pointsCount_; ++i)
		{
			Point p(0, 0);
			double angle = (double)(2.0*CV_PI)/(double)pointsCount_;	// [radian]
			double radius = 0.0;

			if (size_.width <= size_.height)
				radius = (double)size_.width/4.0;
			else
				radius = (double)size_.height/4.0;

			p = circle_equation(radius, angle*(double)i);

			PathData data;
			data.frameCount = i;
			data.p = p;
			path.push_back(data);
		}
		break;
	case kTrajectory_Type_Ellipse:
		for (int i = 0; i < pointsCount_; ++i)
		{
			Point p(0, 0);
			double angle = (double)(2.0*CV_PI)/(double)pointsCount_;	// [radian]

			p = ellipse_equation(size_.width/3, size_.height/3, angle*(double)i);

			PathData data;
			data.frameCount = i;
			data.p = p;
			path.push_back(data);
		}
		break;
	case kTrajectory_Type_Eight:
		for (int i = 0; i < pointsCount_; ++i)
		{
			Point p(0, 0);
			double angle = (double)(2.0*CV_PI)/(double)pointsCount_;	// [radian]

			p = eight_equation(size_.width/3, size_.height/3, angle*(double)i);

			PathData data;
			data.frameCount = i;
			data.p = p;
			path.push_back(data);
		}
		break;
	default:
		// Do nothing
		break;
	} // switch

} // path_init


