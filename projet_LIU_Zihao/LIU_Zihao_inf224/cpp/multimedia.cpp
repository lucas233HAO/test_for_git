#include "multimedia.h"
#include <iostream>
using namespace std;

/**
 * @brief Multimedia constructor
 * @param _name name of multimedia object
 * @param _pathName path of multimedia object
 */
Multimedia::Multimedia(std::string _name,std::string _pathName)
{
    name = _name;
    pathName = _pathName;
}

/**
 * Multimedia destructor
 */
Multimedia::~Multimedia(){}

/**
 * @brief Multimedia::setName
 * @param name of multimedia
 */
void Multimedia::setName(std::string _name)
{
    name = _name;
}

/**
 * @brief Multimedia::setPathName
 * @param path of multimedia
 */
void Multimedia::setPathName(std::string _pathName)
{
    pathName = _pathName;
}

/**
 * @brief Multimedia::getName
 * @return name of multimedia
 */
std::string Multimedia::getName() const
{
    return this->name;
}

/**
 * @brief Multimedia::getPathName
 * @return path of multimedia
 */
std::string Multimedia::getPathName() const
{
    return this->pathName;
}

/**
 * @brief Multimedia::display
 * @param show the parameters of multimedia object on the terminal
 */
void Multimedia::display(std::ostream& s) const
{
    s<<this->name<<std::endl;
}

/**
 * @brief Multimedia::getAllParameters
 * @return all paramters of this multimedia object
 */
string Multimedia::getAllParameters() const
{
    string para = "file name: " + name + "   " + "file path: ./" + pathName ;
    return para;
}
