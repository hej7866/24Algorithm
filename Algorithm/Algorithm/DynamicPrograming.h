#pragma once

#include <vector>

using namespace std;

#define DEFAULT -1


// 예제 : 백준 24416번(알고리즘 수업 - 피보나치 수 1), 백준 2579번(계단오르기) , 백준 12865번(평범한 배낭), 백준 14916번(거스름돈 문제)
// 예시 : 피보나치 수열 문제

int Fib(int n); // 재귀

int FibDp(int n); // DP


// 목표 층까지 도달할 때 가장 높은 점수로 계단을 밟고 지나가는 경우를 구하세요
// 가장 높은 점수가 무엇인가?
// 규칙1. 계단은 한번엔 1개 또는 2개 씩만 오를 수 있다.
// 규칙2. 연속해서 계단을 1개씩만 오를 수 없습니다.
// 규칙3. 위 방식으로 최대의 앖을 얻을 수 있는 방식으로 계단을 오르세요.
int max_stair_recursive(int i, vector<int>& stairs);

int StairCount(vector<int>& stairs);