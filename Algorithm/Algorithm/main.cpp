#include <iostream>
#include "Sort.h"
#include "Pow.h"
#include "InputReference.h"
#include "DevideAndConquer.h"

using namespace std;

int main()
{
	cout << "Algorithm" << endl;

	cout << "\n"; // 구분

	bubbleExample();
	bubbleExample2();
	selectionExample();
	insertionExample();
	countExample();

	cout << "\n"; // 구분
	
	InputExample();

	cout << "\n"; // 구분

	cout << "a의 제곱 수 구하기 : " << " ";
	cout << Pow(3, 5) << "\n";

	cout << "\n"; // 구분

	cout << "병합 정렬 " << "\n";
	int list[8] = { 7,6,10,8,3,5,9,1 }; // 병합정렬 예시 리스트
	MergeSort(list, 0, 7); // 정렬하는 함수 실행
	for (int i = 0; i < 8; i++) // 결과 출력
	{
		cout << list[i] << " ";
	}

	cout << "\n"; // 구분

	cout << "퀵 정렬 " << "\n";
	vector<int> nums = { 7,6,10,8,3,5,9,1,20,6,13 }; // 퀵 정렬 예시 벡터
	QuickSort(nums, 0, nums.size() - 1);
	for (int n : nums)
	{
		cout << n << " ";
	}
}