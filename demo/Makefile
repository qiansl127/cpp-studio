CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall -pedantic

all: demo

demo: demo.o Array.o
	$(CXX) $(CXXFLAGS) -o demo demo.o Array.o

demo.o: Array.h
#	$(CXX) $(CXXFLAGS) -c demo.cpp

Array.o: Array.h
#	$(CXX) $(CXXFLAGS) -c Array.cpp

clean:
	rm -f *.o demo
