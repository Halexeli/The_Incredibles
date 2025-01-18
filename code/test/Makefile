CC = g++
#changer ceci pour linux: 
#CCFLAGS = -Wall -Werror -std=c++11 -g -I../ -I/usr/include
#LDFLAGS = -L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system
CCFLAGS = -Wall -Werror -std=c++11 -g -I../ -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = ../code
FIGURE_DIR = $(SRC_DIR)/Figure
SPIROGRAPH_DIR = $(SRC_DIR)/Spirographe
DISPLAY_DIR = $(SRC_DIR)/Affichage
TEST_DIR = .
SRC = $(wildcard $(FIGURE_DIR)/*.cc) $(wildcard $(SPIROGRAPH_DIR)/*.cc) $(wildcard $(DISPLAY_DIR)/*.cc)
OBJ = $(SRC:.cc=.o)
TST = $(wildcard $(TEST_DIR)/*.cpp)
OBJ_TEST = $(OBJ) $(TST:.cpp=.o)
testcase.out: $(OBJ_TEST)
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@
%.o: %.cc
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ_TEST) testcase.out
.depends:
	$(CC) -MM $(SRC) $(TST) > .depends
-include .depends