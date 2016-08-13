CXX := g++
CXXFLAGS := -std=c++11

SRCS := swapTest.cc
OBJS := swapTest.out

all: test

test: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(OBJS)

clean:
	rm -f $(OBJS)
