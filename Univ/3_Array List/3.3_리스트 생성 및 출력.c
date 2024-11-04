/*3개의 노드에 각각 15, 25, 70을 저장하고 순서대로 연결한다.

printList 함수에 의해 각 노드의 내용을 출력한다. 

- ListNode 타입을 정의하여 사용한다.

- 동적 메모리 할당을 사용한다.


<입출력 예>

 

15 25 70
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

void printList(ListNode *h)
{
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->link;
    }
    printf("\n");
}

int main()
{
    ListNode *p1, *p2, *p3;
    p1 = (ListNode *) malloc(sizeof(ListNode));
    p2 = (ListNode *) malloc(sizeof(ListNode));
    p3 = (ListNode *) malloc(sizeof(ListNode));

    p1->data=15;
    p2->data=25;
    p3->data=70;

    p1->link=p2;
    p2->link=p3;
    p3->link=NULL;



    printList(p1);

    free(p1);
    free(p2);
    free(p3);
}
