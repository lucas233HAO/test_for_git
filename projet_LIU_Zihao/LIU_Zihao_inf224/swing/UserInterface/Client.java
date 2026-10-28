package UserInterface;

import java.io.*;
import java.net.*;

public class Client
{
private static final long serialVersionUID = 1L;
static final String DEFAULT_HOST = "localhost";
static final int DEFAULT_PORT = 3331;
private Socket sock;
private BufferedReader input;
private BufferedWriter output;
private GeneralWindow window;

public Client(GeneralWindow gWindow) {
	this.window = gWindow;
	this.window.addTextArea("start a new client \n");
}

public void startClient(){
 String host = DEFAULT_HOST;
 int port = DEFAULT_PORT;
 Client client = null;
 
 try {
   client = new Client(host, port);
 }
 catch (Exception e) {
    this.window.addTextArea("Client: Couldn't connect to "+host+":"+port + "\n");	 
    this.window.addTextArea("please quit");
    while(true) {}
   
 }
 
 this.window.addTextArea("Client connected to "+host+":"+port + "\n");
 BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
 this.window.addTextArea("request :");	
 
 String request = " ";
 while (true) {	 
	
   try { 
	   while(true)
	   { 
		  Thread.sleep(1);
		  if(window.getSendPlay() == true)
		  {   
			  window.addTextArea("\norder : play");
			  String name = window.getFileName();
			  request = "pl"+" "+name;
			  window.setSendPlay(false);
			  break;
		  }
		  if(window.getSendFind() == true)
		  {   
			  window.addTextArea("\norder : find");
			  String name = window.getFileName();
			  request = "re"+" "+name;
			  window.setSendFind(false);
			  break;
		  }
	  }
     String response = client.send(request);
     this.window.addTextArea("Response : "+ "\n" + response + "\n");
     this.window.addTextArea("request :");	
     
   }
   catch (Exception e) {
	   this.window.addTextArea("Client: IO error");	   
       return ;
   }

 }
}

///
/// Initialise la connexion.
/// Renvoie une exception en cas d'erreur.
///
public Client(String host, int port) throws UnknownHostException, IOException {
 try {
   sock = new java.net.Socket(host, port);
 }
 catch (java.net.UnknownHostException e) {
	 this.window.addTextArea("Client: Couldn't find "+host+":"+port);
     throw e;
 }
 catch (java.io.IOException e) {
	 this.window.addTextArea("Client: Couldn't reach to "+host+":"+port);   
	 throw e;
 }
  try {
   input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
   output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
 }
 catch (java.io.IOException e) {
	 this.window.addTextArea("Client: Couldn't open input or output to "+host+":"+port);
     throw e;
 }
}


/// Envoie une requete au server et retourne sa reponse.
/// Noter que la methode bloque si le serveur ne repond pas.
public String send(String request) {
 
 try {
   request += "\n";  
   output.write(request, 0, request.length());
   output.flush();
 }
 catch (java.io.IOException e) {
	 this.window.addTextArea("Client couldn't send message" + e);	   
     return null;
 }
 
 //Recuperer le resultat envoye par le serveur
 try {
   return input.readLine();
 }
 catch (java.io.IOException e) {
	 this.window.addTextArea("Client: Couldn't receive message"+ e);	
     return null;
 }
}
}


