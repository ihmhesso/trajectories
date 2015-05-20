/**
 * @brief Draw functions definition
 * @file mispath_draw.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */


#include "mispath.h"

/**
 * Draw path
 * @param src IN source image
 * @param color IN
 * @param dst OUT result image
 * @return true if succeed
 */
bool CMISPath::path_draw(const Mat& src, Scalar color, Mat& dst)
{

	// Check parameter
	if (src.empty())
		return(false);

	src.copyTo(dst);

	if (style_ == kDrawing_Style_Off)
		return(true);

	Scalar blue(255, 0, 0);
	Scalar green(0, 255, 0);
	Scalar red(0, 0, 255);
	int radius = 4;
	int count = path_.size();

	//Highlight the first and last point
	circle(dst, path_[0].p, radius, green, FILLED);
	circle(dst, path_[count-1].p, radius, red, FILLED);

	switch (style_)
	{
	case kDrawing_Style_Point:
		for (int i = 1; i < count-1; ++i)
			circle(dst, path_[i].p, radius, color, FILLED);
		break;
	case kDrawing_Style_Line:
		for (int i = 0; i < count-1; ++i)
			line(dst, path_[i].p, path_[i+1].p, color, 1);
		break;
	default:
		break;
	}

	return(true);
} // path_draw


/**
 * Draw position
 * @param src IN source image
 * @param color IN
 * @param size IN object size [pixel]
 * @param dst OUT result image
 * @return true if succeed
 */
bool CMISPath::position_draw(const Mat& src, Scalar color, int size, Mat& dst)
{
	// Check parameter
	if (src.empty())
		return(false);

	src.copyTo(dst);

	switch (objShape_)
	{
	default:
	case kObject_Shape_Circle:
		circle(dst, path_[currentPos_].p, size, color, FILLED);
		break;
	case kObject_Shape_Ellipse:
		{
			Size axes(size, size/2);	// with = major axis, width = minor axis
			Point p1 = path_[currentPos_].p;
			Point p2 = path_[currentPos_-1].p;
			double rad = atan((double)(p1.y-p2.y)/(double)(p1.x-p2.x));	// Rotation angle [rad]
			double rotation = rad*(180.0/(double)CV_PI);	// Rotation angle [degree]
//DEBUG
//			cout << "rotation = " << rotation << endl;
			ellipse(dst, path_[currentPos_].p, axes, rotation, 0.0, 360.0, color, FILLED);
		}
		break;
	}

	return(true);
} // position_draw


#ifdef kCMISPath_GNUPLOT_ENABLE
#include "gnuplot_i.hpp"
#endif


/**
 * Generate (using gnuplot) and error graph
 * @param path2 IN
 * @param fileName IN
 * @return true if succeed
 */
bool CMISPath::errors_graph_generate(const CMISPath& path2, string fileName)
{

	bool result = false;

#ifdef kCMISPath_GNUPLOT_ENABLE

	// Generate data file
	string dataName("gnuplot.dat");

	ofstream file;
	// Setup exception mask
	file.exceptions(ofstream::failbit | ofstream::badbit);

	// Open or create file
	try
	{
		file.open(dataName.c_str());
		if (!file.is_open())
		{
			cout << "Can't open " << dataName << " file" << endl;
			return(false);
		}

		int l2Start = 0;
		Vec3d distRef = euclidean_distance(path2, 0);
		for (int i = 1; i < 30; ++i)
		{
			Vec3d dist = euclidean_distance(path2, i);
			if (dist[1] < distRef[1])
			{
				l2Start = i;
				cout << "l2Start = " << l2Start << endl;
			}
		}

		vector<PathData> list2;
		path2.list_get(list2);

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
			file << i << " " << d << endl;
		}

		file.close();
	}
	catch (ofstream::failure& e)
	{
		cerr << "Exception opening/reading file " << dataName << endl;
		return(false);
	}

	// Generate graphic
	try
	{
		string cmdTxt("set output '");
		cmdTxt += fileName;
		cmdTxt += "'";

		Gnuplot gp("lines");
		gp.cmd("set title 'Errors Graph'");
		gp.cmd("set style data linespoints");
		gp.cmd("set term png size 800, 600");
		gp.cmd(cmdTxt);
		gp.cmd("plot 'gnuplot.dat'");
		result = true;
	}
	catch (GnuplotException& ge)
	{
		cout << ge.what() << endl;
	}

#endif // kCMISPath_GNUPLOT_ENABLE

	return(result);
} // errors_graph_generate

