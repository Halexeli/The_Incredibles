CXX = g++
CXXFLAGS = -std=c++17 -stdlib=libc++
INCLUDES = -I/opt/homebrew/opt/sfml@2/include -I./Figure -I./Spirographe
LDFLAGS = -L/opt/homebrew/opt/sfml@2/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
SOURCES = main.cpp ./Figure/*.cc ./Spirographe/*.cc
TARGET = spirograph

#source files
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(SOURCES) -o $(TARGET) $(LIBS)
clean:
	rm -f $(TARGET)