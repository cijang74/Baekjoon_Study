#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int data;
	struct Node* left, * right;
}Node;

void search(Node *node)
{
	int input = 0;

	printf("현재 노드의 데이터 값: %d\n", node->data);
	printf("왼쪽 노드: 1 / 오른쪽 노드: 2\n");
	scanf("%d", &input);

	if (input == 1 && node->left != NULL)
	{
		search(node->left);
	}

	else if (input == 2 && node->right != NULL)
	{
		search(node->right);
	}

	else
	{
		printf("더이상 노드가 존재하지 않습니다.");
	}
	
}

int main()
{
	Node* n1, * n2, * n3, * n4, * n5, * n6;

	n1 = (Node*)malloc(sizeof(Node));
	n2 = (Node*)malloc(sizeof(Node));
	n3 = (Node*)malloc(sizeof(Node));
	n4 = (Node*)malloc(sizeof(Node));
	n5 = (Node*)malloc(sizeof(Node));
	n6 = (Node*)malloc(sizeof(Node));

	n1->data = 1;
	n1->left = n2;
	n1->right = n3;

	n2->data = 2;
	n2->left = n4;
	n2->right = n5;

	n3->data = 3;
	n3->left = n6;
	n3->right = NULL;

	n4->data = 4;
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 5;
	n5->left = NULL;
	n5->right = NULL;

	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;

	search(n1);

	return 0;
}