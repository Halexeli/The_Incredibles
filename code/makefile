XX = g++
# pour linux nrmlt c ça: 
CXXFLAGS = -Wall -g  
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
#sur mac:
#CXXFLAGS = -Wall -g -I/opt/homebrew/include 
#LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = code 
#j'ai spécifié les directories
FIGURE_DIR = $(SRC_DIR)/Figure
SPIROGRAPH_DIR = $(SRC_DIR)/Spirographe
DISPLAY_DIR = $(SRC_DIR)/Affichage
TEST_DIR = $(SRC_DIR)/test

#source files
SRC = $(wildcard $(FIGURE_DIR)/*.cc) $(wildcard $(SPIROGRAPH_DIR)/*.cc) $(wildcard $(DISPLAY_DIR)/*.cc) main.cpp
OBJ = $(SRC:.cc=.o)
DEPS = $(wildcard $(FIGURE_DIR)/*.hh) $(wildcard $(SPIROGRAPH_DIR)/*.hh) $(wildcard $(DISPLAY_DIR)/*.hh)

TARGET = main.out 

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
%.o: %.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)

