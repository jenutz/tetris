CXX = g++
CXXFLAGS = -lncurses #-Wall

# Directories
SRCDIR = src
BUILDDIR = build
TARGET = tetris

# Source files
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRC))

# Default target
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Create the build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Clean up the build files
clean:
	rm -rf $(BUILDDIR) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# List of files that should be cleaned up
clean-all: clean
	rm -f log.txt buglist.txt

# Phony targets
.PHONY: all clean run clean-all

