# Singly Linked list

- 맨 앞 노드는 head고 마지막 노드의 링크 값은 NULL이어야 함

## Node
노드의 자료령: struct
```c
typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;
```

---

## 생성과 반환
- #### 노드 생성
```c
ListNode *p1;
p1 = (ListNode *) malloc(sizeof(ListNode));
```

- #### 메모리 반환
```c
ListNode *p;
p = (ListNode *) malloc(sizeof(ListNode));
free(p);
```

---

## link
- #### 데이터 필드와 링크 필드 설정
```c
p1->data = 10;
p1->link = NULL;
```

- #### 두번째 노드 생성과 첫번째 노드와의 연결
```c
ListNode *p2;
p2 = (ListNode *) malloc(sizeof(ListNode)); //ListNode사이즈의 메모리를 할당하고 노드 생성
p2->data = 20;
p2->link = NULL;
p1->link = p2;//노드 연결
```

---

## insert

phead:헤드 포인터(head에 대한 포인터)

p: 삽입될 위치의 선행노드를 가리키는 포인터

new_node: 새로운 노드를 가리키는 포인터

#### 삽입의 3가지 경우

1. head가 NULL인 경우(현재 리스트가 비어있는 경우): 공백 리스트에 삽입(삽입하려는 노드가 첫 번째 노드가 됨)

2. p가 NULL인 경우: 리스트의 맨처음에 삽입

3. 일반적인 경우: 리스트의 중간에 삽입

```c
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
    if(*phead == NULL){ //공백리스트인 경우 
        new_node->link = NULL;
        *phead = new_node;
    }
    else if(p == NULL){ //선행노드가 NULL인 경우
        new_node->link = *phead;
        *phead = new_node;
    }
    else{ //p 삽입
        new_node->link = p->link;
        p->link = new_node;
    }
}
```

이중포인터를 사용하는 이유(`**phead`)

- 단일 포인터로는 포인터가 가리키는 데이터를 수정할 수 있지만 포인터가 가리키는 값을 수정할 수 없음
- 헤드의 값을 변경할 때만 이중 포인터를 사용하면 됨
    > 다른 노드는 이미 리스트 내부의 노드를 가리키는 포인터를 사용하고 있기에 필요x

---

## delete

#### 삭제의 2가지 경우

1. p가 NULL인 경우: 맨 앞의 노드 삭제
2. p가 NULL이 아닌 경우: p 다음 노드를 삭제

```c
//phead: 헤드 포인터에 대한 포인터
//p: 선행 노드
//removed: 삭제될 노드
void remove_node(ListNode **phead, listNode *p)
{
    ListNode *removed; //삭제될 노드 포인터 생성

    if(p==NULL){ //p가 NULL인 경우(리스트의 맨 앞 노드 삭제)
        removed = *phead;//삭제할 노드는 헤드
        *phead = (*phead)->link;//헤드 포인터의 값을 헤드 포인터가 가리키는 링크의 값(즉, 다음 노드)로 변경
    }
    else{//p가 NULL이 아닌 경우
        removed = p->link; //삭제할 노드는 선행 노드의 링크
        p->link = removed->link //선행 노드의 링크의 값을 지울 노드의 링크
    }
    free(removed)//삭제
}
```

---

## Traversal

방문 연산: 리스트 상의 노드를 순차적으로 방문
- 반복과 재귀 기법을 모두 사용 가능

### 반복 ver
```c
void display(ListNode *head)
{
    ListNode *p = head; //p라는 리스트 선언 후 head로 초기화
    while(p != NULL){ 
        printf("%d->", p->data);
        p = p->link; //다음 노드로 이동
    }
    printf("\n");
}
```

### 재귀 ver
```c
void display_recur(ListNode *head)
{
    ListNode *p = head;
    if( p != NULL ){
        printf("%d->", p->data);
        display_recur(p->link); //재귀
    }
}
```

---

## search()

탐색: 특정한 데이터 값을 갖는 노드를 찾는 동작

```c
ListNode *search(ListNode *head, int x)
{
    ListNode *p;
    p = head;
    while(p != NULL ){
        if( p->data == x ) return p; //탐색 성공
        p = p->link;
    }
    return p;//탐색 실패시 NULL 반환
}
```

---

## concat()

접합: 2개의 리스트를 합하는 동작

```c
ListNode *concat(ListNode *head1, ListNode *head2)
{
    ListNode *p;
    if( head1 == NULL ) return head2;
    else if( head2 == NULL ) return head1;
    else{
        p = head1;
        while( p->link != NULL )
            p = p->link;
        p->link = head2;
        return head1;
    }
}
```

시간복잡도: 

---

## reverse()

```c
ListNode *reverse(ListNode *head)
{(
    //p: 현재 노드
    //q: 이전 노드
    //r: 인시로 이전 노드 저장하는 포인터
    ListNode *p, *q, *r;
    p = head; //처음이니 현재 노드는 헤드
    q = NULL; //이전 노드가 없으니 초기값
    while(p != NULL){ //리스트 끝까지 반복
        r = q; //이전 노드를 r에 저장
        q = p; //이전 노드를 현재 노드로 업데이트
        p = p->link; //다음 노드로 이동
        q->link = r; //q의 link를 이전 노드로 설정(역순으로 만듬)
    }
    return q;
}
```