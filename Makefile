CC := gcc
CC_FLAGS := -Wall -g

BIN := bin
SRC := src

INCLUDE := -I"include" -I"C:\Users\16479\dev\libraries\c\CSFML-2.5-windows-64-bit\include"

LIBRARIES := -L"C:\Users\16479\dev\libraries\c\CSFML-2.5-windows-64-bit\lib\gcc" -lcsfml-system -lcsfml-window -lcsfml-graphics
EXECUTABLE := main

all: $(BIN)/$(EXECUTABLE)

run: clean all 
	clear 
	@./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.c
	$(CC) $(CC_FLAGS) $(INCLUDE) $^ -o $@ $(LIBRARIES)

clean: 
	-rm $(BIN)/*



.PHONY: test