/*사용자로부터 정수 값을 입력받아 단일 연결 리스트로 생성한다.

리스트 노드는 입력받은 순서대로 연결한다.

단일 연결 리스트 삽입 함수를 사용한다.(교재 참고)

display() 함수에 의해 각 노드의 내용을 출력한다. (교재 참고)

 

 입력을 끝내기 위해 마지막에 -1을 입력한다.
 ListNode 타입을 정의하여 사용한다.
동적 메모리 할당을 사용한다.
 


<입출력 예1>

 

15 25 70 5 10 -1
15 25 70 5 10

<입출력 예2>

 

7 20 12 -1
7 20 12
*/

#include <stdio.h>
#include <stdlib.h>
// ListNode 타입 정의
typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;


// 리스트 출력 함수
void display(ListNode *h)
{
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->link;
    }
    printf("\n");
}

// 삽입 함수
void insert_node() 
{
    // 수업자료 참고
}

int main()
{
    ListNode    *head = NULL;
    ListNode    *p, *new_node;
    int         data;

    p = head;   // 최초에는 리스트가 비어 있으므로 NULL
    // 사용자 입력 처리
    do {
        scanf("%d", &data);
        if (data == -1) break; // -1을 입력하면 입력 종료
        // 1) 동적으로 노드 생성 2) data를 노드에 저장 3) 노드를 리스트에 삽입
        new_node = (ListNode*) malloc(sizeof(ListNode));
        new_node->data=data;
        insert_node(&head, p, new_node);
        p=new_node;
        
    } while (1);

    // 리스트 출력 
    display(head);
}