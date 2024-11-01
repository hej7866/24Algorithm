#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

void Kruskal()
{
	vector<Edge> edges;

	edges.push_back(Edge(1, 7, 12));
	edges.push_back(Edge(4, 7, 13));
	edges.push_back(Edge(2, 4, 24));
	edges.push_back(Edge(1, 4, 28));
	edges.push_back(Edge(3, 6, 37));
	edges.push_back(Edge(5, 6, 45));
	edges.push_back(Edge(2, 5, 62));
	edges.push_back(Edge(1, 2, 67));
	edges.push_back(Edge(5, 7, 73));	


}