C=gcc
CFLAGS= -g
UTILS_OBJS= utils.o

all: $(UTILS_OBJS) multiThreadServer singleThreadServer client

utils: utils.h utils.c
	$(CC) $(CFLAGS) -c utils.c

multiThreadServer: multiThreadServer.c $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o multiThreadServer multiThreadServer.c $(UTILS_OBJS)

singleThreadServer: singleThreadServer.c $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o singleThreadServer singleThreadServer.c $(UTILS_OBJS)

client: client.c $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o client client.c $(UTILS_OBJS)

clean:
	rm -rf *.dSYM *.o multiThreadServer singleThreadServer client