#
# Trajectories application makefile
# gregory.medwed@heig-vd.ch
# Dec 2013

#Shared library
PROJECT= trajectories

COBJS = trajectories_main.o
COBJS += trajectories_init.o
#COBJS += trajectories_args.o
#COBJS += trajectories_keyboard.o
#COBJS += trajectories_mouse.o


# Debug
CFLAGS = -g -Wall
# Release
#CFLAGS  = -O2 -Wall


INCDIR = -I ../../include/

LIBDIRS= -L ../../lib64/

# OpenCV
LIBS = -lopencv_core
LIBS += -lopencv_highgui
LIBS += -lopencv_video
# IHM
LIBS += -lihmbackground
LIBS += -lihmcapture
LIBS += -lihmcurve
LIBS += -lihmperspective
LIBS += -lihmrecord
LIBS += -lihmtracking
LIBS += -lmispath
LIBS += -lihmfootprint


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
	rm -R -f ../../doc/application/trajectories/*



