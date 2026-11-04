#include "utils.h"

#define SEARCH_PATH "tmp/"
#define MAXLINE 4096
#define SERVER_PORT 8989

/**
 * argv[1] = file to read on the server
 */
int main(int argc ,char** argv){
   int sockfd, n;
   int sendbytes;
   struct sockaddr_in servaddr;
   char sendline[MAXLINE];
   char recvline[MAXLINE];
   char msgerror[100];

   if (argc <= 1) {
     sprintf(msgerror, "usage: %s <file to bring from server>", argv[0]);
     fprintf(stderr, "%s\n", msgerror);
     exit(1);
   }
   
   printf("Create socket\n");
   check((sockfd = socket(AF_INET, SOCK_STREAM, 0)), "Error while creating the socket");
   
   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(SERVER_PORT);
   
   check(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) ,"inet_pton error for %s argv[1]");

   printf("Connecting to server on port %d\n", SERVER_PORT);
   check(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)), "connect failed");
   
   strcat(sendline, SEARCH_PATH);
   strcat(sendline, argv[1]);
   //for test sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
   sendbytes = strlen(sendline);

   printf("Sending request: %s\n", sendline);
   check((write(sockfd, sendline, sendbytes) != sendbytes), "write error\n");
   
   memset(recvline, 0, MAXLINE);

   printf("Receiving response from server.\n");
   while (( n = read( sockfd, recvline, MAXLINE - 1)) > 0) {
     printf("%s", recvline);
   }
   check( (n < 0), "read error\n");
}
