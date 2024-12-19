CC=gcc
CFLAGS=-Wall

all: pbuild pview psum psub

psum: poly.o psum.c
		$(CC) $(CFLAGS) psum.c poly.o -o psum

pview: poly.o pview.c
		$(CC) $(CFLAGS) pview.c poly.o -o pview

poly.o: poly.h poly.c
		$(CC) $(CFLAGS) -c poly.c -o poly.o

pbuild: poly.o pbuild.c
		$(CC) $(CFLAGS) pbuild.c poly.o -o pbuild

psub: poly.o psub.c
		$(CC) $(CFLAGS) psub.c poly.o -o psub

clean:
	$(RM) poly.o pbuild pview psum psub
