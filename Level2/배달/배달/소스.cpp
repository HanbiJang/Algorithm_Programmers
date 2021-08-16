#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
마을의 개수 N
길 표현 [[마을번호1, 마을번호2], 비용]
K시간 이하로 비용 드는 마을만 가능
*/

struct compare {
public : bool operator() (const pair<int, int> a, const pair<int, int> b) {
        return a.first > b.first; //오름차순 정리
    }
};

vector<int> AllDist; //시작노드부터 0~n까지의 노드들의 비용이 업데이트됨
vector< pair<int, int> > AllCost[55]; // 연결된 리스트 n번째 배열의 [연결된 노드 이름,  비용]
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; // [인접노드i까지의 비용, 인접노드i이름]
/*
AllCost의 구조

1번째 노드                  2번째 노드              . . . n번째 노드
[연결된 노드1, 비용]       [연결된 노드1, 비용]           [연결된 노드1, 비용]
[연결된 노드2, 비용]       [연결된 노드2, 비용]           [연결된 노드2, 비용]               
.                           .                               .
.                           .                               .
.                           .                               .
[연결된 노드m, 비용]   ,    [연결된 노드k, 비용]      ,     [연결된 노드r, 비용]
*/
//비용 기준으로 오름차순 정렬


void Dijkstra(int N) //채워야 하는 답 :  
{


    // 다익스트라 (1) 시작 노드와 인접한 노드들의 통로의 비용을 비교해서 Dist를 업데이트 시켜준다
    AllDist[1] = 0; //시작노드 1이 1자신과의 비용 0
    pq.push(make_pair(0, 1));  // [현재노드까지의 비용, 현재노드이름] 


        //우선순위큐가 비어있지 않을때까지 반복
        while (!pq.empty()) //pq : 방문한적 있는 노드의 모음
        {
            // 다익스트라 (2) 시작노드를 방문한 노드로 체크한다
            
            int cost = pq.top().first;  //시작노드로부터 가는 비용이 가장 작은 노드의 비용
            int cur = pq.top().second;  //시작노드로부터 가는 비용이 가장 작은 노드의 이름 = cur
            pq.pop(); //시작노드로부터 가는 비용이 가장 작은 노드를 방문처리 (삭제)

            
            for (int i = 0; i < AllCost[cur].size(); i++) //cur 노드의 인접 노드수만큼 반복
            { 
                int next = AllCost[cur][i].first; //cur 노드의 인접노드i의 이름 (다음에 갈 노드)
                int ncost = AllCost[cur][i].second; //cur 노드의 인접노드i의 비용 (다음에 갈 노드의 비용)

                // 다익스트라 (3) 방문한 노드와 연결된 노드들 중에서 가는 비용이 가장 적게 드는 노드를 선택한다
                if (AllDist[next] > cost + ncost) 
                {
                    // 다익스트라 (4) 해당 노드를 방문한 노드로 체크한다
                    pq.push(make_pair(cost + ncost, next)); // [인접노드i까지의 비용, 인접노드i이름]
                    // 다익스트라 (5) - (4)에서의 노드가 연결되어 있을 때, 바뀔 Dist 값을 업데이트 해준다
                    AllDist[next] = cost + ncost; //인접노드i까지의 비용 = 현재노드까지의 cost + 인접노드i의 비용

                }

            }
        }
    
}

int solution(int N, vector<vector<int>> road, int K) {
    
    AllDist.resize(N+1, 2e9); //무한대로 비용 값 초기화하기, 2e9 == 무한대

    for (int i = 0; i < road.size(); i++) 
    {
        int N1 = road[i][0]; //노드1
        int N2 = road[i][1]; //노드1과 연결된 노드2
        int cost = road[i][2]; // 노드1과 노드2 사이의 비용

        //노드1과 노드2가 연결되어있으므로 2번 표시
        AllCost[N1].push_back(make_pair(N2, cost)); //노드1 째 배열 : 노드2와 그 비용 cost
        AllCost[N2].push_back(make_pair(N1, cost)); //노드1 째 배열 : 노드2의 그 비용 cost
    }

    Dijkstra(N); //N개의 노드만큼 반복하여 배열들에 값 채움 (얻어야 하는 배열 dist[])

    int answer = 0;
    for (int i = 1; i <= N; i++) 
    {
        if (AllDist[i] <= K) answer++; //가는 비용이 K이하면 카운트함
    }

    return answer;
}

int main() {
    solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3);
    return 0;
}