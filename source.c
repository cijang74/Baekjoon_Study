#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left, * right;
}Node;

int exculate(Node* node)
{
	if (node->left != NULL && node->right != NULL)
	{
		int op1 = exculate(node->left);
		int op2 = exculate(node->right);
		int result = op1 + op2;

		return (node->data + result);
	}
		
	else
	{
		return (node->data);
	}
}

int main()
{
	Node* n1, * n2, * n3, * n4, * n5;
	n1 = (Node*)malloc(sizeof(Node));
	n2 = (Node*)malloc(sizeof(Node));
	n3 = (Node*)malloc(sizeof(Node));
	n4 = (Node*)malloc(sizeof(Node));
	n5 = (Node*)malloc(sizeof(Node));

	n1->data = 0;
	n1->left = n2;
	n1->right = n3;

	n2->data = 50;
	n2->left = NULL;
	n2->right = NULL;

	n3->data = 100;
	n3->left = n4;
	n3->right = n5;

	n4->data = 200;
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 500;
	n5->left = NULL;
	n5->right = NULL;

	printf("계산 결과는 %d", exculate(n1));

	free(n1, n2, n3, n4, n5);
	return 0;
}