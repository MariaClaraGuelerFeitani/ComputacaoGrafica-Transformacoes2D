all: compila executa
compila: main.o desenharLinha.o poligono.o tela.o viewPort.o
	gcc main.o desenharLinha.o poligono.o tela.o viewPort.o -o prog
main.o: main.c
	gcc -c main.c
desenharLinha.o: desenharLinha.c
	gcc -c desenharLinha.c
poligono.o: poligono.c
	gcc -c poligono.c
tela.o: tela.c
	gcc -c tela.c
viewPort.o: viewPort.c
	gcc -c viewPort.c
executa:
	./prog
clean:
	del main.o desenharLinha.o poligono.o tela.o viewPort.o prog.exe