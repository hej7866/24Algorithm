#pragma once

#include <vector>
#include <iostream>

using namespace std;

// 최소 신장 트리 (minimum spanning tree)

namespace InputWeight
{
	vector<pair<pair<int, int>, int>> edges;

	void Show()
	{
		// make_pair<a,b>
		edges.push_back({ { 1,2 }, 10 });
		edges.push_back({ { 1,3 }, 15 });
		edges.push_back({ { 2,3 }, 5 });
		edges.push_back({ { 2,4 }, 18 });
		edges.push_back({ { 3,4 }, 25 });

		for (const auto& edge : edges)
		{
			cout << "Edge : (" << edge.first.first << "," << edge.first.second << "), weight :" << edge.second << "\n";
		}
	}

	class Edge
	{
	private:
		int node[2];
		int distance;
	public:
		Edge(int node1, int node2, int _distance)
		{
			node[0] = node1;
			node[1] = node2;
			distance = _distance;
		}

		int first_node() { return this->node[0]; }
		int second_node() { return this->node[1]; }
		int getDistance() { return this->distance; } // 함수 이름 수정

		// 연산자 오버로딩
		bool operator < (Edge& edge)
		{
			return this->distance < edge.distance;
		}
	};

	void Show2()
	{
		vector<Edge> edges;

		edges.push_back(Edge(1, 2, 10));
		edges.push_back(Edge(1, 3, 15));
		edges.push_back(Edge(2, 3, 5));
		edges.push_back(Edge(2, 4, 18));
		edges.push_back(Edge(3, 4, 25));

		for (auto& edge : edges)
		{
			cout << "Edge : (" << edge.first_node() << ", " << edge.second_node() << "), weight : " << edge.getDistance() << "\n"; // 출력 형식 수정
		}

		sort(edges.begin(), edges.end());

		for (auto& edge : edges)
		{
			cout << "Edge : (" << edge.first_node() << ", " << edge.second_node() << "), weight : " << edge.getDistance() << "\n"; // 출력 형식 수정
		}
	}
}

namespace Union_Find
{
	// 서로소 문제

	int getParent(int arr[], int x) // 그래프를 주어졌을 때 루트노드(부모)	
	{
		if (x == arr[x]) return x;

		return getParent(arr, arr[x]);
	}

	void UnionParent(int arr[], int a, int b) // 두개의 그래프를 하나로 합친다.
	{
		a = getParent(arr, a);
		b = getParent(arr, b);

		if (a < b) arr[b] = a;
		else
		{
			arr[a] = b;
		}
	}

	bool findParent(int arr[], int a, int b)  // 같은지 아닌지
	{
		a = getParent(arr, a);
		b = getParent(arr, b);

		return a == b;
	}
}
