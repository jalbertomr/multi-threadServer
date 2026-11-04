#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVERPORT 8989
#define BUFFER_SIZE 4096
#define SOCKETERROR -1
#define PATH_MAX 4096
#define SOCKERERROR -1
#define SERVER_BACKLOG 3

int check(int exp, const char* msg);
void handle_connection(int client_socket);

int main(int argc, char* argv[]) {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int addrlen = sizeof(address);

  // Create socket file descriptor
  check((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0, "socket failed");

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(SERVERPORT);

  // Bind the socket to the specified port
  check(bind(server_fd, (struct sockaddr*)&address, sizeof(address)),
        "bind failed.");

  // Start listening for incoming connections
  check(listen(server_fd, SERVER_BACKLOG), "listen failed.");

  printf("Server listening on port %d\n", SERVERPORT);

  while(1) {
    // Accept incoming connection
    printf("Waiting for a new connection...\n");
    check(new_socket = accept(server_fd, (struct sockaddr*)&address,
                              (socklen_t*)&addrlen),
          "accept failed.");

    printf("Accepted new connection\n");

    // Handle the connection in a new thread or process as needed
    // For simplicity, we will just close the socket here
    handle_connection(new_socket);
  }

  return 0;
}

void handle_connection(int client_socket) {
  char buffer[BUFFER_SIZE];
  int msgsize = 0;
  size_t bytes_read;
  char actual_path[PATH_MAX];

  bytes_read =
      read(client_socket, buffer + msgsize, sizeof(buffer) - msgsize - 1);
  printf("Read %ld bytes from client, buffer:%s\n", bytes_read, buffer);
  msgsize += bytes_read;

  check(bytes_read, "read(...) error\n");
  buffer[msgsize] = '\0';  // Null-terminate the string

  printf("Received message: %s\n", buffer);
  fflush(stdout);  // Ensure the message ¡(is printed immediately

  printf("Resolving real path for: %s actual_path:%s\n", buffer, actual_path);
  if (realpath(buffer, actual_path) == NULL) {
    fprintf(stdout, "Invalid path received: %s\n", buffer);
    check(write(client_socket, buffer, strlen(buffer)), "write");
    close(client_socket);
    return;
  }

  printf("Opening file: %s\n", actual_path);
  FILE* file = fopen(actual_path, "r");
  if(file == NULL) {
    perror("fopen");
    close(client_socket);
    return;
  }

  printf("Sending file contents to client...\n");
  // Read the file and send its contents to the client
  while((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
    check(write(client_socket, buffer, bytes_read), "write");
  }
  close(client_socket);
  fclose(file);
  printf("File sent successfully\n");
}