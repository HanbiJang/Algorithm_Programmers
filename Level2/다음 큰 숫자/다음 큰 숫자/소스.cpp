#include <string>
#include <vector>

using namespace std;




// 답 : (1) n보다 큰 자연수, (2) 2진수로 변환했을 때 1의 갯수가 동일하면서 가장 작은 수
int solution(int n) {

    int num1_n = 0;
    int num1_other = 0;
    int num = n+1;


    while (n >= 1) {
        if (n % 2 == 1) num1_n++;
        n /= 2;
    }

    while (1) {
        //이진수로 변환했을 때 1의 갯수 셈

        int num_ = num;
        while (num_ >= 1) {
            if(num_ % 2 == 1) num1_other++;
            num_ /= 2;
        }
        
        if (num1_n == num1_other) return num;

        num1_other = 0;
        num++;
    }
    return -1;
}

int main() {

    solution(78); //83
    return 0;

    // 78 => 
}