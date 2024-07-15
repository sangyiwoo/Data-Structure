//링크드 리스트 헤더 파일의 중복 방지하기 위한 전처리기 지시자
#ifdef LINKEDLIST_H //LINKEDLIST_H가 정의 되지 않았다면 다음 코드를 포함하도록 함
// 이 지시자가 없으면 동일한 헤더 파일을 여러 번 포함될 때 중복 정의로 인한 컴파일 오류 발생할 수 있음
#define LINKEDLIST_H//LINKEDLIST_H를 정의하여 이 파일이 포함되었음을 표시

#include <stdio.h>
#inlcude <stdlib.h>//메모리할당 함수를 사용하기 위한 라이브러리

typedef int ElementType;//ElementType을 int로 정의(저장할 데이터의 타입)

//노드 구조체 정의
typedef struct tagNode
{
    ElementType Data; //노드가 저장하는 데이터 변수
    struct tagNode* NextNode; //다음 노드를 가리키는 포인터 변수
    /*같은 tagNod타입의 다른 노드를 가리킴.
    즉, 하나의 노드가 다음 노드를 가리키고, 그 다음 노드는 또 다른 노드를 가리키는 방식으로 연결*/
} Node; //struct tagNode를 Node라고 정의

//함수 원형 선언
Node* SLL_CreateNode(ElementType NewData); //노드 생성 함수
void SLL_DestroyNode(Node* Node); //노드 소멸 함수
void SLL_AppendNode(Node** Head, Node* NewNode); //노드 추가 함수
void SLL_InsertAfter(Node* Current, Node* NewNode); //현재 노드 뒤에 새 노드를 삽입하는 함수
void SLL_InsertNewHead(Node** Head, Node* NewHead);//리스트 헤드 부분에 새 노드 삽입 함수
void SLL_RemoveNode(Node** Head, Node* Remove);//노드 삭제 함수
Node* SLL_GetNodeAt(Node* Head, int Location);//노드 탐색 함수
int SLL_GetNodeCount(Node* Head);//노드 개수 세는 함수

#endif//ifdef의 끝을 표시