/*
인자로 주어진 변수값을 1씩 증가시키는 함수 increment()을 작성하시오.
작성한 함수 increment()을 이용하여 사용자가 입력한 정수 값을 1증가시킨 후 출력하시오.
함수의 인자 전달방식은 call-by-address를 이용한다.

<입출력 예1>

 

37
38

<입출력 예2>

 

7
8
*/

#include <stdio.h>

// 인자로 주어진 주소에 들어있는 값을 증가
void increment(int *num)
{
    *num=*num+1; //또는 (*num)++도 가능
}

int main(void)
{
    int     num;
    scanf("%d", &num);
    
    // num의 주소를 인자로 increment()함수 호출
    increment(&num);     // 이부분 수정
    
	printf("%d\n", num);
}