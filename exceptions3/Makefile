CXX = g++
EXEC = main
CXXFLAGS +=  -pedantic -Wall -std=c++11
LIBS = -lm

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

$(EXEC): $(OBJ) 
	$(CXX) $(FLAGS) $^ -o $@

.PHONY: clean run check

clean:
	@rm -f $(EXEC) $(OBJ) $(DEP)
run:
	@./$(EXEC)
check:
	@valgrind ./$(EXEC)

-include $(DEP)