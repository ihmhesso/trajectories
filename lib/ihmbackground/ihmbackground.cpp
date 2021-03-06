/**
 * @brief Constructor/destructor functions definition
 * @file ihmbackground.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmbackground.h"


/**
 * Constructor
 */
CIHMBackground::CIHMBackground(void)
{
	paramChanged_ = false;
	pBg_ = createBackgroundSubtractorMOG2().dynamicCast<BackgroundSubtractor>();
}


/**
 * Destructor
 */
CIHMBackground::~CIHMBackground(void)
{

}

