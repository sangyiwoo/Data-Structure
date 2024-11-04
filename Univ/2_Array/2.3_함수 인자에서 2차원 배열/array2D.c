#include <stdio.h>
#define ROWS  2
#define COLS   3

// calc_sum 함수의 프로토타입 선언
int calc_sum(int n[], int rows, int cols);

int main(void)
{
	int  num[ROWS][COLS] = { { 2, 3, 5} , {7, 9, 11}  };
	int  sum = calc_sum((int *) num, ROWS, COLS);
	printf("합 = %d \n", sum);
	return 0;
}
