#include "photo.h"
#include <iostream>
using namespace std;


/**
 * @brief Photo::setLength
 * @param length of the photo
 */
void Photo::setLength(int l)
{
    this->length = l;
}

/**
 * @brief Photo::setWidth
 * @param width of the photo
 */
void Photo::setWidth(int w)
{
    this->width = w;
}


/**
 * @brief Photo::getLength
 * @return length of the photo
 */
int Photo::getLength() const
{
    return this->length;
}

/**
 * @brief Photo::getWidth
 * @return width of the photo
 */
int Photo::getWidth() const
{
    return this->width;
}

/**
 * @brief Photo::display
 * @param show paramters on the console
 */
void Photo::display(std::ostream& s) const
{
    s<<this->name<<endl;
    s<<this->pathName<<endl;
}

/**
 * @brief Photo::play
 * play the photo
 */
void Photo::play() const
{
    string cmd = "imagej " + pathName + " &";
    system(cmd.c_str());
}

string Photo::getAllParameters() const
{
    string para = "file name: " + name + "   " + "file path: ./" + pathName + "  " + "length: " + std::to_string(getLength()) + "  " +
                  "width: " + to_string(getWidth()) ;
    return para;
}




