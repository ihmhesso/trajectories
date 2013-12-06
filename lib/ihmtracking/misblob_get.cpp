/**
 * @brief Get/Set functions
 * @file misblob_get.cpp
 */


#include "misblob.h"


/**
 * Get library version number
 * @return string like "1.0.0"
 */
string CMISBlob::version_get(void)
{
	stringstream out;

	int major = kMISBLOB_VERSION_MAJOR_NUMBER;
	int minor = kMISBLOB_VERSION_MINOR_NUMBER;
	int patch = kMISBLOB_VERSION_PATCH_NUMBER;

	out << major << "." << minor << "." << patch;
	
	return(out.str());
}



/**
 * Get blobs count (current and total)
 * @param count OUT
 * @param maxCount OUT
 * @return string like "0 / 1"
 */
string CMISBlob::count_get(int& count, int& maxCount)
{
	stringstream out;

	count = (int)blobsList.size();
	maxCount = maxCount_;

	out << count << " / " << maxCount;

	return(out.str());
}



/**
 * Set data in MISBlobData structure
 * @param data OUT
 * @param frameNumber IN
 * @param roi IN
 * @return true if succeed
 */
bool CMISBlob::data_set(BlobData& data, int frameNumber, const Rect& roi)
{
	memset(&data, 0, sizeof(BlobData));

	data.frameNumber = frameNumber;
	data.roi = roi;

	return(true);
}


/**
 * Get blob floor point of contact
 * @param data IN
 * @return contact point coorinates
 */
Point CMISBlob::floor_contact_get(const BlobData& data)
{
	Point floorPOC(0, 0);

	floorPOC.x = data.roi.x + data.roi.width/2;
	floorPOC.y = data.roi.y + data.roi.height*floorPOC_;

	return(floorPOC);
}


