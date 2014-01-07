/**
 * @brief Get/set functions definition
 * @file ihmfriend_get.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmfriend.h"


/**
 * Get version string, i.e. "0.1.0"
 */
string CIHMFriend::version_get(void) const
{
	stringstream out;

	int major = kCIHMFriend_VERSION_MAJOR_NUMBER;
	int minor = kCIHMFriend_VERSION_MINOR_NUMBER;
	int patch = kCIHMFriend_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
} // version_get


bool  CIHMFriend::mode_set(EFriend_Mode newMode)
{
	data.mode = newMode;
	return true;
}

CIHMFriend::EFriend_Mode CIHMFriend::mode_get(void) const
{
	return data.mode;
}


void CIHMFriend::image_filename_get(char *filename)
{
		struct timeval tv;

		gettimeofday(&tv, NULL);

		int time_100 = tv.tv_sec*10 + tv.tv_usec /50000;

		int filenumber = time_100%20+1;


		//sprintf(filename, "/home/ihm/Downloads/s/%u.png", filenumber);
		sprintf(filename, "../../picture/friend/%u.png", filenumber);
}


float CIHMFriend::angle_get(Point from, Point to)
{
	float deltax = (to.x-from.x);
	float deltay = (to.y-from.y);

	float angle = atan(abs(deltay/deltax));
	if(deltax<0 && deltay>0)
		angle+=CV_PI;
	else if(deltax<0 && deltay<0)
		angle=CV_PI-angle;
	else if(deltax>0 && deltay>0)
		angle=2*CV_PI-angle;

	return angle;
}


int CIHMFriend::difftime_get()
{
	struct timeval currenttime;
	gettimeofday(&currenttime, NULL);
	int seconds = currenttime.tv_sec-data.lastTime.tv_sec;
	int milliseconds = (currenttime.tv_usec - data.lastTime.tv_usec)/1000;
	data.lastTime.tv_sec = currenttime.tv_sec;
	data.lastTime.tv_usec = currenttime.tv_usec;

	return(seconds*1000+milliseconds);
}


