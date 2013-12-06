/**
 * @brief Constructor/destructor functions definition
 * @file ihmfootprint.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmfootprint.h"


/**
 * Constructor
 */
CIHMFootprint::CIHMFootprint(void)
{
	// Init
	footPrint1_ = Mat::zeros(100, 100, CV_8UC3);
	footPrint2_ = Mat::zeros(200, 100, CV_8UC3);
	size_ = Size(100, 100);

}


/**
 * Destructor
 */
CIHMFootprint::~CIHMFootprint(void)
{


}

