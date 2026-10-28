#ifndef GENERALTABLE_H
#define GENERALTABLE_H


#include <map>
#include "film.h"
#include "group.h"
#include "photo.h"
#include "video.h"

/**
 * @brief The GeneralTable class
 * the general table used to store all multimedia objects and all groups
 */
class GeneralTable
{
private:
    std::map<string,MPtr> BaseMultimedia{};
    std::map<string,Group*> group{};
public:
    GeneralTable(){};
    MPtr creatPhoto(const string,const string,int,int);
    MPtr creatVideo(const string,const string,int);
    MPtr creatFilm(const string,const string,int);
    Group* createGroup(const string);
    bool findMultimediaDisplay(const string) const;
    bool findGroupDiaplay(const string) const;
    bool playMultimedia(const string _name) const;
    string searcMultimediaReturnParameters(const string) const;
};

#endif // GENERALTABLE_H


