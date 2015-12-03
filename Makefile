CC = gcc

snail_search : snail_search.o
	$(CC) -o snail_search snail_search.o
snail_search.o : snail_search.c
	$(CC) -c snail_search.c -g

clean:
	rm -rf snail_search snail_search.o
