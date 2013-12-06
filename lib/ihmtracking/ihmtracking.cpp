/**
 * @brief Constructor/destructor functions definition
 * @file ihmtracking.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmtracking.h"


/**
 * Constructor
 */
CIHMTracking::CIHMTracking(void)
{
	minSize_ = kCIHMTracking_MINIMUM_SIZE;
	maxDistance_ = kCIHMTracking_MAXIMUM_DISTANCE;
}


/**
 * Destructor
 */
CIHMTracking::~CIHMTracking(void)
{

}

