/**
 * @brief Class header file
 * @file mispath.h
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */
#ifndef _MIS_PATH_H_
#define _MIS_PATH_H_


#include <iostream>
#include <vector>
#include <cmath>	// sin(), cos()
#include <sstream>	// stringstream
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#define kCMISPath_MAJOR_VERSION		(0)
#define kCMISPath_MINOR_VERSION		(7)
#define kCMISPath_PATCH_VERSION		(0)

/*
 * Comment this line to disable gnuplot
 * WARNING: requires gnuplot to be installed see:
 * http://www.gnuplot.info
 */
#define kCMISPath_GNUPLOT_ENABLE


using namespace std;
using namespace cv;


/**
 * Trajectory type enumeration
 */
typedef enum _ETrajectory_Type
{
	kTrajectory_Type_Free = 0,	/** Use mouse to draw trajectory */
	kTrajectory_Type_Circle,	/** Circle predefine trajectory */
	kTrajectory_Type_Ellipse,	/** Elliptic predefine trajectory */
	kTrajectory_Type_Eight,	/** Eight shape predefine trajectory */
	kTrajectory_Type_Max		/** MUST BE LAST */
} ETrajectory_Type;


/**
 * Drawing style enumeration
 */
typedef enum _EDrawing_Style
{
	kDrawing_Style_Off = 0,	/** Default */
	kDrawing_Style_Point,	/** points */
	kDrawing_Style_Line,	/** Lines between points */
	kDrawing_Style_Max		/** MUST BE LAST */
} EDrawing_Style;



/**
 * Object shape (circle, ellipse, rectangle) enumeration
 */
typedef enum _EObject_Shape
{
	kObject_Shape_Circle = 0,	/** Default */
	kObject_Shape_Ellipse,		/** Ellipse (varying orientation according to path)*/
//	kObject_Shape_Rectangle,	/** Rectangle (varying orientation according to path) */
	kObject_Shape_Max			/** MUST BE LAST */
} EObject_Shape;


/**
 * Path class
 */
class CMISPath
{
public:
	/*
	 * PUBLIC variables
	 */
	typedef struct PathData
	{
		int frameCount;
		Point p;
	} PathData, *pPathData;

	/*
	 * PUBLIC functions
	 */
	// Constructor/destructor
	CMISPath(ETrajectory_Type type=kTrajectory_Type_Circle, Size size=Size(200,200), int pointsCount=100);
	~CMISPath(void);

	// Get/set
	string version_get(int& ma, int& mi, int& pa) const;
	EDrawing_Style style_get(void) const;
	bool style_set(EDrawing_Style style);
	Size  size_get(void) const;
	bool size_set(Size size);
	int  points_count_get(void) const;
	bool points_count_set(int value);
	ETrajectory_Type type_get(void) const;
	bool type_set(ETrajectory_Type type);
	EObject_Shape shape_get(void);
	bool shape_set(EObject_Shape shape);


	// Path get/set
	bool list_get(vector<PathData>& path) const;
	bool point_add(int frameCount, Point p);
	int  current_pos_get(void) const;
	bool current_pos_set(int pos);
	bool current_pos_inc(int step=1, bool loop=false);
	bool clear(void);
	double distance_get(void) const;
	bool speed_get(double& avg, double& max) const;
	bool csv_write(const string& filename) const;
	bool csv_read(const string& filename);
	friend bool operator==(const CMISPath& lhs, const CMISPath& rhs);
	Vec3d euclidean_distance(const CMISPath& path1, const CMISPath& path2);
	Vec3d euclidean_distance(const CMISPath& path2);
	Vec3d euclidean_distance(const CMISPath& path2, int startPos);

	// Draw
	bool path_draw(const Mat& src, Scalar color, Mat& dst);
	bool position_draw(const Mat& src, Scalar color, int size, Mat& dst);
	bool errors_graph_generate(const CMISPath& path2, string fileName);

	// Debug
	friend ostream& operator<<(ostream& out, const CMISPath& path);
	string type_print(void) const;


private:
	/*
	 * PRIVATE variables
	 */
	ETrajectory_Type type_;	/** Path type (free, circle, rectangle) */
	Size size_;				/** Area size (200, 200) [Pixel] */
	int pointsCount_;		/** Max path points, default = 100 */
	vector<PathData> path_;	/** List of points */
	EDrawing_Style style_;	/** Drawing style (points, lines) */
	int currentPos_;		/** Current position in the list of points */
	EObject_Shape objShape_;/** Object shape */

	/*
	 * PRIVATE functions
	 */
	void path_init(vector<PathData>& path);
	Point circle_equation(int radius, double angle);
	Point ellipse_equation(int a, int b, double angle);
	Point eight_equation(int width, int height, double angle);
	int best_start_pos_find(const vector<PathData>& list1, const vector<PathData>& list2);


}; // CMISPath

#endif //_MIS_PATH_H_
