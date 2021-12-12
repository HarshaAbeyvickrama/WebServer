#include "HTTPRequest.h"
#include <string.h>
#include <stdlib.h>

int getMethod(char *method){
    if(strcmp(method , "GET") == 0){
        return GET;
    }else if(strcmp(method , "POST") == 0){
        return POST;
    }else if(strcmp(method , "PUT") == 0){
        return PUT;
    }else if(strcmp(method , "HEAD") == 0){
        return HEAD;
    }else if(strcmp(method , "PATCH") == 0){
        return PATCH;
    }else if(strcmp(method , "CONNECT") == 0){
        return CONNECT;
    }else if(strcmp(method , "OPTIONS") == 0){
        return OPTIONS;
    }else if(strcmp(method , "TRACE") == 0){
        return TRACE;
    }else{
        return -1;
    }
}

struct HTTPRequest httpRequestConstructor(char *request){

    struct HTTPRequest httpRequest;
    char requested[strlen(request)];
    strcpy(requested , request);

    for(int i = 0 ; i< strlen(requested) - 1 ; i++){
        if(requested[i] == '\n' && requested[i+1] == '\n'){
            requested[i+1] = '|';
        }
    }
    char *requestLine = strtok(requested , "\n");
    char *headers = strtok(NULL, "|");
    char *body = strtok(NULL , "|");

    
    char *method = strtok(requestLine , " ");
    httpRequest.Method = getMethod(method);

    char *URI = strtok(NULL , " ");
    httpRequest.URI = URI;

    char *httpVersion = strtok(NULL , " ");
    httpVersion = strtok(httpVersion , "/");
    httpVersion = strtok(NULL , "/");

    httpRequest.HTTPVersion = (float)atof(httpVersion);

    return httpRequest;
    

}