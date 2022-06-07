#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left, * right;
}Node;

void preorder_search(Node *node) // 전위순회 (부모 먼저) 탐색 알고리즘
{
	printf("[%d] ", node->data);

	if (node->left != NULL)
	{
		preorder_search(node->left);
	}

	if (node->right != NULL)
	{
		preorder_search(node->right);
	}
}

void inorder_search(Node* node) // 중위순회 탐색 알고리즘 (왼쪽 자식 노드 먼저) 탐색 알고리즘
{
	if (node->left != NULL)
	{
		inorder_search(node->left);
	}

	printf("[%d] ", node->data);

	if (node->right != NULL)
	{
		inorder_search(node->right);
	}
}

void postorder_search(Node* node)
{
	if (node->left != NULL)
	{
		postorder_search(node->left);
	}

	if (node->right != NULL)
	{
		postorder_search(node->right);
	}

	printf("[%d] ", node->data);
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

	n1->data = 1;
	n1->left = n2;
	n1->right = n3;

	n2->data = 2;
	n2->left = n4;
	n2->right = n5;

	n3->data = 3;
	n3->left = n6;
	n3->right = n7;

	n4->data = 4;
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 5;
	n5->left = NULL;
	n5->right = NULL;

	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;

	n7->data = 7;
	n7->left = NULL;
	n7->right = NULL;

	printf("// 전위순회 // \n");
	preorder_search(n1);

	printf("\n\n // 중위순회 // \n");
	inorder_search(n1);

	printf("\n\n // 후위순회 // \n");
	postorder_search(n1);

	free(n1, n2, n3, n4, n5, n6, n7);

	return 0;
}