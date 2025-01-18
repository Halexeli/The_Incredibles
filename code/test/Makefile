CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDES = -I/opt/homebrew/opt/sfml@2/include -I../Figure -I../Spirographe -I../Affichage
LDFLAGS = -L/opt/homebrew/opt/sfml@2/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files for tests
TEST_SOURCES = test_unitaire.cpp
TEST_TARGET = test_unitaire

# Build test target
$(TEST_TARGET): $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET) $(LIBS)
# Clean up build files
clean:
	rm -f $(TEST_TARGET)