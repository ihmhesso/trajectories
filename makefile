#
# Trajectoires global makefile including libs, tests, tools and applications
# Gregory.medwed@heig-vd.ch
# Dec 2013
#

all:

	# Libs:
	$(MAKE) -C lib -f makefile all
	# Tests:
	$(MAKE) -C test -f makefile all
	# Tools:
	$(MAKE) -C tool -f makefile all
	# Application:
	$(MAKE) -C application -f makefile all

clean:
	# Libs:
	$(MAKE) -C lib -f makefile clean
	# Tests:
	$(MAKE) -C test -f makefile clean
	# Tools:
	$(MAKE) -C tool -f makefile clean
	# Applications:
	$(MAKE) -C application -f makefile clean
