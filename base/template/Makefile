CXX := g++
CXXFLAGS := -std=c++11

SRCS := function_template.cc
OBJS := function_template.out

all: test

test: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(OBJS)

clean:
	rm -f $(OBJS)
