
#include "group.h"
#include "multimedia.h"
#include "photo.h"
#include "video.h"
using namespace std;
#include <list>

/**
 * @brief Group::Group
 * @param name name of the group
 */
Group::Group(string name)
{
    groupName = name;
}

/**
 * @brief Group::getName
 * @return the name of the group
 */
string Group::getName() const
{
    return groupName;
}

/**
 * @brief Group::showMember
 * show the name of all group members on the terminal
 */
void Group::showMember() const
{
    for(auto & it : (*this))
    {
        it->display(cout);
    }
}
