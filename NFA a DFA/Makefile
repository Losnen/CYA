CXX= g++
CXXFLAGS= -g -o nfa.x

OBJS = nfa.o estado.o transicion.o main.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o nfa ${OBJS}

clean: 
	rm *.*~ *~ *.o nfa 
	
