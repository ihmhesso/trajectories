#
# CIHMPerspective library makefile
# gregory.medwed@heig-vd.ch
# Dec 2013
#

#Shared library
PROJECT= libihmperspective.so

COBJS = ihmperspective.o
COBJS += ihmperspective_get.o
COBJS += ihmperspective_debug.o
COBJS += ihmperspective_draw.o
COBJS += ihmperspective_warp.o


INCDIR = -I ../../include/

# Debug
CFLAGS = -g -Wall
# Release
#CFLAGS  = -O2 -Wall


all: $(PROJECT)

.cpp.o:
	g++ -fPIC -c $(CFLAGS) $(INCDIR) $<

$(PROJECT): $(COBJS)
	cp ihmperspective.h ../../include/
	g++ -shared $(COBJS) $(INCDIR) -o $(PROJECT)
	cp $(PROJECT) ../../lib64/
	doxygen Doxyfile

clean:
	rm -f *.o *.tag $(PROJECT)
	rm -f ../../include/$(PROJECT)
	rm -f ../../lib64/$(PROJECT)
	rm -R -f ../../doc/lib/ihmperspective/*


