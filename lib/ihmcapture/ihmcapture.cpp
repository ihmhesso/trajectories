/**
 * @brief Constructor/destructor functions definition
 * @file ihmcapture.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmcapture.h"


/**
 * Constructor
 */
CIHMCapture::CIHMCapture(void)
{
	CaptureParam_init(param_);
}


/**
 * Destructor
 */
CIHMCapture::~CIHMCapture(void)
{

	// Terminate thread
	close();

} // ~CIHMCapture

