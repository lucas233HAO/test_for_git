#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"
using namespace std;


/**
 * @brief The Photo class
 * The photo class used to store photos
 */
class Photo: public Multimedia
{
private:
    int length{};
    int width{};

public:
    Photo(){}
    Photo(std::string _name,std::string _pathName,int _length, int _width):Multimedia(_name,_pathName)
    {
        name = _name;
        pathName = _pathName;
        length = _length;
        width = _width;
    }

    ~Photo(){printf("the photo '%s' is destroied",name.c_str());}
    void setLength(int); // setters
    void setWidth(int);
    int getLength() const; // getters
    int getWidth() const;
    void display(std::ostream& s) const override;
    void play() const override;
    string getAllParameters() const override;
};

#endif

