#
# CIHMCurve library makefile
# gregory.medwed@heig-vd.ch
# Dec 2013

#Shared library
PROJECT= libihmcurve.so

COBJS = ihmcurve.o
COBJS += ihmcurve_get.o
COBJS += ihmcurve_debug.o
#COBJS += ihmrecord_....o


INCDIR = -I ../../include/

# Debug
CFLAGS = -g -Wall
# Release
#CFLAGS  = -O2 -Wall


all: $(PROJECT)

.cpp.o:
	g++ -fPIC -c $(CFLAGS) $(INCDIR) $<

$(PROJECT): $(COBJS)
	cp ihmcurve.h ../../include/
	g++ -shared $(COBJS) $(INCDIR) -o $(PROJECT)
	cp $(PROJECT) ../../lib64/
	doxygen Doxyfile

clean:
	rm -f *.o *.tag $(PROJECT)
	rm -f ../../include/$(PROJECT)
	rm -f ../../lib64/$(PROJECT)
	rm -R -f ../../doc/lib/ihmcurve/*


