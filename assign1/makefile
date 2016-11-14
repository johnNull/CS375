all: submission

submission: difference.o
	g++ -std=c++11 difference.o -o submission
difference.o: difference.cpp
	g++ -std=c++11 -c difference.cpp
r1:
	./submission input.txt output.txt
r2:
	./submission input2.txt output.txt
r3:
	./submission input3.txt output.txt
clean:
	rm -f *.o *~ submission
