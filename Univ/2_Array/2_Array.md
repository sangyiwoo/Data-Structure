### 2차원 배열 요소의 주소 계산

배열 요소 A[i][j]에 대해,
`address = i*열의 갯수+j`

---

### 함수의 매개변수로 전달

- 배열 이름은 그 배열의 주소(포인터)를 나타낸다.


- #### 1차원 배열의 합

```c
#include <stdio.h>
#define SIZE 6

int cal_sum(int list[], int n)
{
    int sum = 0;
    for(int i=0 ; i<n ; ++i){
        sum += list[i];
    }
    return sum;
}

int main(void)
{
    int num[]={2, 3, 5, 7, 9, 11};
    int sum = cal_sum(num, SIZE);
    printf("합 = %d\n", sum);
    return 0;
}
```

- #### 2차원 배열의 합

```c
#include <stdio.h>
#define ROWS 2
#define COLS 3

int cal_sum(int list[][COLS], int rows, int cols)
{
    int sum = 0;
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            sum+=list[i][j];
        }
    }
    return sum;
}

int main(void)
{
    int num[ROWS][COLS] = {{2,3,5}, {7,9,11}};
    int sum=cal_sum(num, ROWS, COLS);
    printf("합: %d\n", sum);
    return 0;
}
```

#### 만약 cal_sum()함수가 list배열의 형태를 사전에 알지 못한다면?

해당하는 요소가 몇 번째 요소인지 계산하면 됨.

---

## 배열을 활용한 다항식

1. ### 모든 차수에 대한 계수값을 배열로 저장

- 하나의 다항식을 하나의 배열로 표현

```c
typedef struct{
    int degree;
    float coef[MAX_DEGREE];
} polynomial;
polynomial a = {5, {10, 0, 0, 0, 6, 3}};
```

```c
while(Apos<=A.degree && Bbos<=B.degree){
    if(degree_a>degree_b){ //A항>B항
        C.coef[Cpos++]=A.coeg[Apos++];
        degree_a--;
    }
    else if(degree_a==degree_b){ //A항==B항
        C.coef[Cpos++]=A.coef[Apos++]+B.coef[Bpos++];
        degree_a--;
        degree_b--;
    }
    else{ //B항>A항
        C.coef[Cpos++]=B.coef[Bpos++];
        degree_b--;
    }
}
```

- 장점: 다항식의 각종 연산이 간단해짐(덧셈 등)

- 단점: 대부분의 항의 계수가 0이면 공간 낭비가 심함

2. ### 다항식에서 0이 아닌 항만을 배열에 저장

- (계수, 차수)형식으로 배열에 저장

- 하나의 배열로 여러 개의 다항식을 나타낼 수 있음

```c
struct{ //다항식의 항을 저장하는 구조체 정의
    float coef; //계수
    int expon; //지수
} terms[MAX_TERMS]={{10,5}, {6,1}, {3,0}};
```

- 장점: 메모리 공간의 효율적인 이용

- 단점: 다항식의 연산들이 복잡해짐

```c
/*As, Ae: 첫 번째 다항식의 시작과 끝 인덱스 (A의 시작과 끝).
Bs, Be: 두 번째 다항식의 시작과 끝 인덱스 (B의 시작과 끝).
Cs, Ce: 결과 다항식의 시작과 끝 인덱스를 가리키는 포인터.
*/
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
    float tempcoef; //두 계수를 더한 값 임시 저장 변수
    *Cs=avail; //avail 위치에 결과 저장
    while(As<=Ae && Bs<=Be)
    switch(compare(terms[As].expon, terms[Bs].expon)){
        case '>': //A의 차수>B의 차수
            attach(terms[As].coef, terms[As].expon); //A항을 결과에 추가
            As++; //A 다항식 다음 항으로 이동
            break;
        case '=': //A의 차수==B의 차수
            tempcoef = terms[As].coef + terms[Bs].coef; //두 계수를 더함
            if(tempcoef!=0) //더한 값, 즉 계수가 0이 아니라면
                attach(tempcoef, terms[As].expon);//같은 지수로 결과에 추가
            As++; //다음 항 이동
            Bs++;
            break;
        case '<': //A의 차수<B의 차수
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs++;
            break;        
    }
    //같은 차수의 항이 없는 경우
    //A의 나머지 항들을 결과에 추가
    for( ; As<=Ae ; As++)
        attach(Terms[As].coef, terms[As].expon);

    //B의 나머지 항들을 결과에 추가
    for( ; Bs<=Be ; Bs++)
        attach(terms[Bs].coef, terms[Bs].expon);
    *Ce = avail-1; //결과 다항식의 마지막 항의 인덱스를 가리킴

}
```

---

## 배열을 활용한 행렬

#### 1. 2차원 배열을 이용하여 배열의 전체 요소를 저장하는 방법

- 장점: 행렬의 연산들을 간단하게 구현할 수 있음

- 단점: 희소 행렬인 경우 많은 메모리 공간 낭비임

    > Sparse matrix(희소행렬): 대부분의 항들이 0인 배열

#### 2. 0이 아닌 요소들만 저장하는 방법

- 장점: 희소 행렬의 경우, 메모리 공간의 절약

- 단점: 각종 행렬 연산들의 구현이 복잡해짐