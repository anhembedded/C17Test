
#include "220805.h"
#include <search.h>

stk_T oddStack;
stk_T evenStack;
/**
 * @brief   Copy của Chi Chi. Combining 2 array into a single array.
 * @param  {uint16_t []} inputArr1 :
 * @param  {int} n                 : number of elements inputArr1
 * @param  {uint16_t []} inputArr2 :
 * @param  {int} m                 : number of elements inputArr2
 * @param  {uint16_t []} arrResult :
 */
void array(const uint16_t inputArr1[], int n, const uint16_t inputArr2[], int m, uint16_t arrResult[])
{
    uint16_t p = n + m;
    for (int i = 0; i < p; i++)
    {
        if (i < n)
            arrResult[i] = inputArr1[i];
        else
            arrResult[i] = inputArr2[i - n];
    }
}
/**
 * @brief  Compares two numbers,
 * @param  {void*} num1 :
 * @param  {void*} num2 :
 * @note    This function aims to the qSort API's function.
 * @return {int}        :
 */
static int fnCompare(const void *num1, const void *num2)
{
    return ((*(uint16_t *)num1) - (*(uint16_t *)num2));
}
/**
 * @brief   Increasing sort elements of a array
 * @param  {uint16_t*} inputArray      :
 * @param  {uint16_t} numberOfElements :
 */
void u_sortIncreasing(uint16_t *inputArray, uint16_t numberOfElements)
{
    qsort(inputArray, numberOfElements, sizeof(uint16_t), fnCompare);
}
/**
 * @brief   checking if the number is Odd
 * @param  {uint16_t} number :
 * @return {pd_BOOL_T}       :
 */
pd_BOOL_T isOdd(uint16_t number)
{
    pd_BOOL_T res;
    if (number % 2)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }
    return res;
}
/**
 * @brief   checking if the both are the same
 * @param  {uint16_t} first  :
 * @param  {uint16_t} second :
 * @note    This function for the sake of readability
 * @return {pd_BOOL_T}       :
 */
pd_BOOL_T isTheSame(uint16_t first, uint16_t second)
{
    if (first == second)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/**
 * @brief   Distributing elements of array into stack
 * @param  {uint16_t*} inputArray      :
 * @param  {uint16_t} numberOfElements :
 * @param  {stk_T*} oddStack_ptr       :
 * @param  {stk_T*} evenStack_ptr      :
 * @note    Distributing elements of array into 2 stack, depending on the elements is odd or even
 */
void oddEvenDistributeIntoStack(uint16_t *inputArray, uint16_t numberOfElements, stk_T *oddStack_ptr, stk_T *evenStack_ptr)
{
    for (uint16_t i = 0; i < numberOfElements; i++)
    {
        if (isOdd(inputArray[i]))
        {
            stk_push(oddStack_ptr, inputArray[i]);
        }
        else
        {
            stk_push(evenStack_ptr, inputArray[i]);
        }
    }
}
/**
 * @brief  Combine those elements of 2 stacks into an array
 * @param  {uint16_t*} storeArray      :
 * @param  {uint16_t} numberOfElements :
 * @param  {stk_T*} oddStack_ptr       :
 * @param  {stk_T*} evenStack_ptr      :
 * @note    Combine those elements of 2 stacks into an array
 * such that odd numbers and even numbers interleaving, and decreasing order
 */
void final(uint16_t *storeArray, uint16_t numberOfElements, stk_T *oddStack_ptr, stk_T *evenStack_ptr)
{
    uint16_t oddEven = 0;
    for (uint16_t i = 0; i < numberOfElements; i++)
    {
        if (oddEven % 2)
        {
            storeArray[i] = stk_pop(oddStack_ptr);
            if ((!isTheSame(storeArray[i], stk_peek(oddStack_ptr))) && (evenStack_ptr->top != -1))
            {
                oddEven++;
            }
        }
        else
        {
            storeArray[i] = stk_pop(evenStack_ptr);
            if ((!isTheSame(storeArray[i], stk_peek(evenStack_ptr))) && (oddStack_ptr->top != -1))
            {
                oddEven++;
            }
        }
    }
}
