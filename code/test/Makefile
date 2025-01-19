CXX = g++
CXXFLAGS = -std=c++17 -Wall
#changez les includes selon votre machine
#mac
INCLUDES = -I/opt/homebrew/opt/sfml@2/include -I../Figure -I../Spirographe -I../Affichage
LDFLAGS = -L/opt/homebrew/opt/sfml@2/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
#linux
#INCLUDES = -I/usr/include -I./Figure -I./Spirographe
#LDFLAGS = -L/usr/lib
#pour windows: 
#changer path/to/sfml par le chemin d'installation de sfml sur ton ordinateur
#INCLUDES = -IC:/path/to/sfml/include -I./Figure -I./Spirographe
#LDFLAGS = -LC:/path/to/sfml/lib
#LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TEST_SOURCES = test_unitaire.cpp ../Spirographe/Spirographe.cc ../Figure/Cercle.cc ../Figure/Ellipse.cc ../Figure/Polyedre.cc ../Figure/Ellipse_virtuelle.cc ../Affichage/Screen.cc ../Affichage/Page.cc ../Affichage/Bouton.cc 
TEST_TARGET = test_unitaire

$(TEST_TARGET): $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET) $(LIBS)

clean:
	rm -f $(TEST_TARGET)