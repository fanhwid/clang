main: main.o redirect_ptr.o
	gcc main.o redirect_ptr.o -o main

main.o: main.c redirect_ptr.h
redirect_ptr.o: redirect_ptr.c redirect_ptr.h

clean:
	-rm main *.o
