CC=/usr/tce/packages/xl/xl-2019.08.20/bin/xlc
#CC=gcc
CFLAGS= #-qstrict #-std=c99
LDFLAGS=-lm

SOURCES := $(wildcard *.c)

O0EXES := $(SOURCES:.c=_O0)
O3EXES := $(SOURCES:.c=_O3)
EXECUTABLES := $(O0EXES) $(O3EXES)

all: $(SOURCES) $(EXECUTABLES) 
clean:
	rm -f $(EXECUTABLES) 

%_O0 : %.c
	$(CC) $(CFLAGS) -O0 -o $@ $< $(LDFLAGS)

%_O3 : %.c
	$(CC) $(CFLAGS) -O3 -o $@ $< $(LDFLAGS)
