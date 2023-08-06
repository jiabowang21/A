OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

basics.exe: basics.o practica.o
	g++ -o basics.exe basics.o practica.o

greedy.exe: greedy.o practica.o
	g++ -o greedy.exe greedy.o practica.o

local_search.exe: local_search.o practica.o
	g++ -o local_search.exe local_search.o practica.o

practica.o: practica.cc practica.hh
	g++ -c practica.cc $(OPCIONS)

basics.o: basics.cc practica.hh
	g++ -c basics.cc $(OPCIONS)

greedy.o: greedy.cc practica.hh
	g++ -c greedy.cc $(OPCIONS)

local_search.o: local_search.cc practica.hh
	g++ -c local_search.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
