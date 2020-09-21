#include <iostream>
#include <exception>

#include <cmath>	//sqrt
#include <cstdlib>	//atof
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <poll.h>
#include <errno.h>
#include <netinet/in.h>

#include <vector>

#include "SoundEventSource.h"
#include "SoundEvent.h"

using std::cerr;
using std::endl;
using std::hex;
using std::vector;
using std::runtime_error;

#include "test2.h"

SoundEventSource::SoundEventSource(int port)
: _port(port), _state(NOT_CONNECTED), _sockfd(-1), _connfd(-1)
{
}

SoundEventSource::~SoundEventSource()
{
    static char buf[2048];
    while (recv(_connfd, &buf, 2048, 0) > 0) {}
    close(_connfd);
    while (recv(_sockfd, &buf, 2048, 0) > 0) {}
    close(_sockfd);
    qDebug() << "SoundEvent sockets closed" << endl;
}


vector<SoundEvent> SoundEventSource::get()
{
    _result.clear();

    if (0 == _port)
    {
        // simulate receiving from test data (array of struct from test1.h / test2.h)
        static int timeStamp=1;
        static int index=0;

        for(;index < (sizeof(test)/(4*sizeof(float)+sizeof(int))) && timeStamp==test[index].timeStamp;index++)
        {
            float length = sqrt(test[index].x*test[index].x + test[index].y*test[index].y);

            if (0.0 != length)
            {
                test[index].secondsAgo = 0.0;
                // normalize to 2 dimensional vector in x/y plane
                test[index].x /= length;
                test[index].y /= length;
                _result.push_back(test[index]);
            }
        }
        timeStamp++;
    }
    else
    {
        // receive data from port
        static char data[2048];

        if(NOT_CONNECTED == _state)
        {
            // open socket
            _sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (_sockfd == -1) {
                throw runtime_error("could not create socket");
            }
            _state = SOCKET_CREATED;

            // bind socket
            _servaddr.sin_family = AF_INET;
            _servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
            _servaddr.sin_port = htons(_port);

            if ((bind(_sockfd, (const sockaddr*) &_servaddr, sizeof(_servaddr))) != 0) {
                throw runtime_error("could not bind socket");
            }
            _state = SOCKET_BOUND;

            // listen socket
            if ((listen(_sockfd, 5)) != 0) {
                throw runtime_error("could not listen on socket");
            }
            _state = SOCKET_LISTENING;
        }
        if(SOCKET_LISTENING == _state)
        {
            // see if a connection is requested
            static struct pollfd fdsServer = { .fd = _sockfd, .events = POLLIN};
            poll(&fdsServer, 1	, 0);

            if (fdsServer.revents & POLLIN)
            {
                // accept connection
                socklen_t n = sizeof(_clientAddress);
                _connfd = accept(_sockfd, (sockaddr*) &_clientAddress, &n);
                if ( (_connfd < 0))
                {
                    cerr << _connfd << endl;
                    throw runtime_error("server acccept failed...\n");
                }
                qInfo() << "SoundEvent Socket connected" << endl;
                _state = SOCKET_ACCEPTED;
            }
        }
        if(SOCKET_ACCEPTED == _state)
        {
            // process available data
            int n = read(_connfd, data, sizeof(data)-1);
            if (n>0)
            {
                data[n] = '\0';

                // don't really parse, just pick for now... :/
                SoundEvent soundEvent = {0, 0,0,0,0, 0, 0,0,0,0};

                soundEvent.secondsAgo = 0.0;
                for(int i = 0; i<n; i++)
                {
                    if (data[i] == 'x' && i+3 < n && data[i+1] == '"')
                    {
                        soundEvent.x = atof(&data[i+3]);
                        i+=3;
                    }
                    if (data[i] == 'y' && i+3 < n && data[i+1] == '"')
                    {
                        soundEvent.y = atof(&data[i+3]);
                        i+=3;
                    }
                    if (data[i] == 'z' && i+3 < n && data[i+1] == '"')
                    {
                        soundEvent.z = atof(&data[i+3]);
                        i+=3;
                    }
                    // id (for sst)
                    if (data[i] == 'i' && i+4 < n && data[i+1] == 'd' && data[i+2] == '"')
                    {
                        soundEvent.id = atoi(&data[i+4]);
                        i+=4;
                    }
                    if (data[i] == 'E' && i+3 < n && data[i+1] == '"')
                    {
                        soundEvent.E = atof(&data[i+3]);
                        i+=3;

//						// discard low energy events
//						if (soundEvent.E < 0.1) break;

                        // normalize to 2 dimensional vector in x/y plane
                        float length = sqrt(soundEvent.x*soundEvent.x + soundEvent.y*soundEvent.y);
                        if (0!=length)
                        {
                            soundEvent.x /= length;
                            soundEvent.y /= length;
                            _result.push_back(soundEvent);
                        }
                    }
                    // record activity (for sst) as Energy
                    if (data[i] == 'a' && i+11 < n && data[i+1] == 'c')
                    {
                        soundEvent.E = 0.5 * atof(&data[i+11]);
                        i+=11;

                        // discard low energy events
//						if (soundEvent.E < 0.001) break;

                        // normalize to 2 dimensional vector in x/y plane
                        float length = sqrt(soundEvent.x*soundEvent.x + soundEvent.y*soundEvent.y);
                        if (0!=length)
                        {
                            soundEvent.x /= length;
                            soundEvent.y /= length;
                            _result.push_back(soundEvent);
                        }
                    }
                }
            }
            else
            {
                qInfo() << "SoundEvent Socket connection closed" << endl;
                close(_connfd);
                _state = SOCKET_LISTENING;
            }
        }
    }

    return _result;
}

void SoundEventSource::closeSocket()
{
    close(_connfd);
    close(_sockfd);
}

int SoundEventSource::getPort() const
{
    return _port;
}

void SoundEventSource::setPort(int port)
{
    _port = port;
}

states SoundEventSource::getState() const
{
    return _state;
}

void SoundEventSource::setState(states state)
{
    _state = state;
}

