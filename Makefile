# CXX = g++
# CXX_FLAGS = -std=c++11 -Iinclude

# INCLUDE_DIR = include
# SRC_DIR = src
# OBJ_DIR = obj
# TARGET = turtix.out

# SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# all : $(OBJ_DIR) $(TARGET)

# $(TARGET) : $(OBJECTS)
# 	$(CXX) $(CXX_FLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# $(OBJ_DIR)/main.o : $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/Mission.hpp $(INCLUDE_DIR)/Map.hpp $(INCLUDE_DIR)/Turtle.hpp
# 	$(CXX) $(CXX_FLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

# $(OBJ_DIR)/Mission.o : $(INCLUDE_DIR)/Mission.hpp $(SRC_DIR)/Mission.cpp $(INCLUDE_DIR)/Map.hpp $(INCLUDE_DIR)/Turtle.hpp $(INCLUDE_DIR)/Turtle_baby.hpp
# 	$(CXX) $(CXX_FLAGS) -c $(SRC_DIR)/Mission.cpp -o $(OBJ_DIR)/Mission.o

# $(OBJ_DIR)/Map.o : $(INCLUDE_DIR)/Map.hpp $(SRC_DIR)/Map.cpp $(INCLUDE_DIR)/Turtle.hpp $(INCLUDE_DIR)/Turtle_baby.hpp
# 	$(CXX) $(CXX_FLAGS) -c $(SRC_DIR)/Map.cpp -o $(OBJ_DIR)/Map.o

# $(OBJ_DIR)/Turtle.o : $(INCLUDE_DIR)/Turtle.hpp $(SRC_DIR)/Turtle.cpp
# 	$(CXX) $(CXX_FLAGS) -c $(SRC_DIR)/Turtle.cpp -o $(OBJ_DIR)/Turtle.o	

# $(OBJ_DIR)/Turtle_baby.o : $(INCLUDE_DIR)/Turtle.hpp $(SRC_DIR)/Turtle_baby.cpp $(INCLUDE_DIR)/Turtle_baby.hpp
# 	$(CXX) $(CXX_FLAGS) -c $(SRC_DIR)/Turtle_baby.cpp -o $(OBJ_DIR)/Turtle_baby.o

# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)

# clean : 
# 	rm -rf $(OBJ_DIR) $(TARGET)



# Compiler and Flags
CXX = g++
CXX_FLAGS = -std=c++11 -Iinclude -MMD -MP

# Directories
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
TARGET = turtix.out

# File Management
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
DEPENDS = $(OBJECTS:.o=.d)

# Build Target
all: $(OBJ_DIR) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Generic Compilation Rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

# Ensure obj/ exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean Compiled Files
clean:
	rm -f $(OBJECTS) $(DEPENDS) $(TARGET)

# Auto-include Dependencies
-include $(DEPENDS)
