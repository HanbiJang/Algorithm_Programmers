#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
������ ���� N
�� ǥ�� [[������ȣ1, ������ȣ2], ���]
K�ð� ���Ϸ� ��� ��� ������ ����
*/

struct compare {
public : bool operator() (const pair<int, int> a, const pair<int, int> b) {
        return a.first > b.first; //�������� ����
    }
};

vector<int> AllDist; //���۳����� 0~n������ ������ ����� ������Ʈ��
vector< pair<int, int> > AllCost[55]; // ����� ����Ʈ n��° �迭�� [����� ��� �̸�,  ���]
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; // [�������i������ ���, �������i�̸�]
/*
AllCost�� ����

1��° ���                  2��° ���              . . . n��° ���
[����� ���1, ���]       [����� ���1, ���]           [����� ���1, ���]
[����� ���2, ���]       [����� ���2, ���]           [����� ���2, ���]               
.                           .                               .
.                           .                               .
.                           .                               .
[����� ���m, ���]   ,    [����� ���k, ���]      ,     [����� ���r, ���]
*/
//��� �������� �������� ����


void Dijkstra(int N) //ä���� �ϴ� �� :  
{


    // ���ͽ�Ʈ�� (1) ���� ���� ������ ������ ����� ����� ���ؼ� Dist�� ������Ʈ �����ش�
    AllDist[1] = 0; //���۳�� 1�� 1�ڽŰ��� ��� 0
    pq.push(make_pair(0, 1));  // [����������� ���, �������̸�] 


        //�켱����ť�� ������� ���������� �ݺ�
        while (!pq.empty()) //pq : �湮���� �ִ� ����� ����
        {
            // ���ͽ�Ʈ�� (2) ���۳�带 �湮�� ���� üũ�Ѵ�
            
            int cost = pq.top().first;  //���۳��κ��� ���� ����� ���� ���� ����� ���
            int cur = pq.top().second;  //���۳��κ��� ���� ����� ���� ���� ����� �̸� = cur
            pq.pop(); //���۳��κ��� ���� ����� ���� ���� ��带 �湮ó�� (����)

            
            for (int i = 0; i < AllCost[cur].size(); i++) //cur ����� ���� ������ŭ �ݺ�
            { 
                int next = AllCost[cur][i].first; //cur ����� �������i�� �̸� (������ �� ���)
                int ncost = AllCost[cur][i].second; //cur ����� �������i�� ��� (������ �� ����� ���)

                // ���ͽ�Ʈ�� (3) �湮�� ���� ����� ���� �߿��� ���� ����� ���� ���� ��� ��带 �����Ѵ�
                if (AllDist[next] > cost + ncost) 
                {
                    // ���ͽ�Ʈ�� (4) �ش� ��带 �湮�� ���� üũ�Ѵ�
                    pq.push(make_pair(cost + ncost, next)); // [�������i������ ���, �������i�̸�]
                    // ���ͽ�Ʈ�� (5) - (4)������ ��尡 ����Ǿ� ���� ��, �ٲ� Dist ���� ������Ʈ ���ش�
                    AllDist[next] = cost + ncost; //�������i������ ��� = ����������� cost + �������i�� ���

                }

            }
        }
    
}

int solution(int N, vector<vector<int>> road, int K) {
    
    AllDist.resize(N+1, 2e9); //���Ѵ�� ��� �� �ʱ�ȭ�ϱ�, 2e9 == ���Ѵ�

    for (int i = 0; i < road.size(); i++) 
    {
        int N1 = road[i][0]; //���1
        int N2 = road[i][1]; //���1�� ����� ���2
        int cost = road[i][2]; // ���1�� ���2 ������ ���

        //���1�� ���2�� ����Ǿ������Ƿ� 2�� ǥ��
        AllCost[N1].push_back(make_pair(N2, cost)); //���1 ° �迭 : ���2�� �� ��� cost
        AllCost[N2].push_back(make_pair(N1, cost)); //���1 ° �迭 : ���2�� �� ��� cost
    }

    Dijkstra(N); //N���� ��常ŭ �ݺ��Ͽ� �迭�鿡 �� ä�� (���� �ϴ� �迭 dist[])

    int answer = 0;
    for (int i = 1; i <= N; i++) 
    {
        if (AllDist[i] <= K) answer++; //���� ����� K���ϸ� ī��Ʈ��
    }

    return answer;
}

int main() {
    solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3);
    return 0;
}