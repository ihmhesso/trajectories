/**
 * @brief Path functions definition
 * @file mispath_path.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */


#include "mispath.h"


/**
 * Get path
 * @param path OUT list of points
 * @return true when done
 */
bool CMISPath::list_get(vector<PathData>& path) const
{
	path = path_;
	return(true);
}


/**
 * Add a new point to the path
 * @param frameCount IN
 * @param p IN
 * @return true when done
 */
bool CMISPath::point_add(int frameCount, Point p)
{
	PathData data;
	data.frameCount = frameCount;
	data.p = p;

	path_.push_back(data);
	return(true);
}


/**
 * Get current position in the list
 * @return current position
 */
int CMISPath::current_pos_get(void) const
{
	return(currentPos_);
}


/**
 * Set current position
 * @param pos IN
 */
bool CMISPath::current_pos_set(int pos)
{
	if ((pos < 0) || (pos > (int)path_.size()))
		return(false);

	currentPos_ = pos;
	return(true);
}

/**
 * Inc current position (+ or -)
 * @param step IN default = 1
 * @param loop IN default = false
 * @return true when done
 */
bool CMISPath::current_pos_inc(int step, bool loop)
{
	if (step < 0)
	{
		if ((currentPos_-step) < 0)
			currentPos_ = 0;
		else
			currentPos_ += step;

	}
	else if (step > 0)
	{
		int count = (int)path_.size();
		if ((currentPos_+step) > count-1)
		{
			if (loop)
				currentPos_ = 0;
			else
				currentPos_ = count-1;
		}
		else
		{
			currentPos_ += step;
		}
	}
	else
	{
		currentPos_ += step;
	}

//DEBUG:
//	cout << "step = " << step << ", currentPos_ = " << currentPos_ << endl;
	return(true);
} // current_pos_inc


/**
 * Compare operator ==, friend
 * @param lhs IN
 * @param rhs IN
 * @return true if identical
 */
bool operator==(const CMISPath& lhs, const CMISPath& rhs)
{
	int count1 = lhs.path_.size();
	int count2 = rhs.path_.size();

	if (count1 != count2)
		return(false);

	for (int i = 0; i < count1; ++i)
	{
		if (lhs.path_[i].p != rhs.path_[i].p)
			return(false);
	}

	return(true);
} // operator==
