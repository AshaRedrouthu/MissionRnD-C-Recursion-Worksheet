/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int *spiral_recursion(int row, int column, int k, int l, int **input_array, int *output, int index)
{
	int i;
	if (k < row && l < column){
		for (i = l; i < column; ++i)
			output[index++] = input_array[k][i];
		k++;

		for (i = k; i < row; ++i)
			output[index++] = input_array[i][column - 1];
		column--;

		if (k < row)
		{
			for (i = column - 1; i >= l; --i)
				output[index++] = input_array[row - 1][i];
			row--;
		}
		if (l < column)
		{
			for (i = row - 1; i >= k; --i)
				output[index++] = input_array[i][l];
			l++;
		}
		spiral_recursion(row, column, k, l, input_array, output, index);

	}
	else
		return output;
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int *output;
	output = (int *)malloc(sizeof(int) * rows * columns);
	output = spiral_recursion(rows, columns, 0, 0, input_array, output, 0);
	return output;
}
