#include<stdio.h>
#include<ctype.h>

struct sockaddr
{
	unsigned short       sa_family;
	char                 sa_data[14];
};

struct addrinfo
{
	int    ai_flags;
	int    ai_family;
	int    ai_socktype;
	int    ai_protocol;
	size_t ai_addrlen;  //unsigned integer of 32 or 64 bits
	struct sockaddr *ai_addr;
	char   *ai_canonname;

	struct addrinfo *ai_next
};

