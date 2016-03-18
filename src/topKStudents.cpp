/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
#include<stdio.h>
struct student
{
	char *name;
	int score;
};
void topK(struct student *, int, int, int, struct student **);
void swap(struct student *, int, int);
int add(struct student **, struct student *, int, int, int);
struct student *top[15];
struct student ** topKStudents(struct student *students, int len, int K)
{
	int i = 0;
	if (students != NULL && K>0)
	{
		if (K == len || K > len)
		{
			while (i<len)
			{
				top[i] = &students[i];
				i++;
			}
			return top;
		}
		topK(students, 0, len, K, top);
		return top;
	}
	else
		return NULL;
}
void topK(struct student *students3, int low, int high, int k, struct student **result)
{
	int error = 0, rightlen, pivot, i, j, l = 0;
	while (!error)
	{
		pivot = students3[(low + high) / 2].score;
		swap(students3, (low + high) / 2, high - 1);
		i = low;
		j = high - 2;
		while (i < j)
		{
			while ((students3[i].score)<pivot && i<(high - 1))
			{
				i++;
			}
			while ((students3[j].score) >= pivot && j>low)
			{
				j--;
			}
			if (i > j)
			{
				swap(students3, i, high - 1);
				rightlen = high - i;   //rightlen is length of the right partitioned array including pivot
				if (rightlen == k)    //right partitioned array including pivot is topk
				{
					l=add(result, students3, i, high, l); //l tracks the length of resulting array
					error = 1;         //error says k elements are done copying
				}
				else if (rightlen == k + 1) //right partion array without pivot
				{
					i++;
					l=add(result, students3, i, high, l);
					error = 1;
				}
				else if (rightlen < k)  //if right partition array is less than K then we should use left partiton
				{
					l=add(result, students3, i, high, l);
					high = j + 1;
					k = k - rightlen; //if rightlen is less than than after copying k will decreased 
				}
				else        //if right partition array length is greater than actual K than we should further partition the right array
				{
					low = i;
				}
			}
			else
			{
				swap(students3, i, j);
			}
		}
	}
}
void swap(struct student *students4, int i, int j)
{
	int tempi;
	tempi = students4[i].score;
	students4[i].score = students4[j].score;
	students4[j].score = tempi;
}
int add(struct student **result, struct student *students, int i, int high, int l)
{
	while (i < high)
	{
		result[l] = &students[i];
		l++;
		i++;
	}
	return l;
}