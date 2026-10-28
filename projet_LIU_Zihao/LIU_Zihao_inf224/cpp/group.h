#ifndef GROUP_H
#define GROUP_H
#include <memory>
#include "multimedia.h"
using namespace std;
#include <list>


/**
 * @brief The Group class
 * the group class used to store the group
 */
class Group : public std::list<MPtr>
{
private:
    string groupName = "";
public:
    Group(){};
    Group(string);
    ~Group(){};
    string getName() const;
    void showMember() const;
};

#endif
