#Makefile

#Erick de Oliveira Silva

#Compiler
CXX = g++

#Flags
COMPILE_FLAG = -std=c++11

#Path
SRC_PATH = ./src/driver.cpp
INCLUDE_PATH = ./include/

#Executable
BIN_NAME = ./build/dict

dictionary: $(SRC_PATH) $(INCLUDE_PATH)
	$(CXX) -Wall $(COMPILE_FLAG) $(SRC_PATH) -I $(INCLUDE_PATH) -o $(BIN_NAME)