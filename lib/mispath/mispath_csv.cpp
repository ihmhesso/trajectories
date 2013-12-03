/**
 * @brief Read/write csv file functions definition
 * @file mispath_csv.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */

#include "mispath.h"


/**
 * Write data to .csv file
 * @param filename IN
 * @return true if succeed
 */
bool CMISPath::csv_write(const string& filename) const
{
	ofstream file;
	int linesCount = 0;

	// Setup exception mask
	file.exceptions(ofstream::failbit | ofstream::badbit);

	// Open or create file
	try
	{
		file.open(filename.c_str(), ofstream::out);

		// Write first line file
		file << "frameCount" << "," << "x" << "," << "y" << endl;

		// Write all points
		int count = path_.size();
		for (int i = 0; i < count; ++i)
		{
			file << path_[i].frameCount << ",";
			file << path_[i].p.x << "," << path_[i].p.y << endl;
			linesCount++;
		}

		file.close();
	}
	catch (ofstream::failure& e)
	{
		cerr << "Exception opening/reading file " << filename << endl;
		return(false);
	}

	cout << linesCount << " lines written to " << filename << endl;
	return(true);
} // csv_write


/**
 * Read data from .csv file
 * @param filename IN
 * @return true when done
 */
bool CMISPath::csv_read(const string& filename)
{
	ifstream file;
	int linesCount = 0;

	// Setup exception mask
	file.exceptions(ofstream::failbit | ofstream::badbit);

	// Open or create file
	try
	{
		file.open(filename.c_str(), ofstream::in);

		// Erase previous path point
		path_.clear();

		// Skip first line file
		string line;
		getline(file, line);

		while (file.good())
		{
			getline(file, line);

			PathData data;
			sscanf(line.c_str(), "%d,%d,%d", &data.frameCount, &data.p.x, &data.p.y);

			path_.push_back(data);
			linesCount++;
		}

		file.close();
	}
	catch (ofstream::failure& e)
	{
//DEBUG:
		cerr << e.what() << endl;
		cout << endl;
//		return(false);
	}

	cout << linesCount << " lines read from " << filename << endl;
	return(true);
} // csv_read

