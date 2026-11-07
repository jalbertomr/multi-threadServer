CC=gcc
CFLAGS= -g
UTILS_OBJS= utils.o

all: $(UTILS_OBJS) server singleThreadServer client

utils: utils.h utils.c
	$(CC) $(CFLAGS) -c utils.c

server: server.c $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o server server.c $(UTILS_OBJS)

singleThreadServer: singleThreadServer.c $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o singleThreadServer singleThreadServer.c $(UTILS_OBJS)

client: client.c $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o client client.c $(UTILS_OBJS)

clean:
	rm -rf *.dSYM server client