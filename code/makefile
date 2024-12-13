CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g 
SFML= -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard ../*.cc)
OBJ= $(SRC:.cc=.o)
TST= $(wildcard *.cc)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cc=.o) 
%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $< $(SFML)

# Replace "src" with the name of the folder where all your cpp code is
cppFileNames := $(shell find ./Figure -type f -name "*.cpp")

all: compile

compile:	
	mkdir -p bin
	g++ $(cppFileNames) -I$(SFML_PATH)/include -o bin/app -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network


main.out : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^ $(SFML)

main: main.out
	./main.out

clean :
	rm -f $(OBJ_TEST) main.out
