#include <stdio.h>
#include <string.h> // strcmp 함수 쓰기 위한 헤더
#include <stdlib.h> // malloc을 쓰기 위한 헤더

// 전역 변수
int stack_top = -1;
int how_many = 0; // 카운트

void push(int* stack) // 정수 X를 스택에 넣는 연산이다.
{
	// 스택에 넣을 정수 X
	int input = 0;
	scanf("%d", &input);

	// 적절한 인덱스에 정수 넣기, 카운트++
	stack[how_many] = input;
	stack_top = input;
	how_many++;
}

void pop(int* stack) // 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
{
	if (how_many == 0)
		// 스택에 들어있는 정수가 없다면
	{
		printf("-1\n");
	}

	else
		// 스택에 정수가 들어있다면
	{
		printf("%d\n", stack[how_many - 1]); // 넣을 자리가 아니라 넣어진 자리를 찾아야 하므로 카운트 -1
		how_many--;

		if (how_many != 0)
		{
			stack_top = stack[how_many - 1]; // top 업데이트
		}
		

		else if(how_many == 0)
		{
			stack_top = -1;
		}
	}
}

void size() // 스택에 들어있는 정수의 개수를 출력한다.
{
	printf("%d\n", how_many);
}

void empty() // 스택이 비어있으면 1, 아니면 0을 출력한다.
{
	if (how_many == 0)
		// 스택이 비어있으면
	{
		printf("1\n");
	}

	else
		// 스택이 비어있지 않으면
	{
		printf("0\n");
	}
}

void top() // 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
{
	printf("%d\n", stack_top);
}

int compare(char input[], int* stack) // 사용자가 어떠한 명령어를 넣었는지 검사하는 함수
{
	if (!(strcmp(input, "push")))
		// 만약 사용자가 입력한 값이 "push"라면
	{
		push(stack);
		return 0;
	}

	else if (!(strcmp(input, "pop")))
		// 만약 사용자가 입력한 값이 "pop"라면
	{
		pop(stack);
		return 0;
	}

	else if (!(strcmp(input, "size")))
		// 만약 사용자가 입력한 값이 "size"라면
	{
		size();
		return 0;
	}

	else if (!(strcmp(input, "empty")))
		// 만약 사용자가 입력한 값이 "empty"라면
	{
		empty();
		return 0;
	}

	else if (!(strcmp(input, "top")))
		// 만약 사용자가 입력한 값이 "top"라면
	{
		top();
		return 0;
	}

	else
		// 정상적이지 않은 명령이 입력되었다면
	{
		printf("올바르지 않은 입력입니다.\n");
		printf("다시 입력해 주세요.\n");
		return 1;
	}
}

int main() // 메인 함수
{
	int size = 0;

	scanf("%d", &size); // 사용자에게서 사이즈를 입력

	while (size < 1 || size > 10000) // 올바른 값을 입력할 때 까지 반복
	{
		printf("올바르지 않은 입력입니다.\n");
		printf("다시 입력해 주세요.\n");
		scanf("%d", &size); // 사용자에게서 사이즈를 입력
	}

	int* stack;
	stack = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
		// 입력받은 Size만큼 명령어를 받는다.
	{
		char input[10] = "\0";
		int worng_check = 0;

		scanf("%s", input);
		worng_check = compare(input, stack);

		if (worng_check)
			// 정상적이지 않은 명령어는 for문의 카운트로 세지 않음.
		{
			i--;
		}
	}

	free(stack); // 모든 명령어 실행 후에는 동적 할당받은 메모리 공간 반환

	return 0;
}