/**
 * @brief Keyboard function definition
 * @file pathsimulator_keyboard.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */


#include "pathsimulator.h"


/**
 * Print menu
 */
void menu_print(void)
{
	cout << "Menu:" << endl;
	cout << "    'c': Change path drawing style" << endl;
	cout << "    'd': Display path data" << endl;
	cout << "    'i': Generate images sequence" << endl;
	cout << "    'f': Start/stop free hand recording" << endl;
	cout << "    'l': Enable/disable playback loop mode" << endl;
	cout << "    'o': Change object shape (circle, ellipse, ...)" << endl;
	cout << "    'p': Playback (from begining)" << endl;
	cout << "    'r': Start/stop recording free hand sequence" << endl;
	cout << "    's': Stop playback/recording" << endl;
	cout << "    't': Change trajectory type" << endl;
	cout << "    'v': Generate video sequence (.avi)" << endl;
	cout << "    'w': Write path file (.csv)" << endl;
	cout << "    'x': Read a path file (.csv)" << endl;
//	cout << "     ->: One frame forward" << endl;
	cout << "<space>: Start/stop playback" << endl;
	cout << "  <Esc>: Exit program" << endl;
}


/**
 * Main function
 * @param app OUT
 * @param key IN
 * @return True when done
 */
bool keyboard_handler(ApplicationData& app, int key)
{
	switch ((unsigned short)key)
	{
	case 'c':		// Change drawing style
//		app.mode = kPlayback_Mode_Stop;
		switch (app.pPath->style_get())
		{
		case kDrawing_Style_Off:
			app.pPath->style_set(kDrawing_Style_Point);
			break;
		case kDrawing_Style_Point:
			app.pPath->style_set(kDrawing_Style_Line);
			break;
		case kDrawing_Style_Line:
			app.pPath->style_set(kDrawing_Style_Off);
			break;
		default:
			break;
		}
		app.pPath->path_draw(app.src, app.pathColor, app.img);
		break;
	case 'd':		// Display path data
		cout << *app.pPath << endl;
		break;
	case 'f':		// Start/stop free hand recording
		if (app.freeHandRecording)
		{
			cout << "STOP Free hand recording!" << endl;
		}
		else
		{
			app.framesCount = 0;
			cout << "START Free hand recording!" << endl;
		}

		app.freeHandRecording = !app.freeHandRecording;
		break;
	case 'i':		// Create a sequence of images (.jpg)
		{

			string imageName = format_filename("output/", app.filename, app.pPath->type_get(), ".jpg");

			app.generateImages = true;

			app.pPath->current_pos_set(0);
			app.pCapture->set(CAP_PROP_POS_FRAMES, 0.0);
			app.mode = kPlayback_Mode_Record;
			cout << "Record mode" <<endl;

			cout << "filename = " << imageName << " created!" << endl;

		}
		break;
	case 'l':		// Enable/disable loop mode
		app.loopEnable = !app.loopEnable;
		cout << "loop = " << app.loopEnable << endl;
		break;
	case 'o':		// Change object shape
		switch (app.pPath->shape_get())
		{
		default:
		case kObject_Shape_Circle:
			app.pPath->shape_set(kObject_Shape_Ellipse);
			cout << "Ellipse shape" <<endl;
			break;
		case kObject_Shape_Ellipse:
			app.pPath->shape_set(kObject_Shape_Circle);
			cout << "Circle shape" <<endl;
			break;
		}
		break;
	case 'p':		// 'Playback'
		app.pPath->current_pos_set(0);
		app.pCapture->set(CAP_PROP_POS_FRAMES, 0.0);
		app.mode = kPlayback_Mode_Play;
		cout << "PLAY mode" <<endl;
		break;
	case 'r':		// Start/stop recording
		switch (app.mode)
		{
		case kPlayback_Mode_Record:
			app.folderName.clear();
			app.mode = kPlayback_Mode_Stop;
			cout << "STOP mode" <<endl;
			app.pPath->path_draw(app.src, app.pathColor, app.img);
			break;
		default:
			app.framesCount = 0;
			app.pPath->clear();
			app.mode = kPlayback_Mode_Record;
			cout << "RECORD mode" <<endl;
			break;
		}
		break;
	case 's':		// 'Stop'
		app.folderName.clear();
		app.pPath->current_pos_set(0);
		app.pCapture->set(CAP_PROP_POS_FRAMES, 0.0);
		setTrackbarPos("Frames count", app.winName, 0);
		app.mode = kPlayback_Mode_Stop;
		app.generateImages = false;
		cout << "STOP mode" <<endl;
		break;
	case ' ':		// 'Play/Stop'
		app.folderName.clear();
		switch (app.mode)
		{
		case kPlayback_Mode_Stop:
			app.mode = kPlayback_Mode_Play;
			cout << "PLAY mode" <<endl;
			break;
		case kPlayback_Mode_Play:
			app.mode = kPlayback_Mode_Stop;
			cout << "STOP mode" <<endl;
			break;
		default:
			app.mode = kPlayback_Mode_Stop;
			cout << "STOP mode" <<endl;
			break;
		}
		break;
	case 't':		// Change trajectory type
		{
			switch (app.pPath->type_get())
			{
			case kTrajectory_Type_Free:
				app.pPath->type_set(kTrajectory_Type_Circle);
				break;
			case kTrajectory_Type_Circle:
				app.pPath->type_set(kTrajectory_Type_Ellipse);
				break;
			case kTrajectory_Type_Ellipse:
				app.pPath->type_set(kTrajectory_Type_Eight);
				break;
			case kTrajectory_Type_Eight:
				app.pPath->type_set(kTrajectory_Type_Free);
				break;
			default:
				break;
			}
		}
		app.pPath->path_draw(app.src, app.pathColor, app.img);
		break;
	case 'v':		// Create a video sequence (.avi)
		{
			app.generateImages = false;

			if (app.pRecord)
				delete app.pRecord;

			string videoName = format_filename("output/", app.filename, app.pPath->type_get(), ".avi");

			// Create video recorder
			app.pRecord = new VideoWriter(videoName, VideoWriter::fourcc('D','I','V','X'), 30.0, app.size);

			usleep(10);
			if (!app.pRecord->isOpened())
			{
				delete app.pRecord;
				break;
			}
			app.pPath->current_pos_set(0);
			app.pCapture->set(CAP_PROP_POS_FRAMES, 0.0);
			app.mode = kPlayback_Mode_Record;
			cout << "Record mode" <<endl;

			cout << "filename = " << videoName << " created!" << endl;

		}
		break;
	case 'w':		// Write path to .csv file
		{
			string pathName = format_filename("output/", app.filename, app.pPath->type_get(), ".csv");

			if (!app.pPath->csv_write(pathName))
				cout << "[ERROR]: writing " << pathName << endl;
			}
		break;
	case 'x':		// Read path from .csv file
		{
			string pathName = format_filename("output/", app.filename, app.pPath->type_get(), ".csv");

			if (!app.pPath->csv_read(pathName))
				cout << "[ERROR]: reading " << pathName << endl;
		}
		break;
	case 0x1b:		// 'Esc'
		app.mode = kPlayback_Mode_Stop;
		app.exitProg = true;
		break;
	default:
		break;

	} // switch

	return(true);
} // keyboard_handler


