UNAME := $(shell uname)
ifeq ($(UNAME),Linux)
	SHAREDLIB_EXT := so
	SHAREDLIB_FLAG := -shared
endif
ifeq ($(UNAME),Darwin)
	SHAREDLIB_EXT := dylib
	SHAREDLIB_FLAG := -dynamiclib
endif

CURDIR := $(shell pwd)
LIBPLFIT := $(CURDIR)/libplfit.$(SHAREDLIB_EXT)

CFLAGS:= -Wall -c -I../src
OBJS=*.o
all: plfit

.PHONY: all clean

plfit:
	gcc $(CFLAGS) `ls ../src/*.c | grep -F -v plgen.c`
	gcc $(SHAREDLIB_FLAG) -undefined suppress -flat_namespace *.o -o $(LIBPLFIT)

	
clean:
	$(RM) -rf $(OBJS) plfit
	$(RM) -rf $(LIBPLFIT) plfit