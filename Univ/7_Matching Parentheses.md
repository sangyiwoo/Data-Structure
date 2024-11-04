## Algorithm for Matching Parentheses

### 올바른 괄호 조건
```
1. 왼쪽 괄호 개수 = 오른쪽 괄호 개수
2. 왼쪽 괄호는 짝이 되는 오른쪽 괄호보다 먼저 나와야 함
3. 하나의 괄호 쌍은 다른 괄호 쌍과 교차해서는 안됨
```

---

### 알고리즘

1. 입력 문자열에서 심볼을 하나씩 읽어 처리
    -  왼쪽 괄호이면 스택에 `PUSH`
    - 오른쪽 괄호이면,
        - 스택에서 1개를 `POP`(공백 스택이면 조건 #1 또는 #2 위반)
        - POP된 내용이 오른쪽 괄호와 짝이 맞는지 검사(짝이 안 맞으면, 조건 #3 위반)

2. 입력 문자열을 모두 처리한 후에 스택에 남아 있는 항목이 있으면,
    - `RETURN FALSE`
    - 아니면 `RETURN TRUE`

---

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;		// 교체!
							// 차후에 스택이 필요하면 여기만 복사하여 붙인다.
							// ===== 스택 코드의 시작 =====
#define MAX_STACK_SIZE 100
#define MAX_STR_SIZE   4096


typedef struct {
    element stack[MAX_STACK_SIZE];  
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
    return(s->top==-1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
    return(s->top==(MAX_STACK_SIZE-1));
}
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
	    // push 
	(s->stack[++(s->top)])=item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
	    // pop
	    return (s->stack[(s->top)--]);
}
// 피크함수
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	    // peek
	    return(s->stack[s->top]);
	    
}
// ===== 스택 코드의 끝 =====
int check_matching(const char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);  	// n= 문자열의 길이
	init_stack(&s);			// 스택의 초기화

	for (i = 0; i < n; i++) {
		ch = in[i];		// ch = 다음 문자
		switch (ch) {
		case '(':   case '[':    case '{':
            // push
            push(&s, ch);
            break;

		case ')':   case ']':    case '}':
            // pop 하여 비교. unmatch이면 0을 return
            if(is_empty(&s)) return 0;
            char open_ch = pop(&s);
            if(ch == ')' && open_ch !='(') return 0;
            else if(ch == '}' && open_ch !='{') return 0;
            else if(ch == ']' && open_ch !='[') return 0;
		}
	}
	if (!is_empty(&s)) return 0; // 스택에 남아있으면 unmatch
	return 1;   // match이면 1을 return
}

int main(void)
{
	char    *line = NULL;
	size_t     size;
	getline(&line, &size, stdin);
	if (check_matching(line) == 1)
		printf("%s 괄호검사성공\n", line);
	else
		printf("%s 괄호검사실패\n", line);
	return 0;
}
```