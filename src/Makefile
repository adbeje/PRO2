OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Almacen.o Estanteria.o Inventario.o
	g++ -o program.exe *.o 
	
program.o: program.cc Almacen.hh
	g++ -c program.cc $(OPCIONS)
	
Almacen.o: Almacen.cc Almacen.hh Estanteria.hh BinTree.hh Inventario.hh
	g++ -c Almacen.cc $(OPCIONS) 

Estanteria.o: Estanteria.cc Estanteria.hh Inventario.hh
	g++ -c Estanteria.cc $(OPCIONS) 

Inventario.o: Inventario.cc Inventario.hh
	g++ -c Inventario.cc $(OPCIONS) 

practica.tar: program.cc Almacen.cc Almacen.hh Estanteria.cc Estanteria.hh Inventario.cc Inventario.hh
	tar -cvf practica.tar program.cc Almacen.cc Almacen.hh Estanteria.cc Estanteria.hh Inventario.cc Inventario.hh Makefile html.zip jp_adria.ventura.zip

clean:
	rm *.o
	rm *.exe
