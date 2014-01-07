/**
 * @brief Besier test function definition
 */


#include "BezierTest.h"


/**
 * Add some random Points.
 *
 * @param app IN application structure
 * @param nbrOfPoints IN number of random points to generate
 * @param img IN image matrix to get the window size
 */
void InitRandomPoints(pBezierTestApp app, int nbrOfPoints, Mat *img)
{
	// Window size
	app->rows = img->rows;
	app->cols = img->cols;

	// Add some random points in the window
	for (int i = 0; i < nbrOfPoints; i++)
		AddRandomPoint(app);
}


void AddRandomPoint(pBezierTestApp app)
{
	Point p = Point(rand() % app->cols, rand() % app->rows);
			app->fixedPoints.push_back(p);
}


/**
 * Check if a point is clicked in the given application points list.
 * The mouse click coordinate is compared to the coordinate of all points (with 10 pixels margin).
 *
 * @param app IN application structure
 * @param coord IN mouse click coordinate
 * @param x	OUT	index of the clicked point
 * @return true if a point in the list is clicked
 */
bool CheckPointClicked(pBezierTestApp app, Point coord, int *pointNumber)
{
	// Search for the first point coordinate
	for (vector<Point>::iterator it = app->fixedPoints.begin();
			it != app->fixedPoints.end(); ++it) {
		if ((abs((it->x) - coord.x) < 10) & (abs((it->y) - coord.y) < 10)) {
			*pointNumber = distance(app->fixedPoints.begin(), it); // Get index from iterator
			cout << "Point \"" << *pointNumber << "\" clicked." << endl;
			return true;
		}
	}
	return false;
}


/**
 * Move a point of the application.
 *
 * @param app IN application structure
 * @param newCoord IN the new point coordinate (must be inside the window)
 * @param pointIndex IN list index of the point to move
 * @return true if the point has been moved
 */
bool MovePoint(pBezierTestApp app, Point newCoord, unsigned int pointIndex)
{

	// Check coordinate bounds
	if ((newCoord.x < 0) || (newCoord.x >= app->cols))
		return  false;
	if ((newCoord.y < 0) || (newCoord.y >= app->rows))
		return false;

	// Check index bounds
	if(pointIndex < 0 || pointIndex > app->fixedPoints.size())
		return false;

	// Update the point coordinate
	app->fixedPoints.at(pointIndex) = newCoord;
	return true;
}

