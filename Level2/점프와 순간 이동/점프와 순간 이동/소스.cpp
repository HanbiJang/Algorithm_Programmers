#include <iostream>
using namespace std;


//���� : kĭ �̵�/ ������ -k, �����̵� : ������ġ *2 , ������ -0
//�����ϴ� �Ÿ� n
//������ ��뷮�� �ּڰ� return

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

//¦��: ����1ĭ

int main() {
    solution(5000);
    return 0;
}