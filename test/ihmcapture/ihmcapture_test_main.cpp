/**
 * @brief Main function definition
 * @file ihmcapture_test_main.cpp
 * @author ...
 * @date Dec 2013
 */


#include <ihmcapture.h>


/**
 * Main function
 */
int main(void)
{

	CIHMCapture capture;

	cout << capture.version_get() << endl;


	return(0);
} // main
