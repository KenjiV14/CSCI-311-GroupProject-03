all: ServerC client

client: client.c
	$(CC) $(CFLAGS) -o client client.c

ServerC: ServerC.c
	$(CC) $(CFLAGS) -o ServerC ServerC.c

clean:
	rm -f ServerC
	rm -f client