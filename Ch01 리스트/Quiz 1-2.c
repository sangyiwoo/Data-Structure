//내가 짠 코드(잘못됨)
void SLL_InsertBefore( Node** Head, Node* Current, Node* NewHead )
{
    if((*Head)==Current)
    {
        (*Head)=Current->NextNode;
    }
    else{
        NewNode->NextNode=(*Current);
        Current=NewNode;
    }
}
/*내 코드의 논리적 오류
1. 리스트가 비어 있는 경우 경우를 고려하지 않음
2. 삽입하려는 위치가 리스트의 첫 번째 노드인 경우의 전개 과정이 잘못됨
3. 리스트의 중간에 삽입하려는 경우의 전개 과정이 잘못됨*/


//참고 정답
void SLL_insertBefore(Node** head, Node* current, Node* newNode) {

    // 리스트가 비어있는 경우
	if ((*head) == NULL) {
		printf("비어있는 노드 입니다.");//경고 메세지 출력
		return;//함수 종료
	}

    //삽입하려는 위치가 리스트의 첫 번째 노드인 경우
	else if ((*head) == current) {
		newNode->NextNode = (*head);//새 노드의 다음 노드를 현재의 헤드 노드로 설정
		*head = newNode;//헤드 포인터값을 새 노드로 변경
	}

    //리스트의 중간에 삽입하려는 경우
	else {
		Node* prev = NULL;//현재 노드의 이전 노드를 추적하기 위한 포인터
		Node* now = *head;//현재 노드를 추적하기 위한 포인터
        //현재 노드가 NULL이 아니고, 현재 노드가 찾고자 하는 노드가 아닐 때까지 반족
		while (now->NextNode != NULL) {
			prev = now;//이전 노드에 현재 노드 값 저장
			now = now->NextNode;//현재 노드에 다음 노드 값 저장
			if (now == current) {//현재 노드가 찾고자 하는 노드와 일치 시
				break;
			}
		}
		newNode->NextNode = now;//새로운 노드의 다음 노드에 현재 값 저장
		prev->NextNode = newNode;//이전 노드의 다음 노드에 새로운 노드 저장
	}
}