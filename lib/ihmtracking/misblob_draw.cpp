/**
 * @brief Draw Functions
 * @file misblob_draw.cpp
 * @author gregory.medwed@heig-vd.ch
 * @file Dec. 2013
 */


#include "misblob.h"


/**
 * Draw blob box
 * @param img OUT
 * @param id IN blob id
 * @param color IN
 * @return true when done
 */
bool CMISBlob::box(Mat& img, int id, Scalar color)
{
	// Check parameters
	if (img.empty())
		return(false);

	if (blobsList[id].data.empty())
		return(true);	// Nothing to draw

	int pointsCount = (int)blobsList[id].data.size();
	if (pointsCount == 0)
		return(true);	// Nothing to draw

	// Draw rectangle
	BlobData data = blobsList[id].data.back();
	rectangle(img, data.roi, color, 2, 8, 0);

	// Write Blob id
	char text[32];

	memset(text, 0, 32);

	sprintf(&text[strlen(text)], "%d", id);

	putText(img, text,
		data.roi.tl(),	// Origine
		FONT_HERSHEY_PLAIN,
		1,
		color,
		1,
		LINE_AA);

	return(true);
} // box


#if 0
/**
 * Draw blob trajectory
 * @param img OUT
 * @param id IN blob id
 * @param color IN
 * @return true when done
 */
bool CMISBlob::trajectory(Mat& img, int id, Scalar color)
{
	// Check parameters
	if (img.empty())
		return(false);

	if (blobsList[id].data.empty())
		return(true);	// Nothing to draw

	int pointsCount = blobsList[id].data.size();
	if (pointsCount == 0)
		return(true);	// Nothing to draw


	// Parse all blob possitions
	for (int i = 0; i < pointsCount; ++i)
	{
		Point floorPOC = floor_contact_get(blobsList[id].data.at(i));

		if (floorPOC.x < 0)
			floorPOC.x = 0;
		else if (floorPOC.x > img.cols-1)
			floorPOC.x = img.cols-1;

		if (floorPOC.y < 0)
			floorPOC.y = 0;
		else if (floorPOC.y > img.rows-1)
			floorPOC.y = img.rows-1;

		circle(img, floorPOC, 1, color, -1); 	
	}

	return(true);
} // trajectory
#endif

