#ifndef HTTPRequest_h
#define HTTPRequest_h

enum HTTPMethods{
    GET,
    POST,
    PUT,
    DELETE,
    HEAD,
    PATCH,
    CONNECT,
    OPTIONS,
    TRACE
};

struct HTTPRequest{
    int Method;
    char* URI;
    float HTTPVersion;
};

struct HTTPRequest httpRequestConstructor(char *request);

#endif