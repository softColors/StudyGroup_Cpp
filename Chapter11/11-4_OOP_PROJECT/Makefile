#==============================================================================
# FILE NAME  : Chapte11/11_4_OOP_PROJECT/Makefile
#  DESCRIPTS  : study c++ programing
#  PROGRAMMER : softColors
# -----------------------------------------------------------------------------
#  REVIRION HISTORY
#   07/18/2021 : Create.
#==============================================================================

CC=g++
DIR := $(PWD)
CFLAGS=-g -Wall

OBJS=BankingSystemMain.o Account.o AccountArray.o AccountHandler.o
TARGET=app.exe

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)


BankingSystemMain.o: Account.h NomalAccount.h HighCreditAccount.h BankingCommonDec1.h AccountHandler.h BankingSystemMain.cpp
Account.o: Account.h Account.cpp
AccountHandler.o: AccountArray.h Account.h NomalAccount.h HighCreditAccount.h BankingCommonDec1.h AccountHandler.h AccountHandler.cpp
AccountArray.o: Account.h AccountArray.h AccountArray.cpp


# main.o: foo.h bar.h main.c
# foo.o: foo.h foo.c
# bar.o: bar.h bar.c

# clean:
# 	remove-item *.o
# 	remove-item $(TARGET)

# clean:
# 	rm -f *.o
# 	rm -f $(TARGET)