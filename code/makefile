CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g 
SFML= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard ../*.cc)
OBJ= $(SRC:.cc=.o)
TST= $(wildcard *.cc)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cc=.o) 

main.out : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^ $(SFML)

main: main.out
	./main.out
%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $< $(SFML)

clean :
	rm -f $(OBJ_TEST) main.out
