CC = clang

OBJ := ../../build

LIBS   := gtk+-3.0
CFLAGS := $(shell pkg-config --cflags $(LIBS))

GRESOURCE := ui.gresource.xml

all: resources compile

compile: resources
	$(CC) -c resources.c -o $(OBJ)/resources.o $(CFLAGS)

resources:
	glib-compile-resources --target=resources.h --generate-header $(GRESOURCE)
	glib-compile-resources --target=resources.c --generate-source $(GRESOURCE)

.PHONY: all compile resources