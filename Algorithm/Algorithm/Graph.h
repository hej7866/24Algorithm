#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

namespace virus
{
	vector<vector<int>> graph(101);
	bool visited[101] = { false };

	int n, m;      // n 컴퓨터수, m(선)의 수
	int count = 0; // 1번 컴퓨터와 연결된 컴퓨터의 수

	void DFS(int node) // 현재 연결된 컴퓨터(Vertex, node)
	{
		for (int i = 0; graph[node].size(); i++)
		{
			int current = graph[node][i];

			if (visited[current]) continue;

			visited[current] = true;
			count++;
			DFS(current);
		}
	}

	void Example01()
	{
		cin >> n >> m;

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;	  // 컴퓨터, 정점

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// 컴퓨터 1 감염
		visited[1] = true;
		DFS(1);

		cout << count << '\n';
	}
}

namespace GraphVec
{
	int n, m;

	// n 세로의 갯수,  m 가로의 갯수

	vector<vector<int>> graph;



	void Print()
	{
		n = 6, m = 4;

		graph = vector<vector<int>>(n);

		// 입력

		for (int i = 0; i < m; i++)  // i가 선의 갯수 만큼 입력값을 받아옵니다.
		{
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// 정렬

		for (int i = 0; i < n; i++)
		{
			sort(graph[i].begin(), graph[i].end());
		}



		// 출력

		for (int i = 0; i < n; i++)
		{
			cout << "[" << i << "] : ";

			for (int j = 0; j < m; j++)
			{
				// graph[i].연결된 데이터가 없을 때 접근할 방법이없다.
				if (j < graph[i].size())
				{
					cout << graph[i][j] << ' ';
				}
				else
				{
					cout << "@";	    // 0 공백 숫자 1부터 시작,. 
				}
			}
			cout << '\n';
		}


	}
}

namespace InputGraph
{
	// 문자열 형태로 2차원 배열을 표현하라
	// string : char 배열 [0] -> 1

	const int n = 4;
	const int m = 6;

	vector<vector<int>> graph(n, vector<int>(m, 0)); // 4x6 배열 0 할당

	void Show()
	{
		// cin >> n >> m;
		// 입력
		for (int i = 0; i < n; i++)
		{
			string inputString;
			cin >> inputString;

			for (int j = 0; j < m; j++)
			{
				graph[i][j] = inputString[j] - '0';
			}
		}

		// 출력
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << graph[i][j] << ' ';
			}
			cout << '\n';
		}

	}
}




void BFS(int y)
{
	int n, m, start;
	vector<vector<int>> graph(100001);
	bool seen[100001] = { false };

	// BFS Algorithm
	queue<int> q;
	q.push(y);
	seen[y] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i];

			if (!seen[next])
			{
				seen[next] = true;
				q.push(next);
			}
		}
	}
}




void DFS(int y)
{
	int n, m, start;
	vector<vector<int>> graph(100001);
	bool seen[100001] = { false };

	// DFS Algorithm

	// 재귀 탈출 조건
	if (seen[y]) return;
	seen[y] = true; // 보았음

	for (int i = 0; i < graph[y].size(); i++) // DFS(y) 정점의 수 반복문 작성
	{
		int curr = graph[y][i]; // 순회할 vertex의 번호
		DFS(curr);
	}

}