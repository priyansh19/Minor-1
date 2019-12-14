#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>//for read write and close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>//for host .. name ,protocal ipv4 
//filename server_ipaddress port no
void error(const char *msg)
{
    perror(msg);
    exit(1);
}
int main(int argc , char *argv[])// 2 , file naam and port number
{
    if (argc<2)
    {
        printf("bro you have to give port no\n");//use of stderr
        exit(1);
    }
    int sockfd, newsockfd,portno,n;
    char buffer[255];
    struct sockaddr_in server_addr , cli_addr;
    socklen_t clilen;// data type in socket programming
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        printf("socket function fails\n");
    }
    bzero((char *)&server_addr ,sizeof(server_addr));//clears all  the buffers and messages
    portno = atoi(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port= htons(portno);
    if(bind(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr))<0)
    {
        error("binding failed");
    }
    listen(sockfd, 5);//who is on the same port , 5 shows no of conection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd<0)
    {
        error("error on accepting the connection");
        
    }
    while(1)
    {
        bzero(buffer,250);
        n = read(newsockfd,buffer,250);
        if (n<0)
        {
            error("error on reading");
        }
        printf("client: %s\n",buffer);
        bzero(buffer, 255);
        fgets(buffer,255,stdin);
        n = write(newsockfd,buffer,strlen(buffer));
        if(n<0)
        {
            error("error on writing");
        }
        int a  = strncmp("bye",buffer,3);
        if (a ==0)
        {
            break;
        }
    }
    close(newsockfd);
    close(sockfd);
    return 0;
}
