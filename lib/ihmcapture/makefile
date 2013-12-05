#
# CIHMCapture library makefile
# gregory.medwed@heig-vd.ch
# Dec 2013

#Shared library
PROJECT= libihmcapture.so

COBJS = ihmcapture.o
COBJS += ihmcapture_init.o
COBJS += ihmcapture_get.o
COBJS += ihmcapture_debug.o
COBJS += ihmcapture_open.o
COBJS += ihmcapture_thread.o


INCDIR = -I ../../include/

# Debug
CFLAGS = -g -Wall
# Release
#CFLAGS  = -O2 -Wall


all: $(PROJECT)

.cpp.o:
	g++ -fPIC -c $(CFLAGS) $(INCDIR) $<

$(PROJECT): $(COBJS)
	cp ihmcapture.h ../../include/
	g++ -shared $(COBJS) $(INCDIR) -o $(PROJECT)
	cp $(PROJECT) ../../lib64/
	doxygen Doxyfile

clean:
	rm -f *.o *.tag $(PROJECT)
	rm -f ../../include/$(PROJECT)
	rm -f ../../lib64/$(PROJECT)
	rm -R -f ../../doc/lib/ihmcapture/*


