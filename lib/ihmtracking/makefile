#
# CIHMTracking library makefile
# gregory.medwed@heig-vd.ch
# Dec 2013

#Shared library
PROJECT= libihmtracking.so

#MISBlob
COBJS = misblob.o
COBJS += misblob_add.o
COBJS += misblob_debug.o
COBJS += misblob_draw.o
COBJS += misblob_get.o
COBJS += misblob_update.o

#IHMTracking
COBJS += ihmtracking.o
COBJS += ihmtracking_compute.o
COBJS += ihmtracking_check.o
COBJS += ihmtracking_debug.o
COBJS += ihmtracking_get.o


INCDIR = -I ../../include/

# Debug
CFLAGS = -g -Wall
# Release
#CFLAGS  = -O2 -Wall


all: $(PROJECT)

.cpp.o:
	g++ -fPIC -c $(CFLAGS) $(INCDIR) $<

$(PROJECT): $(COBJS)
	cp misblob.h ../../include/
	cp ihmtracking.h ../../include/
	g++ -shared $(COBJS) $(INCDIR) -o $(PROJECT)
	cp $(PROJECT) ../../lib64/
	doxygen Doxyfile

clean:
	rm -f *.o *.tag $(PROJECT)
	rm -f ../../include/misblob.h
	rm -f ../../include/ihmtracking.h
	rm -f ../../lib64/$(PROJECT)
	rm -R -f ../../doc/lib/ihmtracking/*


