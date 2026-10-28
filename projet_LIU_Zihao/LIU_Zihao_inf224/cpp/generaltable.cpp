#include "generaltable.h"
#include "film.h"
#include "group.h"
#include "photo.h"
#include "video.h"



/**
 * @brief GeneralTable::createGroup
 * @param _name name of the
 * @return
 */
Group* GeneralTable::createGroup(const string _name)
{
    Group *g = new Group(_name);
    group.insert({_name,g});
    return g;
}

/**
 * @brief GeneralTable::creatPhoto
 * @param _name name of the photo
 * @param _pathName path of the photo
 * @return the smart pointer to the photo object
 */
MPtr GeneralTable::creatPhoto(const string _name,const string _pathName,int _length,int _width)
{
    MPtr photo1(new Photo(_name,_pathName,_length,_width));
    BaseMultimedia.insert({_name,photo1});
    return photo1;
}

/**
 * @brief GeneralTable::creatVideo
 * @param _name name of the video
 * @param _pathName path of the video
 * @return the smart pointer to the video
 */
MPtr GeneralTable::creatVideo(const string _name,const string _pathName,int _duration)
{
    MPtr video1(new Video(_name,_pathName,_duration));
    BaseMultimedia.insert({_name,video1});
    return video1;
}

/**
 * @brief GeneralTable::creatVideo
 * @param _name name of the film
 * @param _pathName path of the film
 * @return the smart pointer to the film
 */
MPtr GeneralTable::creatFilm(const string _name,const string _pathName,int _duration)
{
    MPtr film1(new Film(_name,_pathName,_duration));
    BaseMultimedia.insert({_name,film1});
    return film1;
}

/**
 * @brief GeneralTable::findMultimediaDisplay
 * @param _name name of the multimedia object that the user want to find
 * @return true if found, false if not
 */
bool GeneralTable::findMultimediaDisplay(const string _name) const
{
    auto it = BaseMultimedia.find(_name);
    if(it == BaseMultimedia.end())
    {
        cout<<"not find multimedia"<<endl;
        return false;
    }
    else
    {
        it->second->display(cout);
        return true;
    }
}

/**
 * @brief GeneralTable::findGroupDiaplay
 * @param _name name of the group that the use want to find
 * @return true if found, false if not
 */
bool GeneralTable::findGroupDiaplay(const string _name) const
{
    auto it = group.find(_name);
    if(it == group.end())
    {
        cout<<"not find group"<<endl;
        return false;
    }
    else
    {
        it->second->showMember();
        return true;
    }
}

/**
 * @brief GeneralTable::playMultimedia
 * @param _name name of the multimedia that we want to play
 * @return true is found, flase if not
 */
bool GeneralTable::playMultimedia(const string _name) const
{
    auto it = BaseMultimedia.find(_name);
    if(it == BaseMultimedia.end())
    {
        cout<<"not find multimedia"<<endl;
        return false;
    }
    else
    {
        it->second->play();
        return true;
    }
}

/**
 * @brief GeneralTable::searcMultimediaReturnParameters
 * @param _name name of the multimedia that we want to find
 * @return all parameters of this multimedia
 */
string GeneralTable::searcMultimediaReturnParameters(const string _name) const
{
    auto it = BaseMultimedia.find(_name);
    if(it == BaseMultimedia.end())
    {
        string s1 = "The server can not find multimedia";
        return s1;
    }
    else
    {
        string s2 = it->second->getAllParameters();
        return s2;
    }
}


