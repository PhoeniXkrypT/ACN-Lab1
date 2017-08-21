#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main()
{
   struct sockaddr_in server, client;
   int sfd,num,sock;
   char buf1[1500]="",buf2[1500]="";
   sfd=socket(AF_INET,SOCK_STREAM,0);// socket is created
   if(sfd<0)
     printf("Socket error.");
   else
     printf("Socket created.");
   server.sin_family=AF_INET;
   server.sin_port=htons(3000);
   server.sin_addr.s_addr=htonl(INADDR_ANY);
   bind(sfd,(struct sockaddr *)&server,sizeof server);// binding
   listen(sfd,5);// listening, backlog = 5
    printf("\nServer ready!");
    printf("\n");
    num=sizeof client;
   sock=accept(sfd,(struct sockaddr *)&client,&num);
 
    while(1)
    {
      recv(sock,buf1,sizeof buf1,0);
        if(strcmp(buf1,"end")==0)
            break;
      printf("\nClient:%s",buf1);
      printf("\nServer:");
      scanf("%s",buf2);
      send(sock,buf2,sizeof buf2,0);
        if(strcmp(buf2,"end")==0)
            break;
     
    }
    close(sock);
   close(sfd);
}
