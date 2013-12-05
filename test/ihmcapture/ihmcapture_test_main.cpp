/**
 * @brief Main function definition
 * @file ihmcapture_test_main.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmcapture_test.h"


/**
 * Callback for incoming images
 * @param img IN
 * @param fCount IN
 * @param pData OUT
 */
void new_image(const Mat& img, int fCount, void* pData)
{
	pApplicationParam pApp = (pApplicationParam)pData;

	img.copyTo(pApp->src);
	pApp->newFrame = true;
}


/**
 * Main function
 * @param argc IN
 * @param argv IN
 * @return always 0
 */
int main(int argc, char* argv[])
{

	CIHMCapture capture;
	ApplicationParam app;
	app.src = Mat::zeros(380, 640, CV_8UC3);
	app.devId = 0;
	app.winName = "ihmcapture_test";
	app.exitProgram = true;

	cout << capture.version_get() << endl;

	// Try to open device
	if (!capture.open(app.devId))
	{
		cout << "ERROR: can't open device " << app.devId << endl;
		return(0);
	}
	app.exitProgram = false;

	// Setup callback
	capture.callback_set(new_image, (void*)&app);


	/*
	 * [GUI] init
	 */
	namedWindow(app.winName);


	/*
	 * [MAIN] loop
	 */
	int key = 0;
	do
	{
		key = waitKey(2);
		switch ((unsigned short)key)
		{
		case ' ':	// 'Space'
			switch (capture.mode_get())
			{
			case CIHMCapture::kMode_Stop:
				capture.mode_set(CIHMCapture::kMode_Play);
				break;
			default:
			case CIHMCapture::kMode_Play:
				capture.mode_set(CIHMCapture::kMode_Stop);
				break;
			}
			break;
		case 0x1b:	// 'Esc'
			app.exitProgram = true;
			break;
		default:
			// Do nothing
			break;
		}

		if (app.newFrame)
			app.newFrame = false;

		imshow(app.winName, app.src);

	} while (!app.exitProgram);


	capture.close();
	destroyAllWindows();
	usleep(1);

	return(0);
} // main

