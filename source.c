#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node
{
	int data;
}node;

node n1 = { 1 };
node n2 = { 2 };
node n3 = { 3 };
node n4 = { 4 };
node n5 = { 5 };
node n6 = { 6 };

void search(node* array)
{
	int i = 1;
	int choose = 0;

	while (i <= 6)
	{
		printf("현재 노드의 값은 %d\n", array[i].data);
		printf("왼쪽 자식 노드로 이동: 1 / 오른쪽 자식 노드로 이동: 2\n");
		scanf("%d", &choose);

		if (choose == 1)
			i *= 2;

		if (choose == 2)
			i = i * 2 + 1;
	}

	printf("더이상 자식 노드가 존재하지 않습니다.");
}

int main()
{
	node array[SIZE];

	array[1] = n1;
	array[2] = n2;
	array[3] = n3;
	array[4] = n4;
	array[5] = n5;
	array[6] = n6;

	search(array);

	return 0;
}