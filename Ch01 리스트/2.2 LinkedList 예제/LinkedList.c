#include "LinkedList.h"

//노드 생성
Node* SLL_CreateNode(ElementType NewData)//데이터를 저장하는 새로운 노드를 생성하여 반환하는 함수 정의
/*`Node*`: Node 구조체를 가리키는 포인터 타입임*/
{
    Node* NewNode = (Node*)malloc(sizeof(Node));//Node구조체 크기만큼의 메모리를 동적 할당
    /*`malloc`: 표준 라이브러리 함수(stdlib.h)로 요청한 바이트 수만큼의 메모리를 동적으로 할당함
    `sizeof(Node)`: `Node` 구조체의 크기를 바이트 단위로 계산*/

    NewNode->Data = NewData;//할당된 노드의 Data 필드에 NewData 저장
    NewNode->NextNode= NULL;//새 노드의 NextNode 포인터를 NULL 초기화

    return NewNode;//생성된 새 노드 반환
}

//노드 소멸
void SLL_DestroyNode(Node* Node)
{
    free(Node); //malloc로 할당된 메모리를 해제함
}

//노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode)
{
    if( (*Head) == NULL )//리스트가 비어있는 경우
    {
        *Head = NewNode;//새 노드를 헤드로 설정
    }
    else
    {
        //테일을 찾아 NewNode를 연결한다.
        Node* Tail = (*Head);
        while( Tail->NewNode != NULL )
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;//리스트의 마지막 노드를 NewNode로 설정
    }
}

//현재 노드 뒤에 새로운 노드 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;//새 노드의 NextNode를 현재 노드의 NextNode로 설정
    Current->NextNode = NewNode;//현재 노드의 NextNode를 새 노드로 설정 
}

//리스트의 헤드에 새 노드 삽입
void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if( Head == NULL )//리스트가 비어있는 경우
    {
        (*Head) = NewNode;//새 노드를 헤드로 설정
    }
    else//리스트가 비어있지 않은 경우
    {
        NewHead->NextNode = (*Head);//새로운 노드의 다음 노드를 헤드값 저장
        (*Head) = NewNode;//헤드에 새로운 노드 설정 
    }
}

//노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if( *Head == Remove )//제거할 노드가 헤드인 경우
    {
        *Head = Remove->NextNode;//헤드를 지울 노드의 다음 노드로 설정
    }
    else//제거할 노드가 헤드가 아닌 경우
    {
        Node* Current = *Head;//헤드를 현재 노드로 설정
        while( Current != NULL && Current->NextNode != Remove )
        //현재 노드가 NULL이 아니고 현재 노드의 다음 노드가 지울 노드가 아닌 경우
        {
            Current = Current->NextNode;//현재 노드를 현재 노드의 다음 노드로 설정
        }

        if( Current != NULL )//현재 노드가 NULL인 경우
            Current->NextNode = Remove->NextNode;//현재 노드의 다음 노드에 지울 노드의 다음 노드를 저장
    }
}

//노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location)
//Node* Head: 리스트의 첫 번째 노드를 가리키는 포인터, int Location: 찾고자 하는 노드의 위치(0부터 시작하는 인덱스로 가정)
{
    Node* Current = Head; //현재 노드를 헤드로 설정

    while( Current != NULL && (--Location) >= 0 ) //현재 노드가 NULL이 아니고 위치의 앞앞이 0보다 크다면
    //Location 값을 감소 시키면서 0 이상일때까지 반복
    {
        Currrent = Current->NextNode;//현재 노드를 현재 노드의 다음 노드로 설정
    }
    
    return Current;//현재 노드 반환
}

//노드 개수 세기
int SLL_GetNodeCount(Node* Head)//매개변수: 첫번째 노드를 가리키는 포인터
{
    int count = 0;//노드를 세기 위한 변수
    Node* Current = Head;//현재 노드를 헤드로 설정

    while( Current != NULL )//현재 노드가 NULL이 아닐 시 반복
    {
        Current = Current->NextNode;//현재 노드를 현재 노드의 다음 노드로 설정
        Count++//카운트 증가
    }

    return Count;//카운트 반환
}