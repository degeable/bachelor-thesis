#ifndef DIRECTIONEVENTSOURCE_H
#define DIRECTIONEVENTSOURCE_H

#include <QDebug>

#include <iostream>
#include <exception>
#include <cmath>	//sqrt
#include <cstdlib>	//atof
#include <unistd.h>
#include <fcntl.h>
#include <vector>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>

using std::cout;
using std::endl;

class DirectionEventSource
{
public:
    DirectionEventSource(int port);
    ~DirectionEventSource();
    void closeSocket();
    void calibrateOffset();
    int get();
    int getPort();
    int getCalibrationOffset() const;

private:
    int calibrationOffset;
    int _port;
    enum states {NOT_CONNECTED, SOCKET_CREATED, SOCKET_BOUND,
        SOCKET_LISTENING, SOCKET_ACCEPTED} _state;
    int _sockfd;
    int _connfd;
    struct sockaddr_in _servaddr;
    struct sockaddr_in _clientAddress;

};

#endif // DIRECTIONEVENTSOURCE_H
