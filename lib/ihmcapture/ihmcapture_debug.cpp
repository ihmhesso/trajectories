/**
 * @brief Debug/print functions
 * @file ihmcapture_debug.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date Dec 2013
 */

#include "ihmcapture.h"


/**
 * Class print data (formated output)
 * @param out
 * @param cap IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMCapture& cap)
{
	out << "CIHMCapture, " <<  cap.version_get() << endl;

	return(out);
}


/**
 * Class print data (formated output)
 * @param out
 * @param mode IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMCapture::ECapture_Mode& mode)
{
	string txt;

	switch (mode)
	{
	case CIHMCapture::kMode_Play: txt = "PLAY mode"; break;
	case CIHMCapture::kMode_Stop: txt = "STOP mode"; break;
	//TODO: ...
	default: break;
	}

	out << txt;
	return(out);
}

