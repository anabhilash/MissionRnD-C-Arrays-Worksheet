
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

int binary(int *a, int length, int score);

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount)
{
	int binary(int *, int, int);
	if (Arr == NULL || len <= 0 || score <= 0)
	{
		return NULL;
	}
	int k = binary(Arr, len, score);
	int count = 0, temp, lowcount = 0, upcount = 0;
	temp = k - 1;
	while (Arr[temp] == score&&temp >= 0)
	{
		lowcount++;
		temp--;
	}
	temp = k + 1;
	while (Arr[temp] == score&&temp < len)
	{
		upcount++;
		temp++;
	}
	if (k < 0)
	{
		*lessCount = 0;
		*moreCount = len;
	}
	else if (k >= len)
	{
		*lessCount = len;
		*moreCount = 0;
	}
	else{
		if (Arr[k] == score)
		{
			*lessCount = k - lowcount;
			*moreCount = len - k - upcount - 1;
		}
		else{
			*lessCount = k - lowcount;
			*moreCount = len - k - upcount;
		}
	}
	return NULL;
}

int binary(int *a, int length, int score)
{
	int low, high, mid;
	low = 0;
	high = length - 1;
	while (low != high)
	{
		mid = (low + high) / 2;
		if (a[mid] == score)
			return mid;
		else if (mid > 0 && mid < length&&a[mid - 1]<score&&a[mid + 1]>score)
		{
			return mid;
		}
		else if (a[mid] < score)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (a[low] == score)
		return low;
	else if (a[low]>score)
		return low - 1;
	else{
		return low + 1;
	}
}





