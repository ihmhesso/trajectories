#
# CIHMRecord library makefile
# gregory.medwed@heig-vd.ch
# Dec 2013

#Shared library
PROJECT= libihmrecord.so

COBJS = ihmrecord.o
COBJS += ihmrecord_get.o
COBJS += ihmrecord_debug.o
COBJS += ihmrecord_write.o


INCDIR = -I ../../include/

# Debug
CFLAGS = -g -Wall
# Release
#CFLAGS  = -O2 -Wall


all: $(PROJECT)

.cpp.o:
	g++ -fPIC -c $(CFLAGS) $(INCDIR) $<

$(PROJECT): $(COBJS)
	cp ihmrecord.h ../../include/
	g++ -shared $(COBJS) $(INCDIR) -o $(PROJECT)
	cp $(PROJECT) ../../lib64/
	doxygen Doxyfile

clean:
	rm -f *.o *.tag $(PROJECT)
	rm -f ../../include/$(PROJECT)
	rm -f ../../lib64/$(PROJECT)
	rm -R -f ../../doc/lib/ihmrecord/*


