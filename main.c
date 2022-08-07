#include <stdint.h>
#include <search.h>
#include "u_stdint.h"
#include "u_stack/u_stack.h"
#include "ChiChi/220805.h"

stk_T myStack = stk_defaultConstructor;
pd_BOOL_T checkFlag = 99;


#define  MAX_SIZE_ARR_INPUT 2020
uint16_t array_1[5] = { 2,4,6,7,9 };
uint16_t array_2[6] = { 1,3,9,13,11,21 };
uint16_t arrResult[MAX_SIZE_ARR_INPUT * 2];


int main()
{
    array(array_1, 5 , array_2, 6, arrResult, MAX_SIZE_ARR_INPUT);
    increase_t(arrResult, 11); //Chổ này là 11 (số phần tử cần sắp xếp),

    return 0;
}
