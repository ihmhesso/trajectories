#
# CIHMCurve library test makefile
# gregory.medwed@heig-vd.ch
# May 2015

#Shared library
PROJECT= ihmcurve_test

COBJS = bezier_test.o
COBJS += plot.o
COBJS += mouse_callback.o
COBJS += ihmcurve_test_main.o


# Debug
CFLAGS = -g -Wall
# Release
#CFLAGS  = -O2 -Wall


INCDIR = -I ../../include/

LIBDIRS= -L ../../lib64/

# OpenCV
LIBS = -lopencv_core
LIBS += -lopencv_highgui
LIBS += -lopencv_imgproc
# IHM
LIBS += -lihmcurve


LDFLAGS= $(LIBDIRS) $(LIBS)

all: $(PROJECT)

.cpp.o:
	g++ -c $(CFLAGS) $(INCDIR) $<

$(PROJECT): $(COBJS) 
	g++ $(COBJS) -o $(PROJECT) $(INCDIR) $(LDFLAGS)
	doxygen Doxyfile
# For shared library
	@echo " *** Don't forget to add the following line in .bashrc file."
	@echo " *** export LD_LIBRARY_PATH=/home/ihm/trajectories/lib64/"	

clean:
	rm -f *.o $(PROJECT)
	rm -R -f ../../doc/test/ihmcurve/*



