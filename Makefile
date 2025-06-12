CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDES = -Iinclude
SOURCES = $(wildcard src/*.cpp) main.cpp
TARGET = ors

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
