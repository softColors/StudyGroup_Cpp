#==============================================================================
#  FILE NAME  : Chapter1/01-4/Makefile
#  DESCRIPTS  : study c++ programing
#  PROGRAMMER : softColors
# -----------------------------------------------------------------------------
#  REVIRION HISTORY
#  06/26/2021 : Create.
#==============================================================================

CC=g++
DIR := $(PWD)
CFLAGS=-g -Wall

OBJS=main.o sub.o 
TARGET=app.exe

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)


main.o: header.h main.cpp
sub.o: header.h sub.cpp

# main.o: foo.h bar.h main.c
# foo.o: foo.h foo.c
# bar.o: bar.h bar.c

# clean:
# 	remove-item *.o
# 	remove-item $(TARGET)

# clean:
# 	rm -f *.o
# 	rm -f $(TARGET)