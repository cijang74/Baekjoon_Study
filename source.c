#include <stdio.h> // 입출력문 사용 위한 라이브러리
#include <stdlib.h> // 동적 할당을 위한 함수들이 포함된 라이브러리

int input_size()
// 정수 개수 입력 함수
{
	int size = 0;
	scanf("%d", &size);

	return size;
}

void input_number(int size, int* arr)
// 정수 입력 함수
{
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void compare(int size, int* arr, int* compare_result)
// 입력받은 정수의 최대값과 최소값을 구하는 함수
{
	int min = 1000001;
	int max = -1000001;

	for (int j = 0; j < size; j++) // 최소값을 구하기 위한 반복문
	{
		if (min > arr[j])
		{
			min = arr[j];
		}
	}

	for (int i = 0; i < size; i++) // 최대값을 구하기 위한 반복문
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
	int size; // 정수의 개수
	size = input_size(); // 정수의 개수 입력

	int* arr; // 입력받은 정수를 저장할 배열 동적할당
	arr = (int*)malloc(sizeof(int) * size); // 정수의 개수 N만큼 할당

	int* compare_result; // 최솟값과 최댓값을 저장할 배열 동적할당
	compare_result = (int*)malloc(sizeof(int) * 2);

	input_number(size, arr); // 정수 입력

	compare(size, arr, compare_result); // 정수 비교

	// 출력
	printf("%d ", compare_result[0]);
	printf("%d", compare_result[1]);

	// 할당받은 메모리 공간 반환
	free(arr);
	free(compare_result);

	return 0;
}