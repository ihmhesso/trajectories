/**
 * @brief Application header file
 * @file pathsimulator.h
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */
#ifndef _PATH_SIMULATOR_H_
#define _PATH_SIMULATOR_H_


#include <iostream>
#include <sstream>	// stringstream
#include <cctype>	// tolower()
#include <cstdio>	// fprintf()

#include <unistd.h>	// usleep()
#include <time.h>	// getdate()
#include <sys/stat.h>	// stat(), mkdir()


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <mispath.h>


#define kPATH_SIMULATOR_PROGRAM_NAME	"pathsimulator"

#define kPATH_SIMULATOR_VERSION_MAJOR	(0)
#define kPATH_SIMULATOR_VERSION_MINOR	(7)
#define kPATH_SIMULATOR_VERSION_PATCH	(0)

#define kPATH_SIMULATOR_DEFAULT_FRAME_RATE	(30.0)	/** [fps] */

#define kPATH_SIMULATOR_DEFAULT_AREA_WIDTH	(800)	/** [pixel] */
#define kPATH_SIMULATOR_DEFAULT_AREA_HEIGHT	(600)	/** [pixel] */

#define kPATH_SIMULATOR_DEFAULT_OBJ_COLOR	(255, 255, 255)
#define kPATH_SIMULATOR_DEFAULT_BG_COLOR	(0, 0, 0)
#define kPATH_SIMULATOR_DEFAULT_PATH_COLOR	(0, 255, 0)

#define kPATH_SIMULATOR_DEFAULT_OBJ_SIZE	(20)	/** [pixel] */
#define kPATH_SIMULATOR_DEFAULT_POINTS_COUNT	(40)	/** Number of points in predefined trajectory */


using namespace std;
using namespace cv;


/**
 * Playback mode enumeration
 */
typedef enum _EPlayback_Mode
{
	kPlayback_Mode_Stop = 0,
	kPlayback_Mode_Play,
	kPlayback_Mode_Frame_Forward,
	kPlayback_Mode_Frame_Backward,
	kPlayback_Mode_Record,

} EPlayback_Mode;


/**
 * Application data structure
 */
typedef struct ApplicationData_
{
	string filename;
	Size size;			// default 800x600
	Scalar objColor;
	Scalar bgColor;
	Scalar pathColor;
	int objSize;		/** Object radius slider (default=20) [pixel] */
	int pointsCount;	/** Number of points in predefined trajectory (Points slider) (default=40) */

	VideoCapture* pCapture;
	int maxFrame;
	VideoWriter* pRecord;
	int framesCount;
	string folderName;
	bool generateImages;

	string winName;		/** Window name */
	Mat src;		/** Reference background image */
	Mat img;

	CMISPath* pPath;

	EPlayback_Mode mode;
	bool freeHandRecording;
	bool loopEnable;
	double frameTime;
	double tRef;
	double tNow;

	Point mouseCoord;

	bool exitProg;
} ApplicationData, *pApplicationData;


/*
 * Functions prototypes
 */
// pathsimulator_init.cpp
void ApplicationData_init(ApplicationData& app);

// pathsimulator_args.cpp
void help_print(void);
bool args_check(int argc, char* argv[], ApplicationData& app);

// pathsimulator_keyboard.cpp
void menu_print(void);
bool keyboard_handler(ApplicationData& app, int key);
string date_time_get(int& d, int& t);
string format_filename(const string& path, const string& src, ETrajectory_Type type, const string& ext);

// pathsimulator_mouse.cpp
void mouse_callback(int event, int x, int y, int flags, void* pUserData = 0);

// pathsimulator_trackbar.cpp
void pointsCount_has_changed(int value, void* pUserData);
void framesCount_has_changed(int value, void* pUserData);

// pathsimulator_video.cpp
bool video_handler(ApplicationData& app);

// pathsimulator_osd.cpp
bool type_display(const CMISPath* pPath, Point pos, Scalar color, Mat& img);
bool speed_display(const CMISPath* pPath, Point pos, Scalar color, Mat& img);
bool distance_display(const CMISPath* pPath, Point pos, Scalar color, Mat& img);

#endif // _PATH_SIMULATOR_H_
