#pragma once

#include <iostream>
#include <vector>

using namespace std;

// 백준문제 - 바이러스 [2606]
namespace virus
{
	vector<vector<int>> graph(101);
	bool visited[101] = { false };

	int n, m; // n 컴퓨터 수, m(엣지)의 수
	int cnt = 0; // 1번 컴퓨터와 연결된 컴퓨터의 수

	void DFS(int node) // 현재 연결된 컴퓨텨 (node)
	{
		for (int i = 0; i < graph[node].size(); i++)
		{
			int currentNode = graph[node][i];

			if (visited[currentNode]) continue;
			visited[currentNode] = true;
			cnt++;
			DFS(currentNode);
		}
	}

	void Solution_2606()
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b; // 컴퓨터, 정점

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// 컴퓨터 1 감염
		visited[1] = true;
		DFS(1);

		cout << cnt << "\n";
	}
}
