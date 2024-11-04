/*아래 그림처럼 3개의 노드에 각각 ‘a’, ‘b’, ‘c’를 저장하고 연결한다.

printList 함수에 의해 각 노드의 내용을 출력한다. List 타입을 정의하여 사용한다.



<입출력 예>

 

a b c

*/

#include <stdio.h>

typedef struct List{
    char data;
    struct list *link;
} List;

// h가 가리키는 노드부터 차례대로 출력
void printList(List *h)
{
    while (h != NULL) {
        printf("%c ", h->data);
        h = h->link;
    }
    printf("\n");
}

int main()
{
    List item1, item2, item3;

    // item1, item2, item3를 그림과 같이 값을 넣고 연결
    item1.data='a';
    item2.data='b';
    item3.data='c';

    item1.link=&item2;
    item2.link=&item3;
    item3.link=NULL;

    printList(&item1);
}
