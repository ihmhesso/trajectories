/**
 * @brief Init functions definition
 * @file pathsimulator_init.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */

#include "pathsimulator.h"


/**
 * Init ApplicationData
 */
void ApplicationData_init(ApplicationData& app)
{

	app.size = Size(kPATH_SIMULATOR_DEFAULT_AREA_WIDTH, kPATH_SIMULATOR_DEFAULT_AREA_HEIGHT);
	app.objColor = Scalar kPATH_SIMULATOR_DEFAULT_OBJ_COLOR;
	app.bgColor = Scalar kPATH_SIMULATOR_DEFAULT_BG_COLOR;
	app.pathColor = Scalar kPATH_SIMULATOR_DEFAULT_PATH_COLOR;
	app.objSize = kPATH_SIMULATOR_DEFAULT_OBJ_SIZE;
	app.pointsCount = kPATH_SIMULATOR_DEFAULT_POINTS_COUNT;

	app.pCapture = 0;
	app.maxFrame = 0;
	app.pRecord = 0;
	app.framesCount = 0;
	app.generateImages = false;

	app.src = Mat::zeros(app.size, CV_8UC3);
	app.img = Mat::zeros(app.size, CV_8UC3);


	app.mode = kPlayback_Mode_Stop;
	app.freeHandRecording = false;
	app.loopEnable = false;
	app.frameTime = 1.0/kPATH_SIMULATOR_DEFAULT_FRAME_RATE;	// [s]
	app.tRef = 0.0;
	app.tNow = 0.0;

	app.mouseCoord = Point(0,0);
	app.exitProg = false;

} // ApplicationData_init
