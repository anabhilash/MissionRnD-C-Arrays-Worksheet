/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
void swap(int *, int, int);
void * sortedArrayPositionsChange(int *a, int size)
{
	int i, first = -1, second = -1, same1 = -1, same2 = -1;
	for (i = 0; i<size; i++)
	{
		if (first == -1)
		{
			if (i == size - 1)
				break;
			if (!(a[i]<a[i + 1]))
			{
				if (a[i] == a[i + 1])
				{
					if (same1 == -1)
					{
						same1 = i;
					}
					else
					{
						if (a[same1] != a[i])
						{
							same1 = i;
						}
					}
				}
				else
				{
					if (same1 != -1)
					{
						if (a[i] == a[same1])
						{
							first = same1;
							second = i + 1;
							break;
						}
					}
					else
					{
						first = i;
					}
				}
			}
		}
		else
		{
			if (same2 == -1)
			{
				if (!(a[first]>a[i]))
				{
					if (a[first] == a[i])
					{
						same2 = i;
					}
					else
					{
						second = i - 1;
						break;
					}
				}
			}
			else
			{
				if (!(a[first]<a[i]))
				{
					if (a[i] != a[same2])
					{
						second = i;
						break;
					}
				}
			}
		}
	}
	if ((first != -1))
	{
		if (second == -1)
		{
			if (same2 != -1)
			{
				second = same2 - 1;
			}
			else
			{
				second = size - 1;
			}
		}
		swap(a, first, second);
	}
	else
		return NULL;


}
void swap(int *a, int first, int second)
{
	int temp;
	temp = a[first];
	a[first] = a[second];
	a[second] = temp;

}