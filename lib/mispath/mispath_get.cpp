/**
 * @brief Get/set functions definition
 * @file mispath_get.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */


#include "mispath.h"


/**
 * Get version number
 * @return version string like "0.1.0"
 */
string CMISPath::version_get(void) const
{
	stringstream out;

	int ma = kCMISPath_MAJOR_VERSION;
	int mi = kCMISPath_MINOR_VERSION;
	int pa = kCMISPath_PATCH_VERSION;

	out << ma << "." << mi << "." << pa;

	return(out.str());
} // version_get


/**
 * Get version number
 * @param ma OUT major number
 * @param mi OUT minor number
 * @param pa OUT patch number
 * @return version string like "0.1.0"
 */
string CMISPath::version_get(int& ma, int& mi, int& pa) const
{
	stringstream out;

	ma = kCMISPath_MAJOR_VERSION;
	mi = kCMISPath_MINOR_VERSION;
	pa = kCMISPath_PATCH_VERSION;

	out << ma << "." << mi << "." << pa;

	return(out.str());
} // version_get


/**
 * Get current path drawing style
 */
EDrawing_Style CMISPath::style_get(void) const
{
	return(style_);
}


/**
 * Get current path drawing style
 */
bool CMISPath::style_set(EDrawing_Style style)
{
	if (style >= kDrawing_Style_Max)
		return(false);

	style_ = style;
	return(true);
} // style_set


/**
 * Clear previous path data
 * @return true when done
 */
bool CMISPath::clear(void)
{
	path_.clear();
	return(true);
}


/**
 * Get current size
 * @return size_
 */
Size CMISPath::size_get(void) const
{
	return(size_);
}


/**
 * Set size
 * @param size IN
 * @return true when done
 */
bool CMISPath::size_set(Size size)
{
	size_ = size;
	if (type_ != kTrajectory_Type_Free)
	{
		clear();
		path_init(path_);
	}

	return(true);
}


/**
 * Get current predefined trajectory points count
 * @return pointsCount_
 */
int  CMISPath::points_count_get(void) const
{
	return(path_.size());
}


/**
 * Set predefined trajectory points count
 * @param value IN
 * @return true when done
 */
bool CMISPath::points_count_set(int value)
{
	if (value < 1)
		pointsCount_ = 1;
	else
		pointsCount_ = value;

	clear();
	path_init(path_);

	return(true);
}


/**
 * Get current predefined trajectory type
 * @return type_
 */
ETrajectory_Type CMISPath::type_get(void) const
{
	return(type_);
}


/**
 * Set predefined trajectory type (circle, ellipse, ...)
 * @param type IN
 * @return true when done
 */
bool CMISPath::type_set(ETrajectory_Type type)
{
	type_ = type;
	clear();
	path_init(path_);
	return(true);
}


/**
 * Get total path length [m]
 */
double CMISPath::distance_get(void) const
{
	double dist = 0.0;

	switch (type_)
	{
	case kTrajectory_Type_Eight:
	case kTrajectory_Type_Free:
		{
			double dx = 0.0;
			double dy = 0.0;
			int count = path_.size();

			// Parse all points
			for (int i = 0; i < count-1; ++i)
			{
				dx = abs(path_[i].p.x-path_[i+1].p.x);
				dy = abs(path_[i].p.y-path_[i+1].p.y);
				dist += sqrt(dx*dx + dy*dy);
			}
		}
		break;
	case kTrajectory_Type_Circle:
		{
			double r = (double)size_.width/4.0;
			dist = 2.0*(double)CV_PI*r;
		}
		break;
	case kTrajectory_Type_Ellipse:
		{
			double a = (double)size_.width/3.0;
			dist = (a/2.0)*sqrt(93.0+0.5*sqrt(3.0));
		}
		break;
	default:
		//Do nothing
		break;
	}

	return(dist);
} // distance_get



/**
 * Get average speed [m]
 */
bool CMISPath::speed_get(double& avg, double& max) const
{
	double dist = distance_get();

	avg = dist/(path_.size()*(1.0/30.0));

	// Compute max speed
	max = 0;
	double dx = 0.0;
	double dy = 0.0;
	double df = 0.0;
	double speed = 0.0;
	int count = path_.size();

	// Parse all points
	for (int i = 0; i < count-1; ++i)
	{
		dx = abs(path_[i].p.x-path_[i+1].p.x);
		dy = abs(path_[i].p.y-path_[i+1].p.y);
		df = path_[i+1].frameCount-path_[i].frameCount;

		dist = sqrt(dx*dx + dy*dy);
		speed = dist/(df*(1.0/30.0));

		if (speed > max)
		{
//DEBUG:
//			cout << "dist = " << dist << ", speed = " << speed << ", max = " << max << endl;
			max = speed;
		}
	}

	return(true);
} // speed_get


/**
 * Get Object shape
 * @return object shape value
 */
EObject_Shape CMISPath::shape_get(void)
{
	return(objShape_);
}


/**
 * Set Object shape
 * @param shape IN
 * @return true if succed
 */
bool CMISPath::shape_set(EObject_Shape shape)
{
	if (shape >= kObject_Shape_Max)
		return(false);

	objShape_ = shape;
	return(true);
} // shape_set

