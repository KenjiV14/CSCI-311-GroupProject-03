all: ServerG ServerC client

client: client.c
	$(CC) $(CFLAGS) -o client client.c rpsGame.c

ServerC: ServerC.c
	$(CC) $(CFLAGS) -o ServerC ServerC.c rpsGame.c

ServerG: ServerG.c
	$(CC) $(CFLAGS) -o ServerG ServerG.c rpsGame.c

clean:
	rm -f ServerC
	rm -f ServerG
	rm -f client