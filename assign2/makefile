submission: assign2.o
	g++ -std=c++11 assign2.o -o submission
assign2.o: assign2.cpp point.h
	g++ -std=c++11 -c assign2.cpp
bruteforce: bruteforce.o
	g++ -std=c++11 bruteforce.o -o bruteforce
bruteforce.o: bruteforce.cpp point.h
	g++ -std=c++11 -c bruteforce.cpp
clean:
	rm *~ *.o submission bruteforce
run:
	./submission input.txt output.txt
run2:
	./bruteforce input.txt output.txt
