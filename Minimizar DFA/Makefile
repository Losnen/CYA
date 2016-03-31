CXX=g++
CXXFLAGS=-g

OBJS = dfa.o estado.o transicion.o main.o
all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o dfa ${OBJS}

clean: 
	rm -rf $(OBJS) 