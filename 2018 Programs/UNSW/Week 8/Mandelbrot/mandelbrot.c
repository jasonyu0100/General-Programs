// Libraries
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
// Header Files
#include "mandelbrot.h"
#include "pixelColor.h"
// Defines
#define MAX_VALUE 2
#define MAX_STEPS 256
#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 7191
#define NUMBER_OF_PAGES_TO_SERVE 10
#define BMP_SIZE 512
#define OFFSET 54

typedef struct imaginaryPoint {
    double real;
    double imaginary;
} imaginaryPoint;

// Other functions
double calculateDistance(imaginaryPoint point);
imaginaryPoint addPoints(imaginaryPoint pointOne, imaginaryPoint pointTwo);
imaginaryPoint squarePoint(imaginaryPoint point);
// Server Functions
int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
void serveBMP (int socket,int zoom,double x,double y);
void serveHTML (int socket);
void createMandelbrot(double x,double y,double zoom, unsigned char *bmp);


int main (int argc, char *argv[]) {
      
   printf ("************************************\n");
   printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
   printf ("Serving bmps since 2012\n");   
   
   int serverSocket = makeServerSocket (DEFAULT_PORT);   
   printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
   printf ("************************************\n");
   
   char request[REQUEST_BUFFER_SIZE];
   int numberServed = 0;
   while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
      
      printf ("*** So far served %d pages ***\n", numberServed);
      
      int connectionSocket = waitForConnection (serverSocket);
      // wait for a request to be sent from a web browser, open a new
      // connection for this conversation
      
      // read the first line of the request sent by the browser  
      int bytesRead;
      bytesRead = read (connectionSocket, request, (sizeof request)-1);
      assert (bytesRead >= 0); 
      // were we able to read any data from the connection?
            
      // print entire request to the console 
      printf (" *** Received http request ***\n %s\n", request);
      int successfulInputs = 0;
      int zoom;
      double x;
      double y;
      successfulInputs = sscanf(request, " GET /mandelbrot/2/%d/%lf/%lf/tile.bmp", &zoom,&x,&y);

      if (successfulInputs == 3) {
          printf("%d %lf %lf\n",zoom,x,y);
          printf("%d\n",successfulInputs);
          serveBMP(connectionSocket,zoom,x,y);
      } else {
          if (request[5] == ' ') {
              serveHTML(connectionSocket);
          } else {
              printf("Page could not be loaded!\n");
          }
      }

      //send the browser a simple html page using http
      printf (" *** Sending http response ***\n");
      // close the connection after sending the page- keep aust beautiful
      close(connectionSocket);
      
      numberServed++;
   } 
   
   // close the server connection after we are done- keep aust beautiful
   printf ("** shutting down the server **\n");
   close (serverSocket);
   
   return EXIT_SUCCESS; 
}

void serveHTML (int socket) {
    printf("Sending message \n");
   char* message;
 
   // first send the http response header
   message =
      "HTTP/1.0 200 Found\n"
      "Content-Type: text/html\n"
      "\n";
   printf ("about to send=> %s\n", message);
   write (socket, message, strlen (message));
 
   message =
      "<script src=\"http://almondbread.cse.unsw.edu.au/tiles.js\"></script>";      
   write (socket, message, strlen (message));
}

void serveBMP (int socket,int zoom,double x,double y) {
   char* message;
   
   // first send the http response header
   
   // (if you write stings one after another like this on separate
   // lines the c compiler kindly joins them togther for you into
   // one long string)
   message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: image/bmp\r\n"
                "\r\n";
   printf ("about to send=> %s\n", message);
   write (socket, message, strlen (message));
   
   // now send the BMP
   // Right Header
    
   unsigned char bmp[BMP_SIZE * BMP_SIZE * 3 + OFFSET] = {
     0x42,0x4d,0x36,0x00,0x00,0x00,0x00,0x00,
     0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,
     0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,
     0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,
     0x00,0x00,0x24,0x00,0x00,0x00,0x13,0x0b,
     0x00,0x00,0x13,0x0b,0x00,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x00,0x00}; // starts at 54


  unsigned char *p;
  p = bmp;
  createMandelbrot(x,y,zoom,p);
  write (socket, bmp, sizeof(bmp));
}

