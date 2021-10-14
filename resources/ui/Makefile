
GRESOURCE = ui.gresource.xml

all: 
	glib-compile-resources --target=resources.h --generate-header $(GRESOURCE)
	glib-compile-resources --target=resources.c --generate-source $(GRESOURCE)