// dijkstra_adj.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 그래프의 노드 수
#define NUM_NODE	11

///
/// 최단거리 노드 계산 함수
///
int minDistance(int dist[], bool shortestPathTree[])
{
	int min = INT_MAX, min_index;

	// 처리되지않은 노드들 조사 후 최단거리 노드의 인덱스 찾음
	for (int node = 0; node < NUM_NODE; node++)
	{
		if (shortestPathTree[node] == false &&
			dist[node] <= min)
		{
			min = dist[node], min_index = node;
		}
	}

	return min_index;
}

///
/// 최단거리값 화면 출력함수
///
void printSolution(int dist[], int n)
{
	//
	///★ 수험번호, 성명 작성 >> 반드시 수정 필수(수정안하면 감점)
	//
	system("cls");
	system("title KOCCA:[문제3](답안작성용), 수험번호:nnnnnnnn, 성명:홍길동");
	system("mode con:lines=20 cols=68");
	//
	///★ 수험번호, 성명 작성(수정안하면 감점)
	//

	printf("Node           Dist from Src\n");
	for (int i = 0; i < NUM_NODE; i++)
	{
		printf("%d \t\t %d\n", i, dist[i]);
	}

}

///
/// 다익스트라(Dijkstra) 최단거리 경로 알고리즘 구현함수
///
void dijkstra(int edgeCost[NUM_NODE][NUM_NODE], int src)
{
	// 출력 배열
	int distFromSrc[NUM_NODE];
	// 최단거리로 처리된다면 true 입력, 아니면 false 상태임
	bool shortestPathTree[NUM_NODE];

	// 출력배열 초기화, 기본적으로 모든 노드는 false로 세팅
	for (int i = 0; i < NUM_NODE; i++)
	{
		distFromSrc[i] = INT_MAX;
		shortestPathTree[i] = false;
	}

	// 출발점 사이의 거리(출발점은 0 입력)
	distFromSrc[src] = 0;

	// 모든 노드들에 대한 최단경로 찾기
	for (int count = 0; count < NUM_NODE - 1; count++)
	{
		// 최단거리 정보를 알고 있는 노드들 중 가장 거리가 짧은 노드의 인덱스 가져오기
		int curNode = minDistance(distFromSrc, shortestPathTree);

		// 현재 기준 노드의 인접 노드들 거리 갱신하기
		for (int node = 0; node < NUM_NODE; node++)
		{
			///
			///★ 문제 ( B )
			///
			/// - 다음은 최단거리 값 갱신을 위한 조건식이다.
			/// 1. 최단경로트리 상의 아직 처리가 되지 않은 노드일 것
			/// 2. curNode와 node간에 연결이 되어 있어야 할 것(비용 존재하는 간선일 것)
			/// 3. Src로부터 curNode까지 경로가 존재해야 할 것(무한대가 아닐것)
			/// 4. 기존 노드까지의 최단거리 값보다 새 간선 거리값이 추가되어도 더 작아 갱신(Update)이 필요한 경우
			/// 5. 갱신이 되도록 ( B )를 수정하여 완성하시오.
			if ((!shortestPathTree[node]) &&
				edgeCost[curNode][node] != 0 &&
				distFromSrc[curNode] != INT_MAX &&
				distFromSrc[curNode] + edgeCost[curNode][node] < distFromSrc[node])
			{
				distFromSrc[node] = distFromSrc[curNode] + edgeCost[curNode][node]; ///★ 문제 (  B   )///
			}
			///
			///★ 문제 (B)
			///
		}
		// 현재 기준 노드 처리 표시
		shortestPathTree[curNode] = true;
	}
	// 출발점과 노드 사이 거리 출력
	printSolution(distFromSrc, NUM_NODE);
}


int main()
{
	///
	///★ 문제 (A) 제시된 그래프에 맞도록 인접 매트릭스를 수정하여 완성하시오.
	///
	// 노드 집합에 대한 인접 매트릭스
	int graphCost[NUM_NODE][NUM_NODE] = {
		{ 0, 5, 0, 0, 0, 0, 0, 13, 0, 0, 0 },
		{ 5, 0, 7, 0, 0, 0, 0, 9, 0, 0, 0 },
		{ 0, 7, 0, 5, 0, 6, 0, 0, 12, 0, 0 },
		{ 0, 0, 5, 0, 8, 11, 0, 0, 0, 0, 9 },
		{ 0, 0, 0, 8, 0, 13, 0, 0, 0, 5, 0 },
		{ 0, 0, 6, 11,13, 0, 4, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 4, 0, 2, 5, 0, 0 },
		{ 13,9, 0, 0, 0, 0, 2, 0, 7, 0, 15 },
		{ 0, 0, 12,0, 0, 0, 5, 7, 0, 6, 0 },
		{ 0, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0 },
		{ 0, 0, 0, 9, 0, 0, 0, 15, 0, 0, 0 }
	};
	///
	///★ 문제 (A)
	///

	// 0번 노드가 출발점임
	dijkstra(graphCost, 0);

	// 콘솔 대기
	for (;;);

	return 0;
}