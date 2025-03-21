#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include"structures.c"

int main()
{
	int sockfd;
	struct addrinfo hints, *res;

	if(getaddrinfo("www.google.com","https", &hints, &res))
	{
		fprintf(stderr, "Not able to fetch address IP.");
		return -1;
	}

	if(sockfd = socket(res -> ai_family, res-> ai_socktype, res-> ai_protocol))
	{
		bind(&hints, 0, sizeof hints);
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_flags = AI_PASSIVE; //AI_PASSIVE is used to tell the compiler to bind to host's IP
		
		
		if(getaddrinfo(NULL,"3490", &hints, &res) < 0)
		{
			
			fprintf(stderr, "Not able to fetch address IP.");
			return -2;
		}

		sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

		//Binding the socket to the port we passed in getaddrinfo()
		if(bind(sockfd, res->ai_addr, res->ai_addrlen))
		{
			fprintf(stderr, "Unable to bind to port.");
			return -3;
		}
	}

