
//=============================================================================
// FILE NAME  : Chapte12/12_3_OOP_PROJECT/BankingCommonDec1.h
// DESCRIPTS  : study c++ programing
// PROGRAMMER : softColors
//-----------------------------------------------------------------------------
// REVIRION HISTORY
//   07/22/2021 : Create.
//=============================================================================
#ifndef __BANKINGCOMMONDEC1__H__
#define __BANKINGCOMMONDEC1__H__
using namespace std;

#define MAX_NAME_LEN 30
#define FAIL -1
#define TRUE 1
#define FALSE 0

enum{OPEN=1, DEPOSIT, WITHDRAW, INQUIRY, END};
enum{NOMAL_ACC=1, HIGH_CREDIT_ACC =2};
namespace CREDIT_TYPE{ enum{TYPE_A=7, TYPE_B =4, TYPE_C = 2}; }

#endif
