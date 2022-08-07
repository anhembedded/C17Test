#include"220805.h"


void array (uint16_t inputArr1[], int n, uint16_t inputArr2[], int m, uint16_t arrResult[], int p)
{
	p = n + m;
	for (int i = 0; i < p; i++)
	{
		if (i < n)
			arrResult[i] = inputArr1[i];
		else arrResult[i] = inputArr2[i - n];
	}
}
void  increase_t(uint16_t arrResult[], uint16_t p) {

	for (int i = 0; i < p - 1; i++) {
		for (int j = i + 1; j < p; j++) {
			if (arrResult[i] > arrResult[j]) {
				int temp = arrResult[i];
				arrResult[i] = arrResult[j];
				arrResult[j] = temp;
			}
		}
	}
}




