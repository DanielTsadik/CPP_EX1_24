CXX=clang++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp Demo.cpp Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: demo test

demo: $(OBJECTS) Demo.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(OBJECTS) TestCounter.o Test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o demo test
