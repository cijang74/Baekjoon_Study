#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left, * right;
}Node;

int exculate(Node* node)
{
	if (node->data == NULL)
	{
		return 0;
	}

	if (node->left == NULL && node->right == NULL) // 비단말 노드라면 피연산자이므로 노트의 데이터를 반환
	{
		return node->data;
	}

	else
	{
		int op1 = exculate(node->left);
		int op2 = exculate(node->right);

		switch (node->data)
		{
		case '+':
			printf("%d + %d = %d\n", op1, op2, op1 + op2);
			return op1 + op2;

		case '*':
			printf("%d * %d = %d\n", op1, op2, op1 * op2);
			return op1 * op2;
		}
	}

}

int main()
{
	Node* n1, * n2, * n3, * n4, * n5, * n6, *n7;
	n1 = (Node*)malloc(sizeof(Node));
	n2 = (Node*)malloc(sizeof(Node));
	n3 = (Node*)malloc(sizeof(Node));
	n4 = (Node*)malloc(sizeof(Node));
	n5 = (Node*)malloc(sizeof(Node));
	n6 = (Node*)malloc(sizeof(Node));
	n7 = (Node*)malloc(sizeof(Node));

	n1->data = '+';
	n1->left = n2;
	n1->right = n3;

	n2->data = '*';
	n2->left = n4;
	n2->right = n5;

	n3->data = '+';
	n3->left = n6;
	n3->right = n7;

	n4->data = 3;
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 2;
	n5->left = NULL;
	n5->right = NULL;

	n6->data = 5;
	n6->left = NULL;
	n6->right = NULL;

	n7->data = 6;
	n7->left = NULL;
	n7->right = NULL;

	printf("계산 결과는 %d", exculate(n1));

	free(n1, n2, n3, n4, n5, n6, n7);
	return 0;
}