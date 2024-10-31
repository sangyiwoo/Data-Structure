/*사용자로부터 정수 n을 입력받은 후 n번째 피보나치 수열 값을 계산하여 출력한다.

<입출력 예1>

1

1

<입출력 예2>

5

5

<입출력 예3>

6

8
*/

#include <stdio.h>
int fib(int n){
    int result=0;

    if(n<=1) return n;
    
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}