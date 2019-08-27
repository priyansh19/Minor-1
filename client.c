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
    
    int sockfd, newsockfd,portno,n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[255];
    if (argc<3)
    {
        fprintf(stderr,"usage %s hostname port \n",argv[0]);
        exit(1);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        printf("socket function fails\n");
    }
    server = gethostbyname(argv[1]);//getting ip address
    if (server == NULL)
    {
        printf("give correct ip info ie no host");
    }
    bzero((char *)&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family= AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port= htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
    {
        error("connection failed");
    }
while(1)
{
    bzero(buffer,255);
    fgets(buffer,255,stdin);
    n = write(sockfd , buffer , strlen(buffer));
    if (n<0)
    {
        error("error on writing");
        
    }
    bzero(buffer,255);
    n = read (sockfd,buffer,225);
    if (n<0)
    {
        error("error on reading");
    }
    printf("server: %s",buffer );
    int a  = strncmp("bye",buffer,3);
    if (a ==0)
    {
        break;
    }
}
    close(sockfd);
    return 0;



}
