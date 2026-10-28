#include "myserver.h"
#include "tcpserver/tcpserver.h"
#include "generaltable.h"
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
//#define TEST_SERVER_VERSION1
//#define TEST_SEARCH_AND_PLAY
#define TEST_ALL_FONCTIONS
using namespace std;

/**
 * @brief MyServer::MyServer, implicit constructor
 *  */
MyServer::MyServer(){}

/**
 * @brief MyServer::MyServer, explicit constructor of the server
 * @param _table table that associated with the server
 */
MyServer::MyServer(GeneralTable * _table){
    ServerTable = _table;
}

/**
 * @brief MyServer::startServer
 * @return true if succeed, false if not
 */
int MyServer::startServer(){
     #ifdef TEST_SERVER_VERSION1
     // cree le TCPServer
      TCPServer* server = new TCPServer( [&](std::string const& request, std::string& response)
      {
      // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;

       // the response that the server sends back to the client
        response = "RECEIVED: " + request;

       // return false would close the connecytion with the client
        return true;;
     });


     // lance la boucle infinie du serveur
     std::cout << "Starting Server on port " << PORT << std::endl;

     int status = server->run(PORT);

     // en cas d'erreur^S
     if (status < 0) {
       std::cerr << "Could not start Server on port " << PORT << std::endl;
       return 1;
     }
       return 0;
    #endif

    #ifdef TEST_SEARCH_AND_PLAY

       //create TCP server
       TCPServer* server = new TCPServer( [&](std::string const& request, std::string& response)
       {
        //string name = nullptr;
       // the request sent by the client to the server
         std::cout << "request: " << request << std::endl;

        // the response that the server sends back to the client

         //name = request;

         findPlayMultimedia(request);

         response = "RECEIVED: " + request;

        // return false would close the connecytion with the client
         return true;;
      });


      // lance la boucle infinie du serveur
      std::cout << "Starting Server on port " << PORT << std::endl;

      int status = server->run(PORT);

      // en cas d'erreur^S
      if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
      }

      return 0;
      #endif

#ifdef TEST_ALL_FONCTIONS
   //create TCP server
   TCPServer* server = new TCPServer( [&](std::string const& request, std::string& response)
   {
    string parameters = "nothing";
   // the request sent by the client to the server
     std::cout << "request: " << request << std::endl;

    // the response that the server sends back to the client

     // pl is play, re is find
     string choice = "no choice";
     choice = request.substr(0,2);

     if(choice == "pl")
     {
           string name = request.substr(3);
           findPlayMultimedia(name);
           response = "play";
     }
     else if (choice == "re" )
     {
            string name = request.substr(3);
            parameters = searchAndReturnParameters(name);
            cout << "para " + parameters<< endl;
            response = "return parameters : " + parameters;
     }
     else
     {
            response = "no choice";
     }

    // return false would close the connecytion with the client
     return true;;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur^S
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }
  return 0;
  #endif
 }

/**
 * @brief MyServer::findPlayMultimedia
 * @param _name name of the multimedia object that we want to find
 * @return true if find, false if not
 */
bool MyServer::findPlayMultimedia(const string _name) const
{
    bool find = ServerTable->playMultimedia(_name);
    return find;
}

/**
 * @brief MyServer::searchAndReturnParameters
 * @param _name
 * @return true if find, false if not
 */
string MyServer::searchAndReturnParameters(const string _name) const
{
    string para = ServerTable->searcMultimediaReturnParameters(_name);
    return para;
}


