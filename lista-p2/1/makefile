CC = g++
CFLAGS = -std=c++11 -Wall

all: main

main: main.o FormaBasica.o Circulo.o Retangulo.o Triangulo.o Quadrado.o
	$(CC) $(CFLAGS) -o main main.o FormaBasica.o Circulo.o Retangulo.o Triangulo.o Quadrado.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

FormaBasica.o: FormaBasica.cpp FormaBasica.h
	$(CC) $(CFLAGS) -c FormaBasica.cpp

Circulo.o: Circulo.cpp Circulo.h FormaBasica.h
	$(CC) $(CFLAGS) -c Circulo.cpp

Retangulo.o: Retangulo.cpp Retangulo.h FormaBasica.h
	$(CC) $(CFLAGS) -c Retangulo.cpp

Triangulo.o: Triangulo.cpp Triangulo.h FormaBasica.h
	$(CC) $(CFLAGS) -c Triangulo.cpp

Quadrado.o: Quadrado.cpp Quadrado.h Retangulo.h FormaBasica.h
	$(CC) $(CFLAGS) -c Quadrado.cpp

clean:
	rm -rf *.o main
