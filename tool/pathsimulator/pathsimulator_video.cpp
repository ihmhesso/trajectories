/**
 * @brief Video handler functions definition
 * @file pathsimulator_video.cpp
 * @author gregory.medwed@heig-vd.ch
 * @date October 2013
 */

#include "pathsimulator.h"


/**
 * Video handler
 * @param app OUT
 * @return TRUE when done
 */
bool video_handler(ApplicationData& app)
{

	app.tNow = (double)getTickCount()/(double)getTickFrequency();

	//Is it time to do something
	double delta = (app.tNow-app.tRef)*1000.0;

	//DEBUG
//	cout << "tNow = " << app.tNow << ", tRef = " << app.tRef << ", delta = " << delta << endl;

	if (delta >= app.frameTime*1000.0)
	{
		// Update tRef
		app.tRef += app.frameTime;

		//DEBUG
//		cout << "tNow = " << app.tNow << ", tRef = " << app.tRef << endl;

//		int pointsCount = app.pPath->points_count_get();

		if (app.freeHandRecording)
		{
			app.pPath->point_add(app.framesCount, app.mouseCoord);
			app.framesCount++;
		}

		switch (app.mode)
		{
		case kPlayback_Mode_Play:
			app.pPath->current_pos_inc(1, app.loopEnable);
			if (app.maxFrame != 0)
				app.framesCount = (int)app.pCapture->get(CV_CAP_PROP_POS_FRAMES);
			else
				app.framesCount++;

			if (app.framesCount >= app.maxFrame-2)
			{
				app.mode = kPlayback_Mode_Stop;
				cout << "STOP mode" <<endl;
			}
			else
			{
				app.pCapture->read(app.src);
			}

			setTrackbarPos("Frames count", app.winName, app.framesCount);
			app.pPath->path_draw(app.src, app.pathColor, app.img);
			app.pPath->position_draw(app.img, app.objColor, app.objSize, app.img);
			break;
		case kPlayback_Mode_Record:
			// Update input
			app.pPath->current_pos_inc(1, app.loopEnable);
			if (app.maxFrame != 0)
				app.framesCount = (int)app.pCapture->get(CV_CAP_PROP_POS_FRAMES);
			else
				app.framesCount++;

			if (app.framesCount >= app.maxFrame-2)
			{
// Stop at the end of the video
//				app.mode = kPlayback_Mode_Stop;
//				cout << "STOP mode" <<endl;
// Better: restart the video until the user STOP or we path through all points
				app.pCapture->set(CV_CAP_PROP_POS_FRAMES, 0.0);
			}
			else
			{
				app.pCapture->read(app.src);
			}

			setTrackbarPos("Frames count", app.winName, app.framesCount);

			if (app.pPath->current_pos_get() >= app.pPath->points_count_get())
			{
				app.mode = kPlayback_Mode_Stop;
				cout << "STOP mode" <<endl;
			}

			// Update output
			app.pPath->path_draw(app.src, app.pathColor, app.img);
			app.pPath->position_draw(app.img, app.objColor, app.objSize, app.img);

			if (app.generateImages)
			{
				if (app.folderName.empty())
				{
					// create a new folder with date and time
					app.folderName = "output/";
					{
						int d = 0;
						int t = 0;
						app.folderName += date_time_get(d, t);
					}

					struct stat st = {0};
					if (stat(app.folderName.c_str(), &st) == -1)
					{
					    mkdir(app.folderName.c_str(), 0700);
						cout << "New folder " << app.folderName << " created!" << endl;
					}

					app.folderName += '/';
				}

				// Create new image name with frame count as number
				string fcount;
				{
					char buffer[20];
					memset(buffer, 0, 20);
					sprintf(buffer, "%04d", app.framesCount);
					fcount = buffer;
				}

				stringstream suffix;
				suffix << "_";
				suffix << fcount;
				suffix << ".jpg";
				string imgName= format_filename(app.folderName, "_img", app.pPath->type_get(), suffix.str());

				// Write new image
				if (imwrite(imgName, app.img))
					cout << "New image written! " << imgName << endl;

			}
			else
			{
				if (app.pRecord)
					app.pRecord->write(app.img);
			}
			break;
		case kPlayback_Mode_Stop:
			// Do nothing
			break;
		default:
			// Do nothing
			break;
		}
	}

	return(true);
}
