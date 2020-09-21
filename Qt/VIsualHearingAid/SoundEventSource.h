#ifndef _SoundEventSource_h_
#define _SoundEventSource_h_

#include <QDebug>

#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>

#include "SoundEvent.h"

using std::vector;

enum states {NOT_CONNECTED, SOCKET_CREATED, SOCKET_BOUND,
    SOCKET_LISTENING, SOCKET_ACCEPTED};

class SoundEventSource
{
public:
    SoundEventSource(int port);
    ~SoundEventSource();
    vector<SoundEvent> get();
    void closeSocket();
    int getPort() const;
    void setPort(int port);

    states getState() const;
    void setState(states state);

private:
    int _port;
    vector<SoundEvent> _result;

    states _state;
    int _sockfd;
    int _connfd;
    struct sockaddr_in _servaddr;
    struct sockaddr_in _clientAddress;
};

#endif
