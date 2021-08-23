#include <iostream>
using namespace std;


//점프 : k칸 이동/ 에너지 -k, 순간이동 : 현재위치 *2 , 에너지 -0
//가야하는 거리 n
//에너지 사용량의 최솟값 return

int solution(int n)
{
    int ans = 0;
    int jumpCnt = 0;

    while (1) {
        
        jumpCnt += n % 2;
        n /= 2;
        if (n == 0) break;
    
    }

    return jumpCnt;
}

//짝수: 점프1칸

int main() {
    solution(5000);
    return 0;
}