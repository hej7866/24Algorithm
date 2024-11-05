#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4819)

#define NODENUM 7
#define LINENUM 11

using namespace std;

class Edge
{
private:
    int node[2];
    int distance;
public:
    Edge(int node1, int node2, int distance_)
    {
        node[0] = node1;
        node[1] = node2;
        distance = distance_;
    }

    int first_node()
    {
        return this->node[0];
    }

    int second_node()
    {
        return this->node[1];
    }

    int showDistance()
    {
        return this->distance;
    }

    // 간선 비용 순으로 정렬하기 위해 연산자 재정의
    bool operator < (Edge& edge)
    {
        return this->distance < edge.distance;
    }
};

// 부모 노드를 찾아가는 함수
int getParent(int arr[], int x)
{
    if (x == arr[x]) return x;

    // 문제 2-1)
    /* ★ 부모 노드가 1이 아닌 경우 계속 찾도록 return을 수정하십시오 */
    return arr[x] = getParent(arr, arr[x]);
}

// 부모 노드를 찾어서 합치는 함수
void unionParent(int arr[], int a, int b)
{
    a = getParent(arr, a);
    b = getParent(arr, b);
    if (a < b) arr[b] = a;
    else arr[a] = b;
}

// 부모 노드를 찾어서 같은지 아닌지 판단하는 함수
int findParent(int arr[], int a, int b)
{
    a = getParent(arr, a);
    b = getParent(arr, b);

    // 문제 2-2) 
    /* ★ 부모 노드가 같으면 사이클이고 아니면 사이클이 아닙니다. */
    return (a == b) ? 1 : 0;
}

int main()
{
    // 아래의 수험번호, 성명 수정해서 입력해야 함
    system("mode con cols=80 lines=30 | title KOCCA [Problem 2]");

    printf("■ [문제2] 모반답안 \n■ 수험번호: 수험번호 기재 \n■ 성    명: 성명 기재\n");
    printf("\n■  Kruskal Algrithm ■ \n");

    vector<Edge> v;
    // 노드 정보 입력, 간선(첫번째 노드, 두번째 노드, 간선 비용)
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(5, 7, 73));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(3, 5, 20));

    // 간선 비용에 따르여 오름차순 정렬(연산자 재정의 이용)
    sort(v.begin(), v.end());

    int lines[LINENUM] = { 0 };            // 선택된 간선 정보를 입력하기 위한 배열
    int line_number = 0;                // 선택된 간선 정보를 입력하기 위한 인덱스 변수
    int nodes[NODENUM + 1] = { 0 };        // 노드 정보
    int sum = 0;

    for (int i = 1; i <= NODENUM; i++)    // 노드 정보 nodes[]에 달음
    {
        nodes[i] = i;
    }

    for (int i = 0; i < v.size(); i++)
    {
        // continue;
        if (findParent(nodes, v[i].first_node(), v[i].second_node()) == 1)
        {
            // 사이클이 되는 간선으로 크루스카루 중복 간선임
            printf("사이클 형성 제출 간선 %d - %d 경력 %d\n", v[i].first_node(), v[i].second_node(), v[i].showDistance());
        }
        // 매우 그 간선의 노드들이 다른 부모 노드이면 즉, 연결되어 있지 않으면 
        else
        {
            // 일단 부모 노드를 합(연결)해주고 
            // 문제 2-3)
            /* ★ 이 부분에 주석에 맞는 적정한 함수를 사용하여 결과화면이 나오도록 수정하십시오 */
            unionParent(nodes, v[i].first_node(), v[i].second_node());

            // 클루스카루 연결 간선 값 출력
            printf("클루스카루 최소비용 간선 %d - %d 경력 %d\n", v[i].first_node(), v[i].second_node(), v[i].showDistance());

            // 경력을 lines[] 배열에 넣고 
            lines[line_number] = v[i].showDistance();
            // lines[] 배열의 인덱스 변수를 +1 해줍
            line_number++;
        }
    }

    // 클루스카루 연결 간선 값 출력
    for (int i = 0; i < line_number; i++)
    {
        sum += lines[i];
    }

    printf("\n최소비용 신장트리 합 : %d\n", sum);

    scanf_s("%d");
}
