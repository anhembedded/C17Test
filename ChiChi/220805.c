#include"220805.h"

#include <search.h>

stk_T oddStack;
stk_T evenStack;

void array (const uint16_t inputArr1[], int n, const uint16_t inputArr2[], int m, uint16_t arrResult[])
{
	uint16_t  p = n + m;
	for (int i = 0; i < p; i++)
	{
		if (i < n)
			arrResult[i] = inputArr1[i];
		else arrResult[i] = inputArr2[i - n];
	}
}

static int fnCompare(const void *num1, const void *num2)
{
    return ( (*(uint16_t*)num1) - (*(uint16_t*)num2));
}

 void u_sortIncreasing(uint16_t *inputArray, uint16_t numberOfElements)
{
    qsort(inputArray,numberOfElements,sizeof (uint16_t), fnCompare);
}

pd_BOOL_T isOdd(uint16_t number) {
    pd_BOOL_T res = 0;
    if(number %2)
    {
        res =1;
    } else
    {
        res = 0;
    }
   return res;
}
pd_BOOL_T isTheSame (uint16_t first, uint16_t second)
{
    if(first == second)
    {
        return 1;
    } else{
        return  0;
    }
}

void oddEvenAttributeIntoStack(uint16_t *inputArray,uint16_t numberOfElements, stk_T *oddStack_ptr, stk_T *evenStack_ptr)
{
    for(uint16_t i = 0; i < numberOfElements; i++ )
    {
        if(isOdd(inputArray[i]))
        {
            stk_push(oddStack_ptr,inputArray[i]);
        } else
        {
            stk_push(evenStack_ptr, inputArray[i]);
        }
    }
}

void final(uint16_t *storeArray, uint16_t numberOfElements, stk_T *oddStack_ptr, stk_T *evenStack_ptr)
{
    uint16_t oddEven = 0;
   for(uint16_t i = 0; i < numberOfElements; i++)
   {
     if(oddEven%2)
     {
         storeArray[i] = stk_pop(oddStack_ptr);
         if( (!isTheSame(storeArray[i],stk_peek(oddStack_ptr))) &&  (evenStack_ptr->top != -1))
         {
             oddEven++;
         }
     } else
     {
         storeArray[i] = stk_pop(evenStack_ptr);
         if((!isTheSame(storeArray[i],stk_peek(evenStack_ptr))) &&  (oddStack_ptr->top != -1))
         {
             oddEven++;
         }
     }
   }

}






