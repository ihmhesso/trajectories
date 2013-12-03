/**
 * @brief Debug functions definition
 * @file mispath_debug.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */


#include "mispath.h"


/**
 * Print class info
 * @param out OUT
 * @param path IN
 * @return text as output stream
 */
ostream& operator<<(ostream& out, const CMISPath& path)
{
	out << "type_: " << path.type_ << endl;
	out << "size_: " << path.size_ << endl;
	out << "pointsCount_: " << path.pointsCount_ << endl;
	out << "style_: " << path.style_ << endl;
	out << "currentPos_: " << path.currentPos_ << endl;

	out << "(" << path.path_[0].frameCount << ", " << path.path_[0].p << ")" << endl;
	int count = (int)path.path_.size();
	for (int i = 1; i < count; ++i)
	{
		out << "(" << path.path_[i].frameCount << ", " << path.path_[i].p << ")" << endl;;
	}

	out << endl;

	return(out);
} // operator<<


/**
 * Print type info
 * @return type as text
 */
string CMISPath::type_print(void) const
{
	string txt;

	switch (type_)
	{
	case kTrajectory_Type_Free: txt = "Free"; break;
	case kTrajectory_Type_Circle: txt = "Circle"; break;
	case kTrajectory_Type_Ellipse: txt = "Ellipse"; break;
	case kTrajectory_Type_Eight: txt = "Eight"; break;
	default: txt = "Unknown"; break;
	}

	return(txt);
} // operator<<
