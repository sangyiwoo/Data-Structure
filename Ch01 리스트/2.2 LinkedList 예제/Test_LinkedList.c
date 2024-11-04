#include "LinkedList.h"

int main(void)
{
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node*  NewNode = NULL;

    //노드 5개 추가
    for(i=0;i<5;i++)
    {
        NewNode=SLL_CreateNode(i);
        SLL_Append(&List, NewNode);
    }

    NewNode = SLL_Create(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = sLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    //리스트 출력
    Count = SLL_GetNodeCount(List);
    for(i=0;i<Count;i++)
    {
        Count = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Count->Date);
    }

    //리스트의 세 번째 노드 위에 새 노드 삽입
    printf("\nInserting 3000 After [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);

    SLL_InsertAfter(Current, NewNode);

    //리스트 출력
    Count = SLL_GetNodeCount(List);
    for(i=0;i<Count;i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Date);
    }

    //모든 노드를 메모리에서 제거
    printf("\nDestroying List...\n");

    for(i=0;i<Count;i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if(Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }

    return 0;
}