## Circular Linked List

- 마지막 노드의 링크가 첫번째 노드를 가리키는 리스트
- 한 노드에서 다른 모든 노드로의 접근이 가능
- 헤드가 마지막 노드를 가리키게 구성하면, 단순 연결 리스트에 비해 삽입 연산이 용이함

## Doubly Linked List

### 노드 구조

```c
typedef int element;
typedef struct DlistNode{
    element data;
    struct DlistNode *llink; //왼쪽 방향 포인터
    struct DlistNode *rlink; //오른쪽 방향 포인터
} DlistNode;
```

---

### Insert

```c
//노드 new_node를 노드 before의 오른쪽에 삽입
void dinsert_node(DlistNode *before, DlistNode *new_node)
{
    new_node->llink = before;
    new_node->rlink = before->rlink;
    before->rlink->llink = new_node;
    before->rlink = new_node;
}
```

---

### Delete

```c
//노드 removed를 삭제
void ddelete_node(DlistNode *head, DlistNode *removed)
{
    if( removed == head ) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}
```