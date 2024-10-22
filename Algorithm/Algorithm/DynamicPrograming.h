#pragma once

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