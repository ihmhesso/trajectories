/**
 * @brief Debug/print functions
 * @file ihmbackground_debug.cpp
 * @author ...
 * @date Dec 2013
 */

#include "ihmbackground.h"


/**
 * Class print data (formated output)
 * @param out
 * @param bg IN
 * @return output stream
 */
ostream& operator<<(ostream& out, const CIHMBackground& bg)
{
	out << "CIHMBackground, " <<  bg.version_get() << endl;

	return(out);
}


/**
 * Mog2Param print data (formated output)
 * @param param IN
 * @return output stream
 */
void CIHMBackground::Mog2Param_print(const Mog2Param& param)
{
	cout << "Mog2Param:" <<  endl;
	cout << "  mixtures:       " << param.mixtures << endl;
	cout << "  bgRatio:        " << param.bgRatio << endl;
	cout << "  varThreshold:   " << param.varThreshold << endl;
	cout << "  varInit:        " << param.varInit << endl;
	cout << "  varMin:         " << param.varMin << endl;
	cout << "  varMax:         " << param.varMax << endl;
	cout << "  ct:             " << param.ct << endl;
	cout << "  shadowValue:    " << param.shadowValue << endl;
	cout << "  shadowThreshold:" << param.shadowThreshold << endl;
	cout << "  shadowEnable:   " << param.shadowEnable << endl;
} // Mog2Param_print

