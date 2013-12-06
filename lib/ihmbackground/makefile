#
# CIHMBackground library makefile
# gregory.medwed@heig-vd.ch
# Dec 2013

#Shared library
PROJECT= libihmbackground.so

COBJS = ihmbackground.o
COBJS += ihmbackground_get.o
COBJS += ihmbackground_debug.o
COBJS += ihmbackground_sub.o


INCDIR = -I ../../include/

# Debug
CFLAGS = -g -Wall
# Release
#CFLAGS  = -O2 -Wall


all: $(PROJECT)

.cpp.o:
	g++ -fPIC -c $(CFLAGS) $(INCDIR) $<

$(PROJECT): $(COBJS)
	cp ihmbackground.h ../../include/
	g++ -shared $(COBJS) $(INCDIR) -o $(PROJECT)
	cp $(PROJECT) ../../lib64/
	doxygen Doxyfile

clean:
	rm -f *.o *.tag $(PROJECT)
	rm -f ../../include/$(PROJECT)
	rm -f ../../lib64/$(PROJECT)
	rm -R -f ../../doc/lib/ihmbackground/*


