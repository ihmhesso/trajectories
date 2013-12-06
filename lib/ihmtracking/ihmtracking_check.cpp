/**
 * @brief Check functions
 * @file ihmtracking_check.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date Dec. 2013
 */


#include "ihmtracking.h"

/**
 * Detect if the position is in rage of a blob
 * @param frameNumber IN
 * @param lastData IN
 * @param currentPos IN
 * @param maxDistance IN
 * @return true if current position is in range and not to old (in number of frame)
 */
bool CIHMTracking::detect_position_in_range(int frameNumber, CMISBlob::BlobData lastData,
	Rect currentPos, int maxDistance)
{
	bool inRange = false;
	int deltaFrame = frameNumber-lastData.frameNumber;

	if (deltaFrame < kCIHMTracking_DELTA_FRAME_IN_RANGE_MAX)
	{
		Rect dRect(0, 0, 0, 0);

		// compute distances delta [pixel]
		dRect = Rect_delta(lastData.roi, currentPos);

		// Check if position is close to an existing Blob
		if ((dRect.x < maxDistance) && (dRect.y < maxDistance))
			inRange = true;
	}

	return(inRange);
} // detect_position_in_range


/**
 * Check for new Blob in the picture (+update current Blob list)
 * @param img IN current image
 * @param frameCount IN 
 * @param fgClean IN foreground
 * @param fgColor IN foreground
 * @param currentList OUT current Blobs list
 * @return positive value corresponding to added Blobs, or negative values for removed Blobs
 */
int CIHMTracking::check(const Mat& img, int frameCount, const Mat& fgClean,
	const Mat& fgColor, CMISBlob& currentList)
{
	int totalNew = 0;

	//TODO:

	return (totalNew);
} // check


