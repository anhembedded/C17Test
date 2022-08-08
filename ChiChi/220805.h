#ifndef ARR_H
#define ARR_H
#include <stdint.h>
#include "u_stdint.h"
#include "u_stack/u_stack.h"

extern stk_T oddStack;
extern stk_T evenStack;

static pd_BOOL_T isOdd(uint16_t number);
void array(const uint16_t inputArr1[], int n, const uint16_t inputArr2[], int m, uint16_t arrResult[]);
static int fnCompare(const void *num1, const void *num2);
void u_sortIncreasing(uint16_t *inputArray, uint16_t numberOfElements);
pd_BOOL_T isTheSame(uint16_t first, uint16_t second);
void oddEvenDistributeIntoStack(uint16_t *inputArray, uint16_t numberOfElements, stk_T *oddStack_ptr, stk_T *evenStack_ptr);
void final(uint16_t *storeArray, uint16_t numberOfElements, stk_T *oddStack_ptr, stk_T *evenStack_ptr);

#endif
