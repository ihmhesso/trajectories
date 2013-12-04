/**
 * @brief Main function definition
 * @file trajectories_main.cpp
 * @author ...
 * @date Dec 2013
 */


#include "trajectories.h"


/**
 * Main function
 * @param argc IN
 * @param argv IN
 * @return always 0
 */
int main(int argc, char* argv[])
{
	/*
	 * [CREATE] variable/objects
	 */
	ApplicationParam app;


	/*
	 * [INIT]
	 */
	app.exitProgram = true;




//DEBUG:
	cout << "Library used:" << endl;
	cout << app.bg;
	cout << app.capture;
	cout << app.persp;
	cout << app.record;
	cout << app.track;
	cout << app.path;
	cout << app.footPrint;
	cout << endl;


	/*
	 * [GUI] init
	 */



	/*
	 * [MAIN] loop
	 */
	int key = 0;
	do
	{

		/*
		 * 1. Retreive new image from device
		 */

		/*
		 * 2. Perspective transformation
		 */

		/*
		 * 3. Background substraction
		 */

		/*
		 * 4. Blob tracking
		 */

		/*
		 * 5. Store blob position
		 */

		/*
		 * 6. Compute trajectory
		 */

		/*
		 * 7. Draw foot print
		 */


	} while (!app.exitProgram);


	/*
	 * [RESSOURCE] free
	 */
//	destroyAllWindows();	


	return(0);
} // main

