/*cal_sum() 는 배열 요소들의 합을 계산하는 함수이다.

cal_sum() 함수는 수정하지 않고 그대로 두고, 오직 함수 호출 부분만 수정하여
num[i] ~ num[i+(k-1)] 까지 k개 요소의 합을 계산하여 출력한다.
i와 k 값은 각각 사용자로부터 입력받는다.

<입출력 예1>

2  3      #사용자 입력
21        # 출력; num[2] + num[3] + num[4]

<입출력 예2>

3  2      #사용자 입력
16        # 출력; num[3] + num[4]
*/

#include <stdio.h>
#define SIZE 7

// 배열 list에서 n개 요소의 합을 구함
int cal_sum(int  list[ ], int  n)
{
	int  sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += list[i];
	}
	return sum;
}
int main(void)
{
	int  num[ ] = { 2, 3, 5, 7, 9, 11, 13 };
	int  sum, i, k;
	
	scanf("%d %d", &i, &k);
	sum = cal_sum(num+i, k);   // 이부분 수정
	printf("%d\n", sum);
	return 0;
}