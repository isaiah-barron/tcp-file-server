#ifndef SOCKET_API_H
#define SOCKET_API_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <iostream>

namespace net {
    int Socket(int domain, int type, int protocol);
    void Setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t option_len);
    void Getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res);
    void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    void Listen(int sockfd, int backlog);
    int Accept(int sockfd, struct sockaddr *address, socklen_t  *address_len);
    int Send(int sockfd, const void *buf, size_t len, int flags);
    int Recv(int sockfd, void *buf, size_t len, int flags);
}

#endif