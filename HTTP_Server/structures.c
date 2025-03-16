#include<stdio.h>
#include<ctype.h>
#include<arpa/inet.h>
#include<errno.h>

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

struct sockaddr_in  //for IPv4
{
	short int          sin_family;
	unsigned short int sin_port;
	struct in_addr     sin_addr;
	unsigned char      sin_zero[8];
};

struct in_addr
{
	uint32_t s_addr;
};

struct sockaddr_storage
{
	sa_family_t    ss_family; //To check if IPv4 or IPv6
	char           __ss_pad1[__SS_PAD1SIZE];
	int64_t        __ss_align;
	char           __ss_pad2[__SS_PAD2SIZE];
};

struct sockaddr_in sa; //An IPv4 socket

if(inet_pton(AF_INET, "10.12"):
		perror("Not able to translate address to it's binary representation.");

