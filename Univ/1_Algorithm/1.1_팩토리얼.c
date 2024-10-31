/*정수 n을 사용자 입력으로 받은 후  n!을 계산한 값을 출력한다.

<입출력 예1>

3

6

<입출력 예2>

5

120
*/

#include <stdio.h>
int fact(int n){
    int result = 1;
    for(int i=1;i<=n;i++)
    {
        result*=i;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fact(n));
    return 0;
}