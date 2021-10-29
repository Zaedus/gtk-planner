CC = clang

MAKEFLAGS := --jobs=$(shell nproc)

SRC := src
OBJ := build
UI  := resources/ui
BIN := gtk-planner

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES)) $(OBJ)/resources.o
HEADERS := $(wildcard $(SRC)/*.hpp) $(UI)/resources.h

LIBS 	 := gtkmm-3.0 libhandy-1 gtk+-3.0
CFLAGS   := $(shell pkg-config --cflags $(LIBS)) -std=c++17
LDFLAGS  := $(shell pkg-config --libs $(LIBS)) -lstdc++

debug: CFLAGS += -O0
debug: $(BIN)

release: CFLAGS += -O2
release: $(BIN)

$(BIN): $(OBJECTS) $(HEADERS)
	$(CC) -o $(BIN) $(OBJECTS) $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CC) -c $< -o $@ $(CFLAGS) $(INCFLAGS)

$(OBJ)/resources.o: 
	$(MAKE) -C $(UI)

$(OBJ):
	mkdir -p $@

clean_debug: clean
	+@$(MAKE) --no-print-directory debug

clean_release: clean
	+@$(MAKE) --no-print-directory release

clean:
	-rm -rf $(OBJ)

.PHONY: resources clean debug release