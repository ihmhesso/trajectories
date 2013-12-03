/**
 * @brief Mouse functions definition
 * @file pathsimulator_mouse.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */

#include "pathsimulator.h"

/*
 * Callback prototype
 */
// void Foo(int event, int x, int y, int flags, void* pUserData);


/**
 * Mouse callback
 * @param event IN
 * @param x IN
 * @param y IN
 * @param flags IN
 * @param pUserData OUT by default set to 0
 */
void mouse_callback(int event, int x, int y, int flags, void* pUserData)
{

	pApplicationData pApp = (pApplicationData)pUserData;

	switch (event)
	{
	case EVENT_MOUSEMOVE:
		pApp->mouseCoord = Point(x,y);
		break;
	default:
		break;
	}

} // mouse_callback
