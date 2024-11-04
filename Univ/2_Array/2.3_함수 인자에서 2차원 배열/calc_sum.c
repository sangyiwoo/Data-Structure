#include <stdio.h>

// 1차원 배열 주소
// 행 개수와 열 개수는 코딩 시점에 알 수 없고, 
// 실행 시에 인자로 전달받음.
int calc_sum(int n, int rows, int cols)
{
    int sum=0;
    for(int i=0 ; i<rows ; ++i) //행
    {
        for(int j=0 ; j<cols ; ++j) //열
        {
            sum+=n[i*cols+j]; //행*열 갯수+열
        }
    }
    return sum;
    
}