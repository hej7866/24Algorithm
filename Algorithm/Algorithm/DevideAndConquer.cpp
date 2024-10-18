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

int QuickSelect(vector<int>& nums, int k)
{
	int length = nums.size();
	if (length == 1) { return nums[0]; }

	// 랜덤한 숫자를 선택해서 그 숫자를 기준으로 둔다
	// 그리고 피벗에 해당하는 숫자를 제일 마지막으로 옮긴다.
	int pIdx = rand() % length;
	int lastIdx = length - 1;
	swap(nums[pIdx], nums[lastIdx]);

	// 왼쪽은 항상 피벗보다 작고, 오른쪽은 항상 피벗보다 크다.
	int lIdx = 0;
	int rIdx = lastIdx - 1;
	int pivot = nums[lastIdx];

	while (lIdx <= rIdx)
	{
		if (nums[lIdx] <= pivot) // 피벗보다 작거나 같은 값이면 lIdx 증가
		{
			lIdx++;
			continue;
		}
		if (pivot < nums[rIdx]) // 피벗보다 큰 값이면 rIdx 감소
		{
			rIdx--;
			continue;
		}

		swap(nums[lIdx], nums[rIdx]); // 피벗 기준으로 큰 값과 작은 값을 교환
	}

	swap(nums[lIdx], nums[lastIdx]); // 피벗을 제자리에 배치

	// k번째 큰 수를 찾는 조건
	if (lIdx == length - k) 
	{
		return nums[lIdx];
	}
	else if (lIdx < length - k) 
	{
		vector<int> rightPart(nums.begin() + lIdx + 1, nums.end());
		return QuickSelect(rightPart, k);  // 오른쪽에서 계속 탐색하므로 k는 그대로
	}
	else 
	{
		vector<int> leftPart(nums.begin(), nums.begin() + lIdx);
		return QuickSelect(leftPart, k - (length - lIdx));  // 왼쪽으로 넘어가면 k를 조정
	}

}

void QuickSort(vector<int>& nums, int begin, int end)
{
	int length = end - begin + 1;
	if (length <= 1) { return; }

	// 랜덤한 숫자를 선택해서 그 숫자를 기준으로 둔다
	// 그리고 피벗에 해당하는 숫자를 제일 마지막으로 옮긴다.
	int pIdx = rand() % length + begin; // 주어진 범위에서 pIdx 선택
	int lastIdx = end; // 끝의 인덱스
	swap(nums[pIdx], nums[lastIdx]);

	// 왼쪽은 항상 피벗보다 작고, 오른쪽은 항상 피벗보다 크다.
	int lIdx = begin;
	int rIdx = lastIdx - 1;
	int pivot = nums[lastIdx];

	while (lIdx <= rIdx)
	{
		if (nums[lIdx] <= pivot) // 피벗보다 작거나 같은 값이면 lIdx 증가
		{
			lIdx++;
			continue;
		}
		if (pivot < nums[rIdx]) // 피벗보다 큰 값이면 rIdx 감소
		{
			rIdx--;
			continue;
		}

		swap(nums[lIdx], nums[rIdx]); // num[lIdx]가 피벗보다 크고 num[rIdx]가 피벗보다 작으면 피벗 기준으로 큰 값과 작은 값을 교환
	}

	swap(nums[lIdx], nums[lastIdx]); // 피벗을 제자리에 배치

	// 피벗을 기준으로 왼쪽과 오른쪽을 재귀적으로 정렬
	QuickSort(nums, begin, lIdx - 1); // 왼쪽 부분 정렬
	QuickSort(nums, lIdx + 1, end);   // 오른쪽 부분 정렬
}


