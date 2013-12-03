/**
 * @brief Compute functions definition
 * @file mispath_compute.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */

#include "mispath.h"


/**
 * Retreive every point on a circle
 * @param radius IN [pixel]
 * @param angle IN [radian]
 */
Point CMISPath::circle_equation(int radius, double angle)
{
	Point p(0, 0);
	Point center = Point(size_.width/2, size_.height/2);

	p.x = radius*cos(angle)+center.x;
	p.y = radius*sin(angle)+center.y;

	return(p);
} // circle_equation


/**
 * Retreive every point on an ellipse
 * @param a IN semi major axis [pixel]
 * @param b IN semi minor axis [pixel]
 * @param angle IN [radian]
 */
Point CMISPath::ellipse_equation(int a, int b, double angle)
{
	Point p(0, 0);
	Point center = Point(size_.width/2, size_.height/2);

	p.x = (double)a*cos(angle)+center.x;
	p.y = (double)b*sin(angle)+center.y;

	return(p);
} // ellipse_equation


/**
 * Retreive every point on an eight shape
 * @param width IN [pixel]
 * @param height IN [pixel]
 * @param angle IN [radian]
 */
Point CMISPath::eight_equation(int width, int height, double angle)
{
	Point p(0, 0);
	Point center = Point(size_.width/2, size_.height/2);

	p.x = (double)width*sin(angle)+center.x;
	p.y = (double)height*sin(2.0*angle)+center.y;

	return(p);
} // eight_equation


/**
 * Find best start position in path
 * @param list1 IN
 * @param list2 IN
 * @return best position
 */
int CMISPath::best_start_pos_find(const vector<PathData>& list1, const vector<PathData>& list2)
{
	int bestStart = 0;
	double dist = 0.0;
	double distMin = 1000.0;

	// Compare points
	int count = (int)list2.size();

	for (int i = 0; i < count; ++i)
	{
		dist = norm(Mat(list1[0].p), Mat(list2[i].p));
		if (dist < distMin)
		{
			distMin = dist;
			bestStart = i;
		}
	}

	cout << "bestStart = " << bestStart << endl;

	return(bestStart);
} // start_position_find



/**
 * Measure Euclidean distance between two path
 * @param path1 IN
 * @param path2 IN
 * @return euclidean distance [min, average, max]
 */
Vec3d CMISPath::euclidean_distance(const CMISPath& path1, const CMISPath& path2)
{
	Vec3d dist(1000.0, 0.0, 0.0);

	vector<PathData> list1;
	vector<PathData> list2;
	path1.list_get(list1);
	path2.list_get(list2);

	// Find the best point to start
	int l2Start = best_start_pos_find(list1, list2);

	int count1 = list1.size();
	int count2 = list2.size();
	int count = 0;

	if (count1 > count2)
		count = count2-l2Start;
	else
		count = count1;

	// Compare points
	for (int i = 0, j = l2Start; i < count; ++i, ++j)
	{
		double d = norm(Mat(list1[i].p), Mat(list2[j].p));
		dist[1] += d;
		if (d < dist[0])
			dist[0] = d;

		if (d > dist[2])
			dist[2] = d;
	}

	dist[1] /= count;

	//Debug
		cout << count << " points compare" << endl;
	return(dist);
} // euclidean_distance


/**
 * Measure Euclidean distance between two path
 * @param path2 IN
 * @return euclidean distances [min, average, max]
 */
Vec3d CMISPath::euclidean_distance(const CMISPath& path2)
{
	Vec3d dist(0.0, 0.0, 0.0);

	vector<PathData> list2;
	path2.list_get(list2);

	// Find the best point to start
	int l2Start = best_start_pos_find(path_, list2);

	int count1 = path_.size();
	int count2 = list2.size();
	int count = 0;

	if (count1 > count2)
		count = count2-l2Start;
	else
		count = count1;

	// Compare points
	for (int i = 0, j = l2Start; i < count; ++i, ++j)
	{
		double d = norm(Mat(path_[i].p), Mat(list2[j].p));
		dist[1] += d;
		if (d < dist[0])
			dist[0] = d;

		if (d > dist[2])
			dist[2] = d;
	}

	dist[1] /= count;

//Debug
	cout << count << " points compare" << endl;
	return(dist);
} // euclidean_distance


/**
 * Measure Euclidean distance between two path
 * @param path2 IN
 * @param startPos IN
 * @return euclidean distances [min, average, max]
 */
Vec3d CMISPath::euclidean_distance(const CMISPath& path2, int startPos)
{
	Vec3d dist(0.0, 0.0, 0.0);

	vector<PathData> list2;
	path2.list_get(list2);

	int count1 = path_.size();
	int count2 = list2.size();
	int count = 0;

	if (count1 > count2)
		count = count2-startPos;
	else
		count = count1;

	// Compare points
	for (int i = 0, j = startPos; i < count; ++i, ++j)
	{
		double d = norm(Mat(path_[i].p), Mat(list2[j].p));
		dist[1] += d;
		if (d < dist[0])
			dist[0] = d;

		if (d > dist[2])
			dist[2] = d;
	}

	dist[1] /= count;

//Debug
	cout << count << " points compare" << endl;
	return(dist);
} // euclidean_distance

