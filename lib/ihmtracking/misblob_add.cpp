/**
 * @brief Add/remove functions definition
 * @file misblob_add.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date Dec. 2013
 */


#include "misblob.h"


#if 0
/**
 * Extract blob image
 * @param fgImg IN
 * @param blobRect OUT
 * @param blobImg OUT
 * @return true if succeed
 */
bool CMISBlob::extract_blob_image(const Mat& fgImg, Rect& blobRect, Mat& blobImg)
{
	// Check parameters
	if (fgImg.empty())
		return(false);

	// Update shape blob image (normalized 200 px height)
	Mat tmp;
	tmp = fgImg(blobRect);
//DEBUG:
//	cout << "blobRect (w,h)= (" << blobRect.width << ", " << blobRect.height << ")" << endl;

	double fy = 200.0/(double)tmp.rows;
	resize(tmp, blobImg, Size(), fy, fy, CV_INTER_CUBIC);

	return(true);
}
#endif

/**
 * Add a blob
 * @param frameCount IN
 * @param roi IN
 * @param fgClean IN
 * @param fgColor IN
 * @param newId OUT
 * @return true if succeed
 */
bool CMISBlob::add(int frameCount, Rect roi, const Mat& fgClean, const Mat& fgColor, int& newId)
{

	if (blobsList.size() >= kMISBLOB_COUNT_MAX)
		return(false);

	BlobData data;
	data_set(data, frameCount, roi);

	BlobObject obj;
	obj.actorId = -1;

	// Update shape blob image (normalized 200 px height)
//	if(!extract_blob_image(fgClean, roi, obj.shapeImg))
//		return(false);

	// Update color blob image (normalized 200 px height)
//	if (!extract_blob_image(fgColor, roi, obj.colorImg))
//		return(false);

	obj.data.push_back(data);
	blobsList.push_back(obj);
	newId = (int)blobsList.size()-1;
//	cout << "New Blob[" << newId << "] created!" << endl;

	maxCount_++;

	return(true);
} // add


/**
 * Remove a blob
 * @param id IN
 * @return true if succeed
 */
bool CMISBlob::remove(int id)
{
	if (blobsList.empty())
		return(false);

	blobsList[id].data.clear();
	blobsList.erase(blobsList.begin()+id);
//	cout << "Blob[" << id << "] removed!" << endl;

	maxCount_--;

	return(true);
} // remove


/**
 * Remove all blobs
 * @return true if succeed
 */
bool CMISBlob::remove_all(void)
{
	int blobsCount = blobsList.size();
	if (blobsCount == 0)
		return(false);

	for (int i = 0; i < blobsCount; ++i)
	{
		blobsList[i].data.clear();
		blobsList.erase(blobsList.begin()+i);
//		cout << "Blob[" << i << "] removed!" << endl;

		maxCount_--;
	}

	maxCount_ = 0;
	return(true);
} // remove_all

