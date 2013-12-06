/**
 * @brief Update blob position and images functions
 * @file misblob_update.cpp
 */


#include "misblob.h"



#if 0
/**
 * Update an existing blob position and images
 * @param blob OUT
 * @param frameCount IN
 * @param blobRect IN
 * @param fgClean IN
 * @param fgColor IN
 * @return true if succeed
 */
bool CMISBlob::update(MISBlobObject& blob, int frameCount, Rect& blobRect, const Mat& fgClean, const Mat& fgColor)
{
	
	MISBlobData data;
	data_set(data, frameCount, blobRect);

	// Update shape blob image (normalized 200 px height)
	extract_blob_image(fgClean, blobRect, blob.shapeImg);

	// Update color blob image (normalized 200 px height)
	extract_blob_image(fgColor, blobRect, blob.colorImg);

	blob.data.push_back(data);

	return(true);
} // update

#endif

