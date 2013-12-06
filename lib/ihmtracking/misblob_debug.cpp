/**
 * @brief Debug/print functions
 * @file misblob_debug.cpp
 */

#include "misblob.h"


/**
 * Print Rect structure (formated output)
 * @param out OUT
 * @param roi IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const Rect& roi)
{
	out << "[" << roi.x << ", ";
	out << roi.y << ", ";
	out << roi.width << ", ";
	out << roi.height << "]";

	return(out);
}


/**
 * Print MISBlobData structure (formated output)
 * @param out OUT
 * @param data IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CMISBlob::BlobData& data)
{
	out <<  data.frameNumber << ", ";
	out << data.roi << endl;

	return(out);
}

/**
 * Print MISBlobData list (formated output)
 * @param out OUT
 * @param object IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CMISBlob::BlobObject& object)
{
	out << "ActorId = " << object.actorId << endl;

	int dataCount = object.data.size();
	for (int i = 0; i < dataCount; ++i)
		out << object.data[i];

	return(out);
}


/**
 * Print MISBlobData list (formated output)
 * @param out OUT
 * @param objList IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const vector<CMISBlob::BlobObject>& objList)
{
	int objCount = objList.size();

	for (int i = 0; i < objCount; ++i)
		out << objList[i];

	return(out);
}


/**
 * Class print data (formated output)
 * @param out OUT
 * @param blob IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CMISBlob& blob)
{

	// Print 
	out << "maxCount: " << blob.maxCount_ << endl;

	// Print all recorded blob positions
	int blobsCount = blob.blobsList.size();
	for (int i = 0; i < blobsCount; ++i)
		out << i << ": " << blob.blobsList[i] << endl;

	return(out);
}

