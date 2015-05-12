/**
 * @brief Main function definition
 * @file ihmfriend_test_main.cpp
 * @author ...
 * @date Dec 2013
 */


#include <ihmfriend.h>


void onMouse(int event, int x, int y, int flags, void* param)
{
	/*  if( event != EVENT_LBUTTONDOWN )
	        return;
	    else*/
	{
		Point *pos = (Point*)param;
		pos->x=x;
		pos->y=y;
	}
//    if( event != EVENT_LBUTTONDOWN )
//        return;
//    else
//    {
//    	//Search if a digit is pressed
//    	int pos=-1;
//    	for(int i= 0;i<NBR_DIGITS;i++)
//    	{
//    		if(digits[i].position_get().contains(Point(x,y)))
//    		{
//    			pos = i;
//    			//break;
//    		}
//    	}
//    	if(pos >= 0)
//    	{
//    		timer::incr_digit(pos);
//    		timer::refresh();
//    	}
//    }
}

/**
 * Main function
 */
int main(void)
{

	CIHMFriend fr;

	cout << fr << endl;
	Mat picture;
	Point pos(400, 500);

	namedWindow("CIHMFriendtest");

	setMouseCallback("CIHMFriendtest", onMouse, &pos);


	while(1)
	{
		picture = Mat::zeros(1000, 1000, CV_8UC3);
		picture = Scalar(235,235,235);

		fr.draw_friend(picture, pos);

		circle(picture, pos, 2, Scalar(255,0,0));
		circle(picture, pos, 100, Scalar(255,0,0));
		imshow("CIHMFriendtest", picture);

		int key = waitKey(100);
		if(key==27)	// <Esc>
			break;
		if(key=='i')
		{
			fr.mode_set(CIHMFriend::kMode_Idle);
		}
		else if(key=='w')
		{
			fr.mode_set(CIHMFriend::kMode_Walking);

		}
	}


	return(0);
} // main


