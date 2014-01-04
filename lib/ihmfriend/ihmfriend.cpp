/**
 * @brief Constructor/destructor functions definition
 * @file ihmfriend.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmfriend.h"

#include <sys/time.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265


/**
 * Constructor
 */
CIHMFriend::CIHMFriend(void)
{
	appdata.mode = kMode_Idle;
	appdata.pos =Point(300,300);
	appdata.angle = 30;
	appdata.speed = 0.05;
	appdata.radius = 100;
	appdata.onradius = false;
	gettimeofday(&appdata.last_time, NULL);
}


/**
 * Destructor
 */
CIHMFriend::~CIHMFriend(void)
{

}


bool  CIHMFriend::mode_set(EFriend_Mode newMode)
{
	appdata.mode = newMode;
	return true;
}

CIHMFriend::EFriend_Mode CIHMFriend::mode_get(void) const
{
	return appdata.mode;
}

void CIHMFriend::get_image_filename(char *filename)
{
		struct timeval tv;

		gettimeofday(&tv, NULL);

		int time_100 = tv.tv_sec*10 + tv.tv_usec /50000;

		int filenumber = time_100%20+1;


		sprintf(filename, "/home/ihm/Downloads/s/%u.png", filenumber);
}
float CIHMFriend::get_angle(Point from, Point to)
{
	float deltax = (to.x-from.x);
	float deltay = (to.y-from.y);

	float angle = atan(abs(deltay/deltax));
	if(deltax<0&&deltay>0)
		angle+=PI;
	else if(deltax<0&&deltay<0)
		angle=PI-angle;
	else if(deltax>0&&deltay>0)
			angle=2*PI-angle;

	cout<<angle*180/PI<<endl;
	return angle;
}

int CIHMFriend::get_difftime()
{
	struct timeval currenttime;
	gettimeofday(&currenttime, NULL);
	int seconds = currenttime.tv_sec-appdata.last_time.tv_sec;
	int milliseconds = (currenttime.tv_usec - appdata.last_time.tv_usec)/1000;
	appdata.last_time.tv_sec = currenttime.tv_sec;
	appdata.last_time.tv_usec = currenttime.tv_usec;
	return seconds*1000+milliseconds;

}

void CIHMFriend::navigate(int deltat)
{
	float angle = get_angle(appdata.pos, appdata.waypoint);
	int deltax = appdata.speed*10 * deltat * cos(angle);
	int deltay = appdata.speed*10 * deltat * sin(angle);

	if(abs(appdata.waypoint.x-appdata.pos.x)>10&&abs(appdata.waypoint.y-appdata.pos.y)>10)
	{
		appdata.pos += Point(deltax, -deltay);
		appdata.angle = -angle-PI/2;
	}else
	{
		appdata.onradius=true;
		appdata.angle = 0;

	}
}
void CIHMFriend::turn(int deltat,Point current_pos)
{
	float delta_alpha = appdata.speed/appdata.radius*deltat;
	appdata.angle += delta_alpha;
	if(appdata.angle>2*PI)
	{
		appdata.angle-=2*PI;
	}

	appdata.pos.x=current_pos.x+appdata.radius*cos(appdata.angle);
	appdata.pos.y=current_pos.y+appdata.radius*sin(appdata.angle);
}

void CIHMFriend::draw_friend(Mat &image,const Point &current_pos)
{
	appdata.waypoint.x=current_pos.x+appdata.radius;
	appdata.waypoint.y=current_pos.y;

	char filename[100];
	get_image_filename(filename);

	//int elapsed = difftime(time(NULL),appdata.last_time);
	int deltat = get_difftime();


	switch(appdata.mode)
	{
	case  kMode_Idle:
		appdata.onradius = false;
		break;
	case kMode_Walking:
		if(appdata.onradius)
		{
			turn(100,current_pos);
		}else
		{
			navigate(10);
		}
		break;
	default:
		break;
	}
	Mat picture;
	picture = imread(filename, -1);
	resize(picture,picture,Size(100,100));
	rotate(picture, -appdata.angle*180/PI, picture);
	circle(image, appdata.pos,10, Scalar(0,255,255));
	overlayImage(image,picture,image,appdata.pos+Point(-50,-50));

	circle(image, appdata.waypoint,10, Scalar(0,255,0));



}

/**
 * Overlay an image
 */
void CIHMFriend::overlayImage(const cv::Mat &background, const cv::Mat &foreground,
  cv::Mat &output, cv::Point2i location)
{
  background.copyTo(output);


  // start at the row indicated by location, or at row 0 if location.y is negative.
  for(int y = std::max(location.y , 0); y < background.rows; ++y)
  {
    int fY = y - location.y; // because of the translation

    // we are done of we have processed all rows of the foreground image.
    if(fY >= foreground.rows)
      break;

    // start at the column indicated by location,

    // or at column 0 if location.x is negative.
    for(int x = std::max(location.x, 0); x < background.cols; ++x)
    {
      int fX = x - location.x; // because of the translation.

      // we are done with this row if the column is outside of the foreground image.
      if(fX >= foreground.cols)
        break;

      // determine the opacity of the foregrond pixel, using its fourth (alpha) channel.
      double opacity =
        ((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3])

        / 255.;


      // and now combine the background and foreground pixel, using the opacity,

      // but only if opacity > 0.
      for(int c = 0; opacity > 0 && c < output.channels(); ++c)
      {
        unsigned char foregroundPx =
          foreground.data[fY * foreground.step + fX * foreground.channels() + c];
        unsigned char backgroundPx =
          background.data[y * background.step + x * background.channels() + c];
        output.data[y*output.step + output.channels()*x + c] =
          backgroundPx * (1.-opacity) + foregroundPx * opacity;
      }
    }
  }
}
/**
 * Rotate an image
 */
void CIHMFriend::rotate(cv::Mat& src, double angle, cv::Mat& dst)
{
    int len = std::max(src.cols, src.rows);
    cv::Point2f pt(len/2., len/2.);
    cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);

    cv::warpAffine(src, dst, r, cv::Size(len, len));
}
