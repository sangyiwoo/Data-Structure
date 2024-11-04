/*배열 공간을 동적 메모리로 할당하고, primes.txt 파일에 들어 있는 값을 이 배열로 읽어들인다.

배열 요소의 총 합을 구한 후 출력한다.



<입출력 예>

 

496165411
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE (10000)

// 배열 list에서 n개의 요소 합을 구함
int cal_sum(int  list[ ], int  n)
{
	int  sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += list[i];
	}
	return sum;
}

// 파일 fname으로부터 데이터를 읽어 list 배열에 저장
void readArray(int list[], char *fname)
{
    FILE    *fp;
    int     i = 0;
    int     rc;
    
    fp = fopen(fname, "r");
    
    do {
        rc = fscanf(fp, " %d", &(list[i]));
        i++;
    } while (rc != EOF);
}

int main(void)
{
	int  *num;
	int  sum;
	
	// SIZE 크기의 동적 메모리 공간 할당
    num=(int *)malloc(SIZE*sizeof(int));
	
	// "primes.txt"로부터 데이터를 읽어 배열 num에 저장
	readArray(num, "primes.txt");

	// 배열 num의 요소의 합 계산
    sum=cal_sum(num, SIZE);
	
	// 합 출력
	printf("%d\n", sum);

    free(num);
	return 0;
}