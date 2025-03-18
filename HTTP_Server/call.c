#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include"structures.c"

/* int getaddrinfo(const char *node,
 * 		   const char *service,
 * 		   const struct addrinfo *hints,
 * 		   struct addrinfo **res);
 */

int status;
struct addrinfo hints;
struct addrinfo *servinfo; // It'll point to the result

memset(&hints, 0 , sizeof hints); //It'll make sure the struct is empty
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;
hints.ai_flags = AI_PASSIVE;
