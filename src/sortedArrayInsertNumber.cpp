/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
void insert(int *, int, int, int);
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i = 0, index = -1;
	if (Arr != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (Arr[i] > num)
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			index = len;
		}
		Arr = (int *)realloc(Arr, sizeof(int)*(len + 1));
		if (Arr != NULL)
		{
			insert(Arr, len, num, index);
			return Arr;
		}
		else
			return NULL;
	}
	else
		return NULL;
}
void insert(int *Arr, int len, int num, int index)
{
	int i;
	for (i = len - 1; i >= index; i--)
	{
		Arr[i + 1] = Arr[i];
	}
	Arr[i + 1] = num;
}