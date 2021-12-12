#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Server.h"

void launch(struct Server *server){
    char buffer[30000];
    int addrlen = sizeof(server->address);
    int newSocket;
    char *hello = "HTTP/1.1 200 OK\nDate: Mon, 27 Jul 2009 12:28:53 GMT\nServer: Apache/2.2.14 (Win32)\nLast-Modified: Wed, 22 Jul 2009 19:15:56 GMT\nContent-Type: text/html\nConnection: Closed\n\n<html><body><h1>Hello</h1></body></html>";

    while (1){
        printf("Waiting for connections...\n");
        newSocket = accept(server->socket , (struct sockaddr *)&server->address , (socklen_t *)&addrlen);
        bzero(buffer , sizeof(buffer));
        read(newSocket , buffer , 30000);
        printf("%s\n" , "====================================================");
        printf("%s\n" , buffer);
        write(newSocket , hello , strlen(hello));
        close(newSocket);
    }
    
}

int main(){
    struct Server server = server_constructor(AF_INET , SOCK_STREAM , 0 , INADDR_ANY , 2222 , 10 , launch);
    server.launch(&server);
}