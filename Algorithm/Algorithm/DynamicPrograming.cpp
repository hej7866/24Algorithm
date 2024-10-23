#pragma once

#include "DynamicPrograming.h"

vector<int> stairDP;
// 예제 : 백준 12865번, 백준 24416번

// 예시 : 피보나치 수열 문제

int Fib(int n) // 재귀
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
}

int FibDp(int n)
{
	int* dp = new int[n + 1];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}



int max_stair_recursive(int i, vector<int>& stairs)
{
	// stairDP 데이터가 -1이 아니면 바로 반환
	if (stairDP[i] != -1)
	{
		return stairDP[i];
	}

	// 계단을 오르는 아이디어
	// 1층짜리 계단 오르는데 가장 큰 데이터
	if (i == 0)
	{
		return stairs[0];
	}

	// 2층짜리 계단 오르는데 가장 큰 데이터
	if (i == 1)
	{
		return stairs[0] + stairs[1];
	}

	// 3층짜리 계단 오르는데 가장 큰 데이터
	if (i == 2)
	{
		return stairDP[i] = max(stairs[0], stairs[1]) + stairs[2];
	}

	stairDP[i] = max(max_stair_recursive(i - 2, stairs), max_stair_recursive(i - 3, stairs) + stairs[i - 1]) + stairs[i];
	return stairDP[i];
}

int StairCount(vector<int>& stairs)
{
	int size = stairs.size();

	stairDP.assign(size, -1); // DEFAULT 값이 -1이다.

	return max_stair_recursive(size - 1, stairs);
}