#include "main.h"

#define MAX_SIZE_ARR_INPUT 2020
#define ARRAY_1_SIZE 14u
#define ARRAY_2_SIZE 12u
#define TOTAL_ARRAY_SIZE (ARRAY_1_SIZE + ARRAY_2_SIZE)

uint16_t input_array1[] = {2, 4, 6, 7, 9, 13, 45, 12, 66, 77, 88, 13, 44, 556};
uint16_t input_array2[] = {1, 3, 9, 13, 11, 211, 32, 45, 77, 4, 8, 9};
uint16_t arrResult[MAX_SIZE_ARR_INPUT * 2];
uint16_t arrayFinalResult[MAX_SIZE_ARR_INPUT * 2];

stk_T stack_reverseArray;

static inline void init()
{
    stack_reverseArray.stackEmptyCallbackHandler = stackEmptyHandler;
    stack_reverseArray.stackEmptyCallbackHandler = stackFullHandler;

    oddStack.stackEmptyCallbackHandler = stackEmptyHandler;
    oddStack.stackFullCallbackHandler = stackFullHandler;

    evenStack.stackEmptyCallbackHandler = stackEmptyHandler;
    evenStack.stackFullCallbackHandler = stackFullHandler;
}

int main()
{

    init();

    array(input_array1, ARRAY_1_SIZE, input_array2, ARRAY_2_SIZE, arrResult);
    u_sortIncreasing(arrResult, TOTAL_ARRAY_SIZE);
    oddEvenDistributeIntoStack(arrResult, TOTAL_ARRAY_SIZE, &oddStack, &evenStack);
    final(arrayFinalResult, TOTAL_ARRAY_SIZE, &oddStack, &evenStack);

    reverseArray(arrayFinalResult, TOTAL_ARRAY_SIZE, &stack_reverseArray);

    return 0;
}

void stackEmptyHandler()
{
    printf("stackEmptyHandler");
}
void stackFullHandler()
{
    printf("stackFullHandler");
}
/**
 * @brief  reversing the Array, Examples: {1,2,3,4,5,6,7} -> {7,6,5,4,3,2,1}
 * @param  {uint16_t*} inputArray      :
 * @param  {uint16_t} numberOfElements :
 * @param  {stk_T*} stackStorage       :
 * @note    Pushing array elements into the stack, and then popping those elements back from the stack
 *
 */
void reverseArray(uint16_t *inputArray, uint16_t numberOfElements, stk_T *stackStorage)
{
    for (uint16_t i = 0; i < numberOfElements; i++)
    {
        stk_push(stackStorage, inputArray[i]);
    }
    for (uint16_t i = 0; i < numberOfElements; i++)
    {
        inputArray[i] = stk_pop(stackStorage);
    }
}