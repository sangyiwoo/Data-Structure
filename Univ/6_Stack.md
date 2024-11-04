## Stack

- 후입선출

### is_empty(), is_full

```
is_empty(S)

if top = -1
    then return TRUE
    else return FALSE
```

```
is_full(S)

if top = (MAX_STACK_SIZE-1)
    then return TRUE
    else return FALSE
```

---

```c
typedef int element; //자료형
typedef struct{
    element stack[MAX_STACK_SIZE]; //스택을 저장할 배열
    int top; //스택 최상단 요소를 가리키는 인덱스
} StackType;

//스택 초기화
void init(StackType *s)
{
    s->top = -1;
}

//스택 비어있나 확인
int is_empty(StackType *s)
{
    return (s->top == -1);
}

//스택 가득 찼나 확인
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE-1));
}

//요소 삽입
void push(StackType *s, element item)
{
    if(is_full(s)){
        fprintf(stderr, "Stack full.\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}

//요소 삭제 후 반환
element pop(StackType *s)
{
    if (is_empty(s)){
        fprintf(stderr, "Stack empty.\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}

//최상단 요소 반환(삭제x)
element peek(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "Stack empty.\n");
        exit(1);
    }
    else return s->stack[s->top];
}
```

---
---

## Linked Stack

```c
typedef int element; //자료형 정의

typedef struct StackNode{ //노드 정의 구조체
    element item; //스택에 저장할 데이터
    struct StackNode *link; //다음 노드를 가리키는 포인터
} StackNode;

typedef struct{ //스택 리스트 구조체
    StackNode *top; //스택의 최상단을 가리키는 포인터
} LinkedStackType;
```

---

- ### push()
```c
void push(LinkedStackType *s, element item)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode)); //StackNode*타입으로 StackNode 사이즈의 메모리를 할당
    temp->item = item;
    temp->link = s->top; //스택 맨 위 노드와 연결
    s->top = temp;//스택 최상단 노드를 새 노드로 갱신
}
```

---

- ### pop()

```c
element pop(LinkedStackType *s)
{
    StackNode *temp;//스택에서 꺼낼 임시 저장용 포인터
    elemnt item; //스택에서 꺼낸 노드 저장용
    if(is_empty(s))
    {
        exit(1);
    }
    else
    {
        temp = s->top; //최상단 노드 저장
        item = temp->item; //최상단 노드의 데이터 저장
        s->top = s->top->link; //최상단 노드 다음 노드로 갱신
        free(temp); //꺼낸 노드 메모리 해제
        return item; //꺼낸 데이터 반환
    }
}
```