#pragma once



// 1. stack을 사용하는 방법 ( 백준 - 28278, 10773)

using namespace std;

#include <stack>

void Data001()
{
	// 스택 선언
	stack<int> myStack;

	// 입력
	myStack.push(1);
	myStack.pop();
	myStack.size();
	myStack.empty();
	myStack.top(); // 스택의 상단을 가리키는 값
}

#include <queue>

void Data002()
{
	// 스택 선언
	queue<int> myQueue;

	// 입력
	myQueue.push(1);
	myQueue.pop();
	myQueue.size();
	myQueue.empty();
	myQueue.front();
	myQueue.back();
}

#include <deque>

void Data003()
{
	// 스택 선언
	deque<int> myDeque;

	// 입력
	myDeque.push_back(1);
	myDeque.push_front(3);
	myDeque.pop_back();
	myDeque.pop_front();
	myDeque.size();
	myDeque.empty();
	myDeque.back();
	myDeque.front();
}
