#include <string>
#include <vector>

using namespace std;

/* 
--아래 /6번 반복 = 시작: 0  마지막 인덱스 +0,+1,+2, ...
[1] [2] [] [3] [] [] [4] [] [] [] [5] [] [] [] [] [6] [] [] [] [] []

--쭉 /6-1번 반복 = 마지막 인덱스+1
[1] [2] [] [3] [ ] [] [4] [] [] [] [5] [] [] [] [] [6] [7] [8] [9] [10] [11]

--위 /6-2번 반복 마지막 인덱스 -6, -5, -4, ...
[1] [2] [15] [3] [] [14] [4] [] [] [13] [5] [] [] [] [12] [6] [7] [8] [9] [10] [11]

--아래 (오) /6-3번 반복 = 시작: 마지막 인덱스 +2, +3, +4 ...
[1] [2] [15] [3] [16] [14] [4] [17] [] [13] [5] [18] [] [] [12] [6] [7] [8] [9] [10] [11]

--쭉 (오) / 6-4번 반복 = 마지막 인덱스+1
[1] [2] [15] [3] [16] [14] [4] [17] [] [13] [5] [18] [19] [20] [12] [6] [7] [8] [9] [10] [11]

--위 (왼) / 6-5번 반복 마지막 인덱스 -5, ...
[1] [2] [15] [3] [16] [14] [4] [17] [21] [13] [5] [18] [19] [20] [12] [6] [7] [8] [9] [10] [11]
*/

vector<int> solution(int n) {
    int sumN = 0;
    for (int i = 1; i <= n; i++) {
        sumN += i;
    }
    int curIdx = 0;
    int value = 0;
    int case1 = 0;
    int case3 = n;

    vector<int> answer(sumN,0);
    int dir = -1; //-1면 아래, 0 쭉, 1위

    for (int a = n; a >= 1; a--) {
        if (dir == -1) { //아래
            curIdx += case1;

            for (int i = 1; i <= a; i++) {
                answer[curIdx] = ++value;
                if (i != a) curIdx += i + case1;
            }
            case1+=2;
            dir = 0;
        }
        else if (dir == 0) { //쭉
            for (int i = 1; i <= a; i++) {
                answer[++curIdx] = ++value;
            }
            dir = 1;
        }
        else { //위 층, 층-1, 층-2...
            for (int i = 0; i <= (a-1); i++) {
                curIdx -= (case3-i);
                answer[curIdx] = ++value;
            }
            case3--;
            dir = -1;
        }
    }

    return answer;
}

int main() {
    solution(6);
    return 0;
}