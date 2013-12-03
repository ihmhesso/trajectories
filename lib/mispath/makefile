#
# CMISPath library makefile
# gregory.medwed@heig-vd.ch
# Dec 2013

#Shared library
PROJECT= libmispath.so

COBJS = mispath.o
COBJS += mispath_compute.o
COBJS += mispath_csv.o
COBJS += mispath_debug.o
COBJS += mispath_draw.o
COBJS += mispath_get.o
COBJS += mispath_init.o
COBJS += mispath_path.o


INCDIR = -I ../../include/

# Debug
CFLAGS = -g -Wall
# Release
#CFLAGS  = -O2 -Wall


all: $(PROJECT)

.cpp.o:
	g++ -fPIC -c $(CFLAGS) $(INCDIR) $<

$(PROJECT): $(COBJS)
	cp mispath.h ../../include/
	g++ -shared $(COBJS) $(INCDIR) -o $(PROJECT)
	cp $(PROJECT) ../../lib64/
	doxygen Doxyfile

clean:
	rm -f *.o $(PROJECT)
	rm -f ../../include/$(PROJECT)
	rm -f ../../lib64/$(PROJECT)
	rm -R -f ../../doc/lib/mispath/*


