#include "DevideAndConquer.h"
#include <iostream>
#include <vector>

using namespace std;

void MergeSort(int list[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(list, left, mid); // 왼쪽 정렬
		MergeSort(list, mid + 1, right); // 오른쪽 정렬
		Merge(list, left, mid, right); // Merge
	}
}

void Merge(int list[], int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> sorted;

	// 왼쪽 파트와 오른쪽 파트를 비교해서 작은 수 부터 정렬된 공간에 저장을 한다.
	while (leftIdx <= mid && rightIdx <= right)
	{
		if (list[leftIdx] <= list[rightIdx])
		{
			sorted.push_back(list[leftIdx]);
			leftIdx++;
		}
		else if (list[leftIdx] > list[rightIdx])
		{
			sorted.push_back(list[rightIdx]);
			rightIdx++;
		}
	}

	// 왼쪽 파트에 남은 요소를 추가
	while (leftIdx <= mid)
	{
		sorted.push_back(list[leftIdx]);
		leftIdx++;
	}

	// 오른쪽 파트에 남은 요소를 추가
	while (rightIdx <= right)
	{
		sorted.push_back(list[rightIdx]);
		rightIdx++;
	}

	// 정렬된 배열을 원래 배열로 복사
	for (int i = 0; i < sorted.size(); i++)
	{
		list[left + i] = sorted[i];
	}
}
