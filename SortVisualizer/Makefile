TARGET		= sort
CXX			= hgcc
CXXFLAGS	= -Wall -Iinclude
LDFLAGS		= -lc++

SRC =	main.cpp \
		src/Box.cpp \
		src/Layer.cpp \
		src/random.cpp \
		src/Shape.cpp \
		src/sorter.cpp \
		src/visualizer.cpp \
		src/Window.cpp

OBJ = 	$(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

bubble: $(TARGET)
	./$(TARGET) 0

quick: $(TARGET)
	./$(TARGET) 1

choice: $(TARGET)
	./$(TARGET) 2

insertion: $(TARGET)
	./$(TARGET) 3

heap: $(TARGET)
	./$(TARGET) 4
	
starin: $(TARGET)
	./$(TARGET) 5

abe: $(TARGET)
	./$(TARGET) 6

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
