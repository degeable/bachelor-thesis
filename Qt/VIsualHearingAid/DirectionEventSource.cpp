#include "DirectionEventSource.h"

using std::cerr;
using std::cout;
using std::endl;
using std::hex;
using std::vector;
using std::runtime_error;


DirectionEventSource::DirectionEventSource(int port)
: calibrationOffset(0), _port(port), _state(NOT_CONNECTED), _sockfd(-1), _connfd(-1)
{
}

DirectionEventSource::~DirectionEventSource()
{
    static char buf[sizeof(int)];
    while (recv(_connfd, &buf, sizeof(int), 0) > 0) {}
    close(_connfd);
    while (recv(_sockfd, &buf, sizeof(int), 0) > 0) {}
    close(_sockfd);
    qInfo() << "DirectionEventsockets closed" << endl;
}

void DirectionEventSource::closeSocket()
{
    close(_connfd);
    close(_sockfd);
}

void DirectionEventSource::calibrateOffset()
{
    if (0 != _port) //only change the offset if we use real data
        calibrationOffset = get();
}


int DirectionEventSource::get()
{


    if (0 == _port)
    {
      return 100; //Dummy data
    }
    else
    {
        // receive data from port
        static char data[sizeof(int)];

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
                qInfo() << "DirectionEvent socket connected" << endl;
                _state = SOCKET_ACCEPTED;
            }
        }
        if(SOCKET_ACCEPTED == _state)
        {
            // process available data
            int angle;
            int n = read(_connfd, data, sizeof(data)-1);
            if (n>0)
            {
                data[n] = '\0';
                angle = atoi(data);
                return angle;
            }
            else
            {
                qInfo() << "DirectionEvent socket connection closed" << endl;
                close(_connfd);
                _state = SOCKET_LISTENING;
            }
        }
    }

    return -1;
}

int DirectionEventSource::getPort()
{
    return _port;
}

int DirectionEventSource::getCalibrationOffset() const
{
    return calibrationOffset;
}

