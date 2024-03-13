CC=gcc
CFLAGS=-I.
DEPS = hellomake.h add.h
OBJ = main.o hellofunc.o add.o



#This says that the .o file depends upon the .c version of the file and the .h files
#included in the DEPS macro.
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
#-c flag says to generate the object file,
#-o      sats that we want a name for our executable
#$@      it is the  name on the left side of the :
#$<      is the first item in the DEPS list


hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
#&^      it's the name of the right side of the :



.PHONY: clear

clear:
	rm *.o




#source: https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#IMPORTANT to add a tab in nano is: shift + alt + v than u enter a tab
