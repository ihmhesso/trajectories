#include "BezierTest.h"

bool isPointClicked = false;// true if the user clicked on a point and hold the left button
int pointIndex; // Index of the clicked point

/**
 * Mouse event callback
 * @param event IN CV_EVENT_...
 * @param x IN coordonate
 * @param y IN coordonate
 * @param flags IN
 * @param *param OUT
 */
void mouse_callback(int event, int x, int y, int flags, void *param)
{
	pBezierTestApp app = (pBezierTestApp)param;

	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		// Check if the mouse click is on a point
		isPointClicked = CheckPointClicked(app, Point(x, y), &pointIndex);
		break;
	case CV_EVENT_LBUTTONUP:
		isPointClicked = false;
		break;
	case CV_EVENT_MOUSEMOVE:
		if (isPointClicked) {
			Point p(x, y); // Current cursor position
			MovePoint(app, p, pointIndex);	// Update the point coordinate
		}
		break;
	default:
		break;
	}

} // mouse_callback


/**
 * Check if a point is clicked
 * @return true if a point is clicked
 */
bool ClickedPoint(void)
{
	return isPointClicked;
} // ClickedPoint
