# Array List

## ArrayListType
```c
typedef int element; //항목들의 타입을 element로 정의
typedef struct{
    element list[MAX_LIST_SIZE]; //배열 정의
    int length; //현재 배열에 저장된 항목들의 개수
} ArrayListType;

//리스트 초기화
void init(ArrayListType *L)
{
    L->length = 0;
}

int is_empty(ArrayListType *L)
{
    return (L->length == 0);
}
```

## Operations
```c
//리스트가 비어 있으면
int is_full(ArrayListType *L)
{
    return(L->length == 0);
}

//리스트가 가득 차 있으면
int is_full(ArrayListType *L)
{
    return(L->length == MAX_LIST_SIZE);
}
```

- ### add()
1. 삽입 가능 검사
2. 삽입 위치에 다음에 있는 요소들을 한 칸씩 뒤로 이동
```c
//position: 삽입하고자 하는 위치
//item: 삽입하고자 하는 자료
void add(ArrayListType *L, int position, element item)
{
    if(!is_full(L) && (position>=0) && (position <= L -> length)){
    //리스트가 가득 차있지 않음&&삽입 위치가 0보다 크거나 같음&&배열의 길이보다 삽입 위치가 작음
        for(int i=(L->length-1) ; i>=position ; i--) //삽입 위치 다음 요소 한칸씩 뒤로 이동
            L->list[i+1] = L->list[i];
        L->list[position] = item; //삽입
        L->length++; //항목 갯수 +1
    }
}
```

- ### delete()
1. 삭제 위치를 검사
2. 삭제 위치부터 맨 끝까지 요소들을 한 칸씩 앞으로 이동

```c
//position: 삭제하고자 하는 위치
//반환값: 삭제되는 자료
element delete(ArrayListType *L, int position)
{
    element item; //삭제 항목 담을 그릇

    if(position<0 || position >= L->length)
    //삭제 위치가 0보다 작거나 위치가 리스트의 길이보다 크거나 같을시
        error("위치 오류");
    item = L->list[position]; //리스트의 삭제 항목 값 저장
    for(int i=position;i<(L->length-1);i++)
        L->list[i] = L->list[i+1];//삭제 위치부터 맨끝까지 요소들 한 칸씩 앞으로 이동
    L->length--;//요소 갯수 -1
    return item; //삭제 값 리턴
}
```