IDIR=include
BDIR=build

CC=gcc
CFLAGS=-I$(IDIR)

_OBJ = main.o hellofunc.o
OBJ = $(patsubst %,$(BDIR)/%,$(_OBJ))

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

$(BDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) hellomake
