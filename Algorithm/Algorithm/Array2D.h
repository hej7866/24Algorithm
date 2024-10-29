#pragma once


#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Board
{
	const int size = 4;

	int board1[size][size];

	vector<string> inputString(size);

	void Case01()
	{
		for (int i = 0; i < size; i++)
		{
			cin >> inputString[i];
		}

		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				board1[y][x] = inputString[y][x] - '0';
			}
		}

		for (int y = 0; y < size; y++)
		{
			for (int x = 0; x < size; x++)
			{
				cout << board1[y][x] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	void Print(const string& s)
	{
		for (int i = 0; i < size; i++)
		{
			cout << s[i] << ' ';
		}
		cout << '\n';
	}

	void Case02()
	{
		int first = 101111;
		string one = to_string(first);

		int second = 101010;
		string two = to_string(second);

		int third = 101011;
		string three = to_string(third);

		int forth = 111000;
		string four = to_string(forth);

		Print(one);
		Print(two);
		Print(three);
		Print(four);
	}

	vector<vector<int>> board2(size, vector<int>(size,0));
	vector<vector<int>> board3(size); // 세로로 열만 하나 만들어놓은느낌 크기는 size

	void Case03()
	{
		cout << "2차원 벡터" << "\n";
		for (int y = 0; y < board2.size(); y++)
		{
			for (int x = 0; x < board2[y].size(); x++)
			{
				cout << board2[y][x] << ' ';
			}
			cout << '\n';
		}


		cout << "push_back 2차원 배열에 값 추가(그래프 알고리즘에 응용)" << "\n";
		cout << "2차원 배열의 크기를 입력하세요: ";
		int n;
		cin >> n;

		// 세로로 열만 하나 만들어놓은 느낌의 2차원 벡터 초기화
		vector<vector<int>> board3(n);

		// 각 행에 값 추가 (예시로 0부터 size-1까지의 값을 추가)
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cout << "board3[" << y << "][" << x << "]에 추가할 값을 입력하세요: ";
				int value;
				cin >> value;
				board3[y].push_back(value); // 각 행에 push_back을 통해 값을 추가
			}
		}

		// 2차원 벡터의 값 출력
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				cout << board3[y][x] << ' ';
			}
			cout << '\n';
		}
	}
}