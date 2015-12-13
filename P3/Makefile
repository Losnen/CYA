CXX=g++
CXXFLAGS= -g

OBJS = DFA.o estado.o main.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o dfa ${OBJS}

clean: 
	rm *.*~ *~ *.o dfa