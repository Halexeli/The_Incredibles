CXX = g++
CXXFLAGS = -std=c++17 #-stdlib=libc++
#modifier ceci pour linux
#INCLUDES = -I/usr/include -I./Figure -I./Spirographe
#LDFLAGS = -L/usr/lib

#pour windows: 
#changer path/to/sfml par le chemin d'installation de sfml sur ton ordinateur
#INCLUDES = -IC:/path/to/sfml/include -I./Figure -I./Spirographe
#LDFLAGS = -LC:/path/to/sfml/lib
#LIBS = -lsfml-graphics -lsfml-window -lsfml-system

#INCLUDES = -I/opt/homebrew/opt/sfml@2/include -I./Figure -I./Spirographe -I./Affichage
#LDFLAGS = -L/opt/homebrew/opt/sfml@2/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
SOURCES = main.cpp Make_page.cc Inter_page.cc ./Figure/*.cc ./Spirographe/*.cc ./Affichage/*.cc
TARGET = spirograph

#source files
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(SOURCES) -o $(TARGET) $(LIBS)
clean:
	rm -f $(TARGET)