#ifndef MYSERVER_H
#define MYSERVER_H

#define PORT 3331
#include <string>
#include "generaltable.h"
using namespace std;

/**
 * @brief The MyServer class
 * the TCP server to store the multimedia table
 */
class MyServer
{
private:
    GeneralTable *ServerTable = nullptr;
public:
    MyServer();
    MyServer(GeneralTable *_table);
    int startServer();
    bool findPlayMultimedia(const string) const;
    string searchAndReturnParameters(const string) const;
};

#endif
