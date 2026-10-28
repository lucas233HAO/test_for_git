#include "film.h"



/**
 * @brief Film::setChapiter
 * @param table of chapiterDuration of each chapiter
 * @param number of each chapiter
 */
void Film::setChapiter(const int* _chapiterDuration,int number)
{
    numberOfchapiter = number;
    if(_chapiterDuration != nullptr)
    {
        delete[] chapiterDuration;
        chapiterDuration = new int[number];
        for(int i=0;i<numberOfchapiter;i++)
        {
            chapiterDuration[i] = _chapiterDuration[i];
        }
    }
    else
        chapiterDuration = nullptr;
}

/**
 * @brief Film::getChapiter
 * @return the table of chapiter duration
 */
const int* Film::getChapiter() const
{
    return this->chapiterDuration;
}

/**
 * @brief Film::getnumber
 * @return the number of chapiter
 */
int Film::getnumber() const
{
    return numberOfchapiter;
}

/**
 * @brief Film::display
 * @param the output stream that used to show the parameters
 */
void Film::display(std::ostream& s) const
{
    s << this->getName() << endl;
    s << this->getPathName() << endl;
}

/**
 * @brief Film::~Film
 * film destructor
 */
Film::~Film()
{
    printf("the film is destroied");
    delete[] chapiterDuration;
}

/**
 * @brief Film::Film
 * @param the film object which we copied from
 */
Film::Film(const Film& from):Video(from)
{
    setChapiter(from.getChapiter(),from.getnumber());
}

/**
 * @brief redefinition of "="
 * @param the film that we copied from
 * @return the film object with the same parameters
 */
Film& Film::operator=(const Film&from)
{
    Video::operator=(from);
    setChapiter(from.getChapiter(),from.getnumber());
    return *this;
}
