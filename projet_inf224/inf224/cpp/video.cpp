#include "video.h"
#include <iostream>
using namespace std;

/**
 * @brief Video::setDuration
 * @param duration of the video
 */
void Video::setDuration(int duration)
{
    this->videoDuration = duration;
}

/**
 * @brief Video::getDuration
 * @return the duration of the video
 */
int Video::getDuration() const
{
    return this->videoDuration;
}

/**
 * @brief Video::display
 * @param the output stream that show the parameters of this video
 */
void Video::display(std::ostream& s) const
{
    s<< this->name << endl;
    s<< this->pathName << endl;
}

/**
 * @brief Video::play
 * play the video
 */
void Video::play() const
{
    string cmd = "mpv " + pathName + " &";
    system(cmd.c_str());
}

string Video::getAllParameters() const
{
    string para = "file name: " + name + "   " + "file path: ./" + pathName + "  " + "duration: " + std::to_string(getDuration()) + "s";
    return para;
}
