#include <socket_api.hh>

namespace net{

     int Socket(int domain, int type, int protocol){
        int sockfd = socket(domain, type, protocol);
        if (sockfd < 0){
            perror("Failed to create socket");
            exit(EXIT_FAILURE);
        }
        return sockfd;
    }

    void Getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res){
        if (getaddrinfo(node, service, hints, res) < 0){
            perror("Could not get address info");
            exit(EXIT_FAILURE);
        }
    }

    void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
        if (bind(sockfd, addr, addrlen) < 0){
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
    }

    void Listen(int sockfd, int backlog){
        if (listen(sockfd, backlog) < 0){
            perror("listen failed");
            exit(EXIT_FAILURE);
        }
    }

    int Accept(int sockfd, struct sockaddr *address, socklen_t  *address_len){
        int connfd = accept(sockfd, address, address_len);
        if (connfd < 0){
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        return connfd;
    }

    int Send(int sockfd, const void *buf, size_t len, int flags){
        int sent = send(sockfd, buf, len, flags);
        if (sent <= 0){
            std::cout << "Disconnected or error\n";
        }
        return sent;
    }

    int Recv(int sockfd, void *buf, size_t len, int flags){
        int recieved = recv(sockfd, buf, len, flags);
        if (recieved <= 0){
            std::cout << "Disconnected or error\n";
        }
        return recieved;
    }
}