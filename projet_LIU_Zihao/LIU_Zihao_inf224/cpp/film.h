#ifndef FILM_H
#define FILM_H
#include "multimedia.h"
#include "video.h"
using namespace std;

/**
 * @brief The Film class
 * the film class uesd to store the film
 */
class Film: public Video
{
private:
    int *chapiterDuration = nullptr;
    int numberOfchapiter{};
public:
    Film(){}
    Film(std::string name,std::string pathName,int _duration):Video(name,pathName,_duration){}
    ~Film();
    Film(const Film&);
    Film& operator=(const Film&);
    void setChapiter(const int* chapiter, int number);
    const int* getChapiter() const;
    int getnumber() const;
    void display(std::ostream&) const override;
};

#endif
