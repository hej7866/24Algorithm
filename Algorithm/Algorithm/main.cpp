#include <iostream>
#include "Sort.h"
#include "Pow.h"
#include "InputReference.h"
#include "DevideAndConquer.h"
#include "DynamicPrograming.h"
#include "TimeChecker.h"
#include "BackTracking.h"
#include "Array2D.h"
#include "Graph.h"
#include "MST.h"


using namespace std;

int main()
{
	cout << "Algorithm" << endl;

	// 버블정렬 선택정렬 삽입정렬 계수정렬
	cout << "\n"; // 구분

	bubbleExample();
	bubbleExample2();
	selectionExample();
	insertionExample();
	countExample();

	cout << "\n"; // 구분
	
	InputExample();

	// 재귀 예시 (거듭제곱)
	cout << "\n"; // 구분

	cout << "a의 제곱 수 구하기 : " << " ";
	cout << Pow(3, 5) << "\n";

	// 병합정렬
	cout << "\n"; // 구분

	cout << "병합 정렬 " << "\n";
	int list[8] = { 7,6,10,8,3,5,9,1 }; // 병합정렬 예시 리스트
	MergeSort(list, 0, 7); // 정렬하는 함수 실행
	for (int i = 0; i < 8; i++) // 결과 출력
	{
		cout << list[i] << " ";
	}
	
	// 퀵 정렬과 퀵 선택
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

	// 재귀와 DP 피보나치수열 효율성 비교
	cout << "\n"; // 구분

	cout << "재귀 : 피보나치 수열 " << endl;
	int n = 30;
	cout << "피보나치 " << n << "번째 수 : " << Fib(n) << "\n";
	cout << "피보나치 시간 : " << measureExecutionTime(Fib, n) << "ms" << "\n";

	cout << "Dp : 피보나치 수열 " << endl;

	cout << "피보나치 " << n << "번째 수 : " << FibDp(n) << "\n";
	cout << "피보나치 시간 : " << measureExecutionTime(FibDp, n) << "ms" << "\n";

	// 계단 오르기 문제
	cout << "\n"; // 구분
	cout << "계단 오르기 문제(메모이제이션)" << "\n";
	vector<int> stairs = { 10, 20, 15, 25, 10, 20 };
	cout << "계단의 수가(" << stairs.size() << ")인 최대 값 : " << StairCount(stairs) << "\n";


	// 순열 조합
	cout << "\n";
	cout << "순열" << endl;
	Permutation::Case01();
	cout << "조합" << endl;
	Combine::Case02();

	// 2차원 배열
	cout << "\n";
	cout << "2차원 배열" << endl;
	//Board::Case01();
	//Board::Case02();
	//Board::Case03();
	//GraphVec::Print();
	//InputGraph::Show();
	InputWeight::Show();
	InputWeight::Show2();
}