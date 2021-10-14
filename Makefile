CC = clang

MAKEFLAGS := --jobs=$(shell nproc)

SRC := src
OBJ := build
BIN := gtk-planner

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))
HEADERS := $(wildcard $(SRC)/*.hpp)

LIBS 	 := gtkmm-4.0
CFLAGS   := $(shell pkg-config --cflags $(LIBS)) -std=c++17
LDFLAGS  := $(shell pkg-config --libs $(LIBS)) -lstdc++

debug: CFLAGS += -O0
debug: $(BIN)

release: CFLAGS += -O2
release: $(BIN)

$(BIN): $(OBJECTS) $(HEADERS)
	$(CC) -o $(BIN) $(OBJECTS) $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CC) -c $< -o $@ -D VERSION=\"$(VERSION)\" $(CFLAGS) $(INCFLAGS)

$(OBJ):
	mkdir -p $@

clean:
	-rm -rf $(OBJ)