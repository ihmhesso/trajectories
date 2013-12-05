/**
 * @brief Arguments function definition
 * @file ihmcapture_test_args.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date Dec. 2013
 */

#include "ihmcapture_test.h"


/**
 * Print help
 */
void help_print(void)
{
	cout << "USAGE: ihmcapture_test [OPTION]" << endl,
	cout << "OPTIONS:" << endl;
	cout << "  -h, --help              Print this message" << endl;
	cout << "  -d, --device <id>       Open device id" << endl;
	cout << "  -v, --video  <fileName> Open video file" << endl; 
//	cout << "  -i, --ip <ipAddr>       Open Ethernet stream" << endl; 

	cout << "Report bug to <mis@heig-vd.ch>" << endl;
}



/**
 * Check command line arguments
 * @param argc IN
 * @param argv IN
 * @param app OUT
 * @return true if arguments are valid
 */
bool args_check(int argc, char* argv[], ApplicationParam& app)
{
	bool result = false;

// DEBUG:
	cout << "Parameters:";
	for (int i = 1; i < argc; ++i)
		cout << " " << argv[i];

	cout << endl;

	// Parse all arguments, look for [OPTIONS]
	for (int i = 1; i < argc; ++i)
	{
		/* -h, --help */
		if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0))
		{
			help_print();
		}
		/* -d, --device */
		else if ((strcmp(argv[i], "-d") == 0) || (strcmp(argv[i], "--device") == 0))
		{
			i++;
			app.devId = atoi(argv[i]);
			app.capture.type_set(CIHMCapture::kType_USB_Device);
			result = true;
		}
		/* -v, --video */
		else if ((strcmp(argv[i], "-v") == 0) || (strcmp(argv[i], "--video") == 0))
		{
			i++;
			app.videoName = argv[i];
			app.capture.type_set(CIHMCapture::kType_Video_File);
			result = true;
		}

	}


	return(result);
} // args_check

