#include <stdio.h> // ����¹� ��� ���� ���̺귯��
#include <stdlib.h> // ���� �Ҵ��� ���� �Լ����� ���Ե� ���̺귯��

int input_size()
// ���� ���� �Է� �Լ�
{
	int size = 0;
	scanf("%d", &size);

	return size;
}

void input_number(int size, int* arr)
// ���� �Է� �Լ�
{
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void compare(int size, int* arr, int* compare_result)
// �Է¹��� ������ �ִ밪�� �ּҰ��� ���ϴ� �Լ�
{
	int min = 1000001;
	int max = -1000001;

	for (int j = 0; j < size; j++) // �ּҰ��� ���ϱ� ���� �ݺ���
	{
		if (min > arr[j])
		{
			min = arr[j];
		}
	}

	for (int i = 0; i < size; i++) // �ִ밪�� ���ϱ� ���� �ݺ���
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	compare_result[0] = min;
	compare_result[1] = max;
}

int main()
{
	int size; // ������ ����
	size = input_size(); // ������ ���� �Է�

	int* arr; // �Է¹��� ������ ������ �迭 �����Ҵ�
	arr = (int*)malloc(sizeof(int) * size); // ������ ���� N��ŭ �Ҵ�

	int* compare_result; // �ּڰ��� �ִ��� ������ �迭 �����Ҵ�
	compare_result = (int*)malloc(sizeof(int) * 2);

	input_number(size, arr); // ���� �Է�

	compare(size, arr, compare_result); // ���� ��

	// ���
	printf("%d ", compare_result[0]);
	printf("%d", compare_result[1]);

	// �Ҵ���� �޸� ���� ��ȯ
	free(arr);
	free(compare_result);

	return 0;
}