###############################################################################
#
#	Makefile for the ihmcurve test application.
#	--
#	Version	: 1.0
#	Date	: 27 December 2013
#	Authors	: Rodolfo Horta (rodolfo.horta@master.hes-so.ch)
#			  Christopher Métrailler (christopher.metrailler@master.hes-so.ch)
#
###############################################################################

# Binary name
TARGET     = ihmcurve_test

# List of *.c files sources to compile
CSRCS      = # Not used...

# List of *.cpp files sources to compile
CXXSRCS    = BezierTest.cpp \
			 Plot.cpp \
			 MouseCallback.cpp \
			 ihmcurve_test_main.cpp

# Path to all include directories
INCS       = ../../include

# Path to all custom libraries
LIBDIRS    = ../../lib64

# Add some librairies
LIBS       = -lopencv_core \
             -lopencv_highgui \
             -lihmcurve

# The following are variable that hold binaries and settings
LD         = g++ 
CC         = gcc
CPPC       = g++
CFLAGS     = -g -Wall
LDFLAGS    = $(LIBDIRS:%=-L%) $(LIBS)
CPPFLAGS   = -g -Wall

###############################################################################
# Don't change anything below this line
###############################################################################

# generate the object names
OBJS       = $(CXXSRCS:%.cpp=%.o)

# automate the inclusion paths
CFLAGS    += $(INCS:%=-I%)
CPPFLAGS  += $(INCS:%=-I%) 

# this is the default if the user does just call 'make'
all: $(TARGET)

# link everything together
$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET) $(OBJS)

# compile c files
%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $^

# compile cpp files
%.o: %.cpp
	$(CPPC) $(CPPFLAGS) -c -o $@ $^

# remove the binrary, all object files and html doc
clean:
	rm -f *.o $(TARGET)
	rm -R -f ../../doc/test/ihmcurve/*

# doxygen doc generation
doc:
	doxygen Doxyfile

# clean must be a phony target so make knows this never exists as a file
.PHONY: clean
.PHONY: doc

