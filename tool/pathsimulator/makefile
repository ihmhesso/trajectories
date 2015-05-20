#
# Pathsimulator tool makefile
# gregory.medwed@heig-vd.ch
# Dec 2013


PROJECT= pathsimulator


COBJS = pathsimulator_args.o
COBJS += pathsimulator_init.o
COBJS += pathsimulator_keyboard.o
COBJS += pathsimulator_mouse.o
COBJS += pathsimulator_main.o
COBJS += pathsimulator_osd.o
COBJS += pathsimulator_trackbar.o
COBJS += pathsimulator_video.o


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
LIBS += -lopencv_videoio
LIBS += -lopencv_imgcodecs
# IHM
LIBS += -lmispath


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
	rm -R -f ../../doc/tool/pathsimulator/*



