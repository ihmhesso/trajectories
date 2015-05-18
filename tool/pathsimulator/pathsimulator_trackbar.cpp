/**
 * @brief Trackbar callbacks functions definition
 * @file pathsimulator_trackbar.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */

#include "pathsimulator.h"

/*
 * Callback prototype
 */
// void Foo(int,void*);


/**
 * Points Count trackbar callback
 * @param value IN new value
 * @param pUserData OUT
 */
void pointsCount_has_changed(int value, void* pUserData)
{
	pApplicationData pApp = (pApplicationData)pUserData;

	// Minimum value limit
	if (value < 1)
	{
		pApp->pointsCount = 1;
		setTrackbarPos("Points count", pApp->winName, pApp->pointsCount);
	}

	// Update value
	pApp->pPath->points_count_set(pApp->pointsCount);
	pApp->pPath->path_draw(pApp->src, pApp->pathColor, pApp->img);

} // pointsCount_has_changed


/**
 * Frames Count trackbar callback
 * @param value IN new value
 * @param pUserData OUT
 */
void framesCount_has_changed(int value, void* pUserData)
{
	pApplicationData pApp = (pApplicationData)pUserData;

	pApp->framesCount = value;
	setTrackbarPos("Frames count", pApp->winName, pApp->framesCount);

	pApp->pCapture->set(CAP_PROP_POS_FRAMES, (double)pApp->framesCount);

} // framesCount_has_changed
