/**
 * @brief Arguments functions definition
 * @file pathsimulator_args.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */


#include "pathsimulator.h"


/**
 * Print help menu
 */
void help_print(void)
{
	cout << "Usage: pathsimulator [OPTIONS]" << endl;
	cout << "OPTIONS:" << endl;
	cout << "   -c, --color <COLOR>     Select object/bg color: bw (black dot over white) or wb (default)" << endl;
	cout << "   -h, --help              Print this help and exit" << endl;
	cout << "   -i, --image <FILENAME>  Load image FILENAME as background" << endl;
	cout << "   -l, --Loop              Enable playback loop mode" << endl;
	cout << "   -s, --size <SIZE>       Set area size (default 800x600) [pixel]" << endl;
	cout << "   -v, --video <FILENAME>  Load video FILENAME as background" << endl;

	cout << "Report " << kPATH_SIMULATOR_PROGRAM_NAME << " bugs to mis@heig-vd.ch" << endl;
} // help_print


/**
 * Check arguments pass from command line
 * @param argc IN
 * @param argv IN
 * @param app OUT
 * @return true if succeed
 */
bool args_check(int argc, char* argv[], ApplicationData& app)
{
	bool result = true;
	Scalar black(0, 0, 0);
	Scalar white(255, 255, 255);

	cout << kPATH_SIMULATOR_PROGRAM_NAME << " program version ";
	cout << kPATH_SIMULATOR_VERSION_MAJOR << ".";
	cout << kPATH_SIMULATOR_VERSION_MINOR << ".";
	cout << kPATH_SIMULATOR_VERSION_PATCH << endl;

	// Print all args
	cout << "parameters: ";
	for (int i = 1; i < argc; ++i)
		cout << argv[i] << " ";
	cout << endl;

	for (int i = 1; i < argc; ++i)
	{
		// Display help
		if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0))
		{
			help_print();
			result = false;
			break; // exit for
		}
		// Select object/background colors
		else if ((strcmp(argv[i], "-c") == 0) || (strcmp(argv[i], "--color") == 0))
		{
			i++;
			if ((strcmp(argv[i], "bw") == 0) || (strcmp(argv[i], "BW") == 0))
			{
				app.objColor = black;
				app.bgColor = white;
				app.src = Mat::zeros(app.size, CV_8UC3);
				app.src.setTo(white);
			}
			else if ((strcmp(argv[i], "wb") == 0) || (strcmp(argv[i], "WB") == 0))
			{
				app.objColor = white;
				app.bgColor = black;
			}
			result = true;
		} // --color
		// Enable playback in loop
		else if ((strcmp(argv[i], "-l") == 0) || (strcmp(argv[i], "--loop") == 0))
		{
			app.loopEnable = true;
			result = true;
		} // --loop
		// Set image size
		else if ((strcmp(argv[i], "-s") == 0) || (strcmp(argv[i], "--size") == 0))
		{
			i++;
			string size(argv[i]);

			for (int j=0; j < (int)size.length(); ++j)
				size[j] = tolower(size[j]);

			size_t pos = size.find("x");
			if ((pos != string::npos))
			{
				string width;
				string height;
				width = size.substr(0, pos);
				height = size.substr(pos+1);
//DEBUG:
//				cout << "width = " << width << ", height = " << height << endl;

				// transform string to int
				Size sz(atoi(width.c_str()), atoi(height.c_str()));
				if (sz != app.size)
				{
					app.size = sz;
					resize(app.src, app.src, app.size);
				}

				result = true;
			}
		} // --size
		// Load an image as background
		else if ((strcmp(argv[i], "-i") == 0) || (strcmp(argv[i], "--image") == 0))
		{
			i++;
			string filename(argv[i]);

			for (int j=0; j < (int)filename.length(); ++j)
				filename[j] = tolower(filename[j]);

			if ((filename.find(".jpg") != string::npos) ||
					(filename.find(".jpeg") != string::npos) ||
					(filename.find(".png") != string::npos))
			{
				app.filename = argv[i];
				cout << "filename = " << app.filename << endl;
				app.src = imread(app.filename);

				//TODO: should resize image according to app.size
				//FIXME: OK for now!
				app.size = app.src.size();

				result = true;
			}
		} // --image
		// Load a video as background
		else if ((strcmp(argv[i], "-v") == 0) || (strcmp(argv[i], "--video") == 0))
		{
			i++;
			string filename(argv[i]);

			for (int j=0; j < (int)filename.length(); ++j)
				filename[j] = tolower(filename[j]);

			if (filename.find(".avi") != string::npos)
			{
				app.filename = argv[i];

				app.pCapture = new VideoCapture(app.filename);
				usleep(10);

				if (!app.pCapture->isOpened())
				{
					delete app.pCapture;
					break;
				}

				app.maxFrame = (int)app.pCapture->get(CAP_PROP_FRAME_COUNT);
				cout << "filename = " << app.filename << "(" << app.maxFrame << ")" << endl;

				// Read first image
				app.pCapture->read(app.src);

				//TODO: should resize image according to app.size
				//FIXME: OK for now!
				app.size = app.src.size();

				result = true;
			}
		} // --video

	}

	return(result);
} // args_check