void createMandelbrot(double x,double y,double zoom, unsigned char *bmp) {
  float distance = pow(2,-zoom);
  int rowCount = 0;
  int colCount = 0;
  double xOrigin = x - ((255 + 0.5) * distance);
  double yOrigin = y - ((255 + 0.5) * distance);
  imaginaryPoint currentPoint = {xOrigin,yOrigin};
  while (rowCount < BMP_SIZE){
    colCount = 0;
    while(colCount < BMP_SIZE ){
      int steps = escapeSteps(currentPoint.real,currentPoint.imaginary);
      *(bmp + OFFSET + rowCount * BMP_SIZE * 3 + colCount * 3) = stepsToBlue(steps);
      *(bmp + OFFSET + rowCount * BMP_SIZE * 3 + colCount * 3 + 1) = stepsToGreen(steps);
      *(bmp + OFFSET + rowCount * BMP_SIZE * 3 + colCount * 3 + 2) = stepsToRed (steps);
      colCount++;
      currentPoint.real += distance;
    }
    rowCount++;
    currentPoint.imaginary += distance;
    currentPoint.real = xOrigin;
  }
}


// start the server listening on the specified port number
int makeServerSocket (int portNumber) { 
   
   // create socket
   int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
   assert (serverSocket >= 0);   
   // error opening socket
   
   // bind socket to listening port
   struct sockaddr_in serverAddress;
   memset ((char *) &serverAddress, 0,sizeof (serverAddress));
   
   serverAddress.sin_family      = AF_INET;
   serverAddress.sin_addr.s_addr = INADDR_ANY;
   serverAddress.sin_port        = htons (portNumber);
   
   // let the server start immediately after a previous shutdown
   int optionValue = 1;
   setsockopt (
      serverSocket,
      SOL_SOCKET,
      SO_REUSEADDR,
      &optionValue, 
      sizeof(int)
   );

   int bindSuccess = 
      bind (
         serverSocket, 
         (struct sockaddr *) &serverAddress,
         sizeof (serverAddress)
      );
   
   assert (bindSuccess >= 0);
   // if this assert fails wait a short while to let the operating 
   // system clear the port before trying again
   
   return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
   // listen for a connection
   const int serverMaxBacklog = 10;
   listen (serverSocket, serverMaxBacklog);
   
   // accept the connection
   struct sockaddr_in clientAddress;
   socklen_t clientLen = sizeof (clientAddress);
   int connectionSocket = 
      accept (
         serverSocket, 
         (struct sockaddr *) &clientAddress, 
         &clientLen
      );
   
   assert (connectionSocket >= 0);
   // error on accept
   
   return (connectionSocket);
}


int escapeSteps(double x, double y) {
    int steps = 0;
    imaginaryPoint previous = {0,0};
    imaginaryPoint current = {x,y};
    double distance = 0;
    while (distance < MAX_VALUE && steps < MAX_STEPS) {
        imaginaryPoint squaredPrevious =  squarePoint(previous);
        previous = addPoints(squaredPrevious,current);
        distance = calculateDistance(previous);
        steps += 1;
    }
    return steps;
}

imaginaryPoint addPoints(imaginaryPoint pointOne, imaginaryPoint pointTwo) {
    imaginaryPoint newPoint = {pointOne.real + pointTwo.real,pointOne.imaginary + pointTwo.imaginary};
    return newPoint;
} 

imaginaryPoint squarePoint(imaginaryPoint point) {
    double newReal = pow(point.real,2) - pow(point.imaginary,2);
    double newImaginary = 2 * (point.real * point.imaginary);
    imaginaryPoint newPoint = {newReal,newImaginary};
    return newPoint;
}

double calculateDistance(imaginaryPoint point) {
    double distance = sqrt(pow(point.real,2) + pow(point.imaginary,2));
    return distance;
}

