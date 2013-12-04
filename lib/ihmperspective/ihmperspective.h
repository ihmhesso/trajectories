/**
 * @brief Class header file
 * @file ihmperspective.h
 * @author ...
 * @date Dec 2013
 */
#ifndef _IHM_PERSPECTIVE_H_
#define _IHM_PERSPECTIVE_H_

#include <iostream>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#define kCIHMPerspective_VERSION_MAJOR_NUMBER	(0)
#define kCIHMPerspective_VERSION_MINOR_NUMBER	(1)
#define kCIHMPerspective_VERSION_PATCH_NUMBER	(0)


using namespace std;
using namespace cv;


/**
 * CIHMPerspective Class 
 */
class CIHMPerspective
{
public:
	/*
	 * PUBLIC Functions
	 */
	// Constructor/destructor
	CIHMPerspective(void);
	~CIHMPerspective(void);

	// Get/set
	string version_get(void) const;


	// Debug
	friend ostream& operator<<(ostream& out, const CIHMPerspective& persp);

private:
	/*
	 * PRIVATE Objects
	 */
	

}; // CIHMPerspective


#endif // _IHM_PERSPECTIVE_H_
