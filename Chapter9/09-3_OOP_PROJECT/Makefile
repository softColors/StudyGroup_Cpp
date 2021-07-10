#==============================================================================
# FILE NAME  : Chapter9/09-3_OOP_PROJECT/Makefile
#  DESCRIPTS  : study c++ programing
#  PROGRAMMER : softColors
# -----------------------------------------------------------------------------
#  REVIRION HISTORY
#  07/10/2021 : Create.
#==============================================================================

CC=g++
DIR := $(PWD)
CFLAGS=-g -Wall

OBJS=BankingSystemMain.o Account.o  AccountHandler.o
TARGET=app.exe

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)


BankingSystemMain.o: Account.h NomalAccount.h HighCreditAccount.h BankingCommonDec1.h AccountHandler.h BankingSystemMain.cpp
Account.o: Account.h Account.cpp
AccountHandler.o: Account.h NomalAccount.h HighCreditAccount.h BankingCommonDec1.h AccountHandler.h AccountHandler.cpp


# main.o: foo.h bar.h main.c
# foo.o: foo.h foo.c
# bar.o: bar.h bar.c

# clean:
# 	remove-item *.o
# 	remove-item $(TARGET)

# clean:
# 	rm -f *.o
# 	rm -f $(TARGET)