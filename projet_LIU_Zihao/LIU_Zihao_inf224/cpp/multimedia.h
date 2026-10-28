#ifndef MULTLMEDIA_H
#define MULTLMEDIA_H
#include <iostream>
#include <memory>
using namespace std;


/**
 * @brief The Multimedia class
 * The base MUltitmedia class used for heritage
 */
class Multimedia
{
protected :
    std::string name{};
    std::string pathName{};

public:
    Multimedia(std::string name, std::string pathName);
    Multimedia(){};
    virtual ~Multimedia();
    std::string getName() const;
    std::string getPathName() const;
    void setName(std::string);
    void setPathName(std::string);
    virtual void display(std::ostream&) const = 0 ;
    virtual void play() const = 0;
    virtual string getAllParameters() const;
};

typedef shared_ptr<Multimedia> MPtr;

#endif
