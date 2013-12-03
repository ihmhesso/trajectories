/**
 * @brief Main function definition
 * @file pathsimulator_main.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */


#include "pathsimulator.h"


/**
 * Main function
 * @param argc IN
 * @param argv IN
 * @return always 0
 */
int main(int argc, char* argv[])
{

	/*
	 * [INIT]
	 */
	ApplicationData app;
	ApplicationData_init(app);

	/*
	 * [ARGS] check
	 */
	if (!args_check(argc, argv, app))
		return(0);


	//	app.pPath = new CMISPath(kTrajectory_Type_Circle, app.size, 40);
	//	app.pPath = new CMISPath(kTrajectory_Type_Ellipse, app.size, 40);
		app.pPath = new CMISPath(kTrajectory_Type_Eight, app.size, 40);

//DEBUG:
	cout << *app.pPath << endl;


	/*
	 * [GUI] init
	 */
	app.winName = "Path Simulator ";
	{
		stringstream size;
		size << app.size;
		app.winName += size.str();
	}

	namedWindow(app.winName);
//	displayOverlay(app.winName, "Press 's' to swich style or <Esc> to Quit", 2000);

	// Mouse
	setMouseCallback(app.winName, mouse_callback, (void*)&app);

	// Trackbar
	createTrackbar("object Size", app.winName, &app.objSize, 200);
	createTrackbar("Points count", app.winName, &app.pointsCount, 2000, pointsCount_has_changed, (void*)&app);
	if (app.maxFrame != 0)
		createTrackbar("Frames count", app.winName, &app.framesCount, app.maxFrame, framesCount_has_changed, (void*)&app);


	app.pPath->path_draw(app.src, app.pathColor, app.img);
	menu_print();

	if (app.loopEnable)
		app.mode = kPlayback_Mode_Play;

//FIXME: Should be remove only to test...
	{
		CMISPath path2(kTrajectory_Type_Eight, app.size, 40);

		cout << "distances(min, average, max) = " << path2.euclidean_distance(path2, *app.pPath) << endl;

		// Try generate erro graph
		path2.errors_graph_generate(*app.pPath, "graph.png");
	}

	/*
	 * Main loop
	 */
	app.tNow = (double)getTickCount()/(double)getTickFrequency();;
	app.tRef = app.tNow;
	int key = 0;
	do
	{
		/*
		 * [VIDEO]
		 */
		video_handler(app);


		/*
		 * [KEYBOARD]
		 */
		key = waitKey(2);
		keyboard_handler(app, key);

		/*
		 * [RECORD]
		 */
		//TODO: ...

		/*
		 * [OSD]
		 */
		type_display(app.pPath, Point(20,30), Scalar(0, 255, 0), app.img);
		distance_display(app.pPath, Point(20,60), Scalar(0, 255, 0), app.img);
		speed_display(app.pPath, Point(20,90), Scalar(0, 255, 0), app.img);

		imshow(app.winName, app.img);

	} while(!app.exitProg);


	/*
	 * [RESSOURCE] free
	 */
	if (app.pCapture)
		delete app.pCapture;

	if (app.pRecord)
		delete app.pRecord;

	delete app.pPath;

	destroyAllWindows();

	return(0);
} // main
