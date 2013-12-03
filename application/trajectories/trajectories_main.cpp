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

	CIHMCapture capture;

	cout << capture.version_get() << endl;


	return(0);
} // main
