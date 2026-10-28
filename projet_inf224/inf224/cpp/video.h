#ifndef VIDEO_H
#define VIDEO_H
#include "multimedia.h"
using namespace std;

/**
 * @brief The Video class
 * The video class used to store video
 */
class Video: public Multimedia
{
private:
    int videoDuration{};
public:
    Video(){}
    Video(std::string _name,std::string _pathName,int _duration):Multimedia(_name,_pathName)
    {
        name = _name;
        pathName = _pathName;
        videoDuration = _duration;
    }
    virtual ~Video(){printf("the video is destroied");}
    void setDuration(int);
    int getDuration() const;
    void display(std::ostream&) const override;
    void play() const override;
    string getAllParameters() const override;
};

#endif
