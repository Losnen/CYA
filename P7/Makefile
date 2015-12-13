CXX= g++
CXXFLAGS= -g -o nfa.x

OBJS = dfa_t.o estado_t.o transicion_t.o GR.o main.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o dfa ${OBJS}

clean: 
	rm *.*~ *~ *.o dfa
	
