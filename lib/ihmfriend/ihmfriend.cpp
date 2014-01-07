/**
 * @brief Constructor/destructor functions definition
 * @file ihmfriend.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmfriend.h"


/**
 * Constructor
 */
CIHMFriend::CIHMFriend(void)
{
	data.mode = kMode_Idle;
	data.pos = Point(300,300);
	data.angle = 30.0f;
	data.speed = 0.05f;
	data.radius = 100;
	data.onRadius = false;
	gettimeofday(&data.lastTime, NULL);
}


/**
 * Destructor
 */
CIHMFriend::~CIHMFriend(void)
{

}




void CIHMFriend::navigate(int deltat)
{
	float angle = angle_get(data.pos, data.waypoint);
	int deltax = data.speed * deltat * cos(angle);
	int deltay = data.speed * deltat * sin(angle);

	if(abs(data.waypoint.x-data.pos.x)>10 || 
		abs(data.waypoint.y-data.pos.y)>10)
	{
		data.pos += Point(deltax, -deltay);
		data.angle = -angle-CV_PI/2;
	}
	else
	{
		data.onRadius=true;
		data.angle = 0;
	}
}


void CIHMFriend::turn(int deltat, Point currentPos)
{
	float deltaAlpha = data.speed/data.radius*deltat;
	data.angle += deltaAlpha;

	if (data.angle>2*CV_PI)
	{
		data.angle-=2*CV_PI;
	}

	data.pos.x = currentPos.x+data.radius*cos(data.angle);
	data.pos.y = currentPos.y+data.radius*sin(data.angle);
}


void CIHMFriend::draw_friend(Mat& image, const Point& currentPos)
{
	data.waypoint.x = currentPos.x+data.radius;
	data.waypoint.y = currentPos.y;

	char filename[100];
	image_filename_get(filename);

	//int elapsed = difftime(time(NULL),appdata.last_time);
	int deltat = difftime_get();

	switch(data.mode)
	{
	case kMode_Idle:
		data.onRadius = false;
		break;
	case kMode_Walking:
		if (data.onRadius)
		{
		//	turn(100,current_pos);
			turn(deltat, currentPos);
		}else
		{
		//	navigate(10);
			navigate(deltat);
		}
		break;
	default:
		break;
	}

	Mat picture;
	picture = imread(filename, -1);
	resize(picture, picture, Size(100,100));
	rotate(picture, -data.angle*180/CV_PI, picture);
	circle(image, data.pos,10, Scalar(0,255,255));
	overlay_image(image, picture, image, data.pos+Point(-50,-50));

	circle(image, data.waypoint,10, Scalar(0,255,0));

}


/**
 * Overlay an image
 */
void CIHMFriend::overlay_image(const Mat& background, const Mat& foreground,
  Mat& output, Point2i location)
{
	background.copyTo(output);

	// start at the row indicated by location, or at row 0 if location.y is negative.
	for (int y = std::max(location.y , 0); y < background.rows; ++y)
	{
		int fY = y - location.y; // because of the translation

		// we are done of we have processed all rows of the foreground image.
		if (fY >= foreground.rows)
			break;

		// start at the column indicated by location,
		// or at column 0 if location.x is negative.
		for (int x = std::max(location.x, 0); x < background.cols; ++x)
		{
			int fX = x - location.x; // because of the translation.

			// we are done with this row if the column is outside of the foreground image.
			if (fX >= foreground.cols)
				break;

			// determine the opacity of the foregrond pixel, using its fourth (alpha) channel.
			double opacity = ((double)foreground.data[fY * foreground.step +
				fX * foreground.channels() + 3]) / 255.0;


			// and now combine the background and foreground pixel, using the opacity,

			// but only if opacity > 0.
			for (int c = 0; opacity > 0 && c < output.channels(); ++c)
			{
				unsigned char foregroundPx =
					foreground.data[fY * foreground.step +
					fX * foreground.channels() + c];
				unsigned char backgroundPx =
					background.data[y * background.step +
					x * background.channels() + c];
				output.data[y*output.step + output.channels()*x + c] =
					backgroundPx * (1.-opacity) + foregroundPx * opacity;
			}
		}
	}
} // overlay_image


/**
 * Rotate an image
 */
void CIHMFriend::rotate(Mat& src, double angle, Mat& dst)
{
    int len = std::max(src.cols, src.rows);
    Point2f pt(len/2., len/2.);
    Mat r = getRotationMatrix2D(pt, angle, 1.0);

    warpAffine(src, dst, r, Size(len, len));
}

