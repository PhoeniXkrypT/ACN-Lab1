#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main()
{
  int sfd,sock;
  char buf1[1500]="",buf2[1500]=""; // Initialising
  struct sockaddr_in server;
   sfd=socket(AF_INET,SOCK_STREAM,0);
    if(sfd<0)
     printf("Socket error.");
   else
     printf("Socket created.");
    server.sin_family=AF_INET;
    server.sin_port=htons(3000);
    server.sin_addr.s_addr=htonl(INADDR_ANY);
    printf("\nClient ready !\n");
    connect(sfd,(struct sockaddr *)&server,sizeof server);
   while(1)
    {
       printf("\nClient:");
       scanf("%s",buf2);
      send(sfd,buf2,sizeof buf2,0);
        if(strcmp(buf2,"end")==0)
            break;
      recv(sfd,buf1,sizeof buf1,0);
        if(strcmp(buf1,"end")==0)
            break;
       printf("\nServer:%s",buf1);
    }
    close(sfd);
}
