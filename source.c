#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left, *right;
}Node;

struct Node root = { 0, NULL, NULL };
Node* insert_point, *before_point;

void print(Node* node)
{
	if (node->data == 0)
	{
		printf("[현재 트리가 비었습니다.]\n");
		return;
	}

	if (node->left != NULL)
	{
		print(node->left);
	}

	printf("[%d] ", node->data);

	if (node->right != NULL)
	{
		print(node->right);
	}
}

void binary_search_tree(Node* node, int key)
{
	if (node->data == 0)
	{
		insert_point = node;
	}

	if (node->data == key)
	{
		insert_point = node;
		return;
	}

	else if (node->data > key) // 키값이 노드의 데이터값보다 작다면
	{
		if (node->left == NULL) // 더이상 왼쪽에 노드가 없다면
		{
			insert_point = node;
		}

		else
		{
			before_point = node;
			binary_search_tree(node->left, key);
		}
	}

	else if (node->data < key) // 키값이 노드의 데이터값보다 크다면
	{
		if (node->right == NULL) // 더이상 오른쪽에 노드가 없다면
		{
			insert_point = node;
		}

		else
		{
			before_point = node;
			binary_search_tree(node->right, key);
		}
	}
}

void insert(Node* node, int item)
{
	binary_search_tree(node, item);

	if (insert_point->data == 0)
	{
		root.data = item;
		return;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	new_node->left = NULL;
	new_node->right = NULL;

	if (insert_point->data > item)
	{
		insert_point->left = new_node;
	}

	else if (insert_point->data < item)
	{
		insert_point->right = new_node;
	}

	else
	{
		printf("중복된 값입니다.\n");
		free(new_node);
	}
}

void delete(Node* node, int item)
{
	binary_search_tree(node, item); // 탐색 후

	if (insert_point->data == item) // 일치하는 값을 찾았다면 case를 나누어서 대응
	{
		if (insert_point->left == NULL && insert_point->right == NULL) // case 1: 단말노드라면 부모와의 간선을 없애주면 됨.
		{
			if (before_point->data > insert_point->data)
			{
				before_point->right = NULL;
			}

			else
			{
				before_point->left = NULL;
			}
		}

		else if (insert_point->left == NULL) // case 2-1: 하나의 서브트리만 가지고 있는 경우에는 그 서브트르리를 삭제할 노드 자리에 놓아주면 됨.
		{
			if (before_point > insert_point)
			{
				before_point->right = insert_point->right;
			}

			else
			{
				before_point->left = insert_point->right;
			}
		}

		else if (insert_point->right == NULL) // case 2-2: 하나의 서브트리만 가지고 있는 경우에는 그 서브트르리를 삭제할 노드 자리에 놓아주면 됨.
		{
			if (before_point > insert_point)
			{
				before_point->right = insert_point->left;
			}

			else
			{
				before_point->left = insert_point->left;
			}
		}

		else if (insert_point->right != NULL && insert_point->left != NULL) // case 3: 삭제하려는 노드가 두개의 서브트리를 가지고 있는 경우에는 가장 비슷한 값을 가진 노드를 끌고 와서 앉히면 됨.
		{
			Node* left_max, *right_min, *temp1, *temp2;
			temp1 = (Node*)malloc(sizeof(Node));
			temp2 = (Node*)malloc(sizeof(Node));

			left_max = insert_point->left;
			right_min = insert_point->right;

			while (left_max->right != NULL) // 왼쪽 서브트리에서 가장 큰 값을 찾기 위한 반복문
			{
				if (left_max->right->right == NULL)
				{
					temp1 = left_max->right;
				}
				left_max = left_max->right;
			}

			while (right_min->left != NULL) // 오른쪽 서브트리에서 가장 작은 값을 찾기 위한 반복문
			{
				if (right_min->left->left == NULL)
				{
					temp2 = right_min->left;
				}
				right_min = right_min->left;
			}

			if (insert_point->data - left_max->data < right_min->data - insert_point->data) // 만약에 왼쪽 서브트리에서 가장 큰 값이 가장 비슷한 값이라면
			{

				if (before_point->data > insert_point->data)
				{
					before_point->left = left_max;
				}

				else
				{
					before_point->right = left_max;
				}
				temp1->right = NULL;
			}

			else if (insert_point->data - left_max->data > right_min->data - insert_point->data) // 만약에 오른쪽 서브트리에서 가장 작은값이 가장 비슷한 값이라면
			{

				if (before_point->data < insert_point->data)
				{
					before_point->right = right_min;
				}
				
				else
				{
					before_point->left = right_min;
				}
				temp2->left = NULL;
			}

			//right_min->left = insert_point->left;
			//right_min->right = insert_point->right;
		}
	}
}

int main()
{
	int input = 0;
	int want_key = 0;

	while (1)
	{
		printf("\n이진탐색 트리입니다.\n");
		printf("=========================\n");
		printf("0. 종료\n");
		printf("1. 이진탐색트리 출력\n");
		printf("2. 이진탐색트리 삽입\n");
		printf("3. 이진탐색트리 삭제\n");

		scanf("%d", &input);

		if (input == 0)
		{
			break;
		}

		else if (input == 1)
		{
			system("cls");
			printf("\n이진트리를 탐색합니다.\n");
			print(&root);
		}

		else if (input == 2)
		{
			system("cls");
			printf("\n이진트리에 새로운 노드를 삽입합니다. 삽입할 숫자를 입력해 주세요.\n");
			scanf("%d", &want_key);
			insert(&root, want_key);
		}

		else if (input == 3)
		{
			system("cls");
			printf("\n이진트리에 존재하는 노드를 삭제합니다. 삭제할 숫자를 입력해 주세요.\n");
			scanf("%d", &want_key);
			delete(&root, want_key);
		}

		else
		{
			system("cls");
			printf("\n좆까.\n");
		}
	}

	return 0;
}