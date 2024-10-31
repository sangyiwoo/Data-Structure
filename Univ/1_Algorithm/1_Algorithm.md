## 팩토리얼

#### 반복
```c
int fact(int n)
{
    int result=1; //0으로 선언 안하게 주의
    for(int i=1;i<=n;i++)
        result*=i;
    return result;
}
```

#### 재귀
```c
int fact(int n)
{
    result=1;
    if(n==1) return 1; //재귀X
    else return n*fact(n-1);
}
```

---

## 피보나치

앞의 두 수의 합이 바로 뒤의 수가 되는 수

#### 반복
```c
int fib(int n)
{
    if(n<2) return n;
    else
    {
        int tmp, current=1, last=0;
        for(int i=2 ; i<=n ; i++)
        {
            tmp=current;
            current=current+last;
            last=tmp;
        }
        return current;
    }
}
```

#### 재귀

```c
int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return (fib(n-1)+fib(n-2));
}
```

---

## 순차 탐색
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int seqsearch(int list[ ], int searchnum, int left, int right) {
    for(int i=left;i<=right;i++)
        if(list[i]==searchnum)
            return i;
    return -1;
}

int prime[] ={여기에 배열 값};

int main()
{
  int search_num;
  int idx;

  scanf("%d", &search_num);
  idx = seqsearch(prime, search_num, 0, 9999);
  printf("%d\n", idx);
}
```

---

## 이진 탐색

##### COMPARE 함수

```c
int COMPARE(int a, int b) //(배열의 중간 값, 찾으려는 값)
{
    if(a>b) return 1; //왼쪽 값이 더 클 경우
    else if(a==b) return 0; //양쪽 값이 같을 경우
    else return -1; //오른쪽 값이 더 클 경우
}
```

##### COMPARE() 매크로

```c
#define COMPARE(a, b)   ((a>b)?1:((a==b)?0:(-1)));
```


#### 반복
```c
int binsearch(int list[], int searchnum, int left, int right)
//(배열, 찾으려는 값, 배열의 맨 왼쪽 값, 맨 오른 쪽 값임)
{
    int middle;
    while(left<=right){
        middle=(left+right)/2;
        switch(COMPARE(list[middle], searchnum)){
            case -1:    left = middle-1; //list[middle]<searchnum
                        break;//switch문이니 break 넣어주기
            case 0:     return middle; //list[middle]==searchnum
            case 1:     right = middle-1; //list[middle]>searchnum
        }
    }
    return -1; 
}
```
while문이 log2(n)번 반복 실행됨

즉, `시간복잡도`는 `O(log n)`임

#### 재귀

```c
int binsearch(int list[], int searchnum, int left, int right)
{
    int middle;
    if(left<=right){
        middle=(left+right)/2;
        switch(COMPARE(list[middle], searchnum)){
            case -1: return binsearch(list, searchnum, middle+1, right); //list[middle]<searchnum
            case 0: return middle; //list[middle]==searchnum, 탐색 성공(재귀 멈춤)
            case 1: return binsearch(list, searchnum, left, middle-1); //list[middle]>searchnum
        }
    }
    return -1;
}
```
---

