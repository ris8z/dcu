#Giuseppe Esposito;    
#22702205;
    
IDIR=include
BDIR=build

CC=gcc
CFLAGS=-I$(IDIR)

_OBJ = command.o internal_command.o main.o utility.o
OBJ = $(patsubst %,$(BDIR)/%,$(_OBJ))

_DEPS = command.h internal_command.h utility.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

$(BDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

myshell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clear

clear:
	rm -f $(OBJ) myshell