/**
 * Retreive date and time
 * @param d OUT as yyyymmdd (i.e. 20131021)
 * @param t OUT as hhmmss (i.e. 121110)
 * @return formated date_time (i.e. "20131021_121110")
 */
string date_time_get(int& d, int& t)
{
	string dateTime;

	// Format date and time info
	time_t rawtime;
	struct tm* pTimeinfo;
	char buffer[100];
	memset(buffer, 0, 100);

	time(&rawtime);
	pTimeinfo = localtime(&rawtime);
	strftime(buffer, 100, "%Y%m%d", pTimeinfo);
	d = atoi(buffer);
	dateTime = buffer;

	memset(buffer, 0, 100);
	strftime(buffer, 100, "%H%M%S", pTimeinfo);
	t = atoi(buffer);
	dateTime += '_';
	dateTime += buffer;

	return(dateTime);
} // date_time_get


/**
 * Generate filename
 * @param path IN
 * @param src IN
 * @param type IN free, circle, ...
 * @param ext IN file extention like .jpg, .avi, ...
 * @return formated filename path/src_type.ext
 */
string format_filename(const string& path, const string& src, ETrajectory_Type type, const string& ext)
{
//	struct tm;
//	tm = getdate();

	// Format date and time info
	string dateTime;
	{
		int d = 0;
		int t = 0;
		dateTime = date_time_get(d, t);
	}

	string filename(path);
	filename += dateTime;
	filename += '_';
	size_t pos = src.find_last_of('/');
	string name;
	if (pos != string::npos)
		name = src.substr(pos+1);
	else
		name = src;

	pos = name.find_last_of('.');
	filename += name.substr(0, pos);

	switch (type)
	{
	case kTrajectory_Type_Free: filename += "_free"; break;
	case kTrajectory_Type_Circle: filename += "_circle"; break;
	case kTrajectory_Type_Ellipse: filename += "_ellipse"; break;
	case kTrajectory_Type_Eight: filename += "_eight"; break;
	default:
		break;
	}

	filename += ext;

	return(filename);
} // format_filename

