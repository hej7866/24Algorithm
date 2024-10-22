#include <iostream>
#include "Sort.h"
#include "Pow.h"
#include "InputReference.h"
#include "DevideAndConquer.h"
#include "DynamicPrograming.h"
#include "TimeChecker.h"


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
	cout << "\n";
	cout << "3번째로 큰 수 : " << QuickSelect(nums, 7) << "\n";

	cout << "\n"; // 구분

	cout << "재귀 : 피보나치 수열 " << endl;
	int n = 30;
	cout << "피보나치 " << n << "번째 수 : " << Fib(n) << "\n";
	cout << "피보나치 시간 : " << measureExecutionTime(Fib, n) << "ms" << "\n";

	cout << "Dp : 피보나치 수열 " << endl;

	cout << "피보나치 " << n << "번째 수 : " << FibDp(n) << "\n";
	cout << "피보나치 시간 : " << measureExecutionTime(FibDp, n) << "ms" << "\n";
}