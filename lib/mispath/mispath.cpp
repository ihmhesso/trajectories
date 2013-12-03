/**
 * @brief Constructor/destructor functions definition
 * @file mispath.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */


#include "mispath.h"


/**
 * Constructor
 * @param type IN default = kETrajectory_Type_Circle
 * @param size IN default = Size(200,200)
 * @param pointsCount IN default = 100
 */
CMISPath::CMISPath(ETrajectory_Type type, Size size, int pointsCount)
	: type_(type), size_(size), pointsCount_(pointsCount)
{
	style_ = kDrawing_Style_Off;
	currentPos_ = 0;
	objShape_ = kObject_Shape_Circle;

	if ((type_ == kTrajectory_Type_Circle) ||
			(type_ == kTrajectory_Type_Ellipse) ||
			(type_ == kTrajectory_Type_Eight))
		path_init(path_);
}


/**
 * Destructor
 */
CMISPath::~CMISPath(void)
{

}
