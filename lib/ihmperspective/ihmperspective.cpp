/**
 * @brief Constructor/destructor functions definition
 * @file ihmperspective.cpp
 * @author ...
 * @date Dec 2013
 */


#include "ihmperspective.h"


/**
 * Constructor
 * @param coordCount IN default = 4
 */
CIHMPerspective::CIHMPerspective(int coordCount)
{
	// Check parameter
	if ((coordCount < 3) || (coordCount > 4))
	{
		coordCount_ = 4;
		cout << "coordCount invalide, force to 4!" << endl;
	}

	// Init
	for( int i = 0 ; i < 4 ; i++)
	{
		srcPoints_[i] = Point2f(0.0, 0.0);
		dstPoints_[i] = Point2f(0.0, 0.0);
	}

	perspMartixCompute_ = false;
	perspInvMartixCompute_ = false;

}


/**
 * Destructor
 */
CIHMPerspective::~CIHMPerspective(void)
{

}

