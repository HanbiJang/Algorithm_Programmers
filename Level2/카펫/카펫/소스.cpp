#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //brown + yello = all
    //for all ~ sqt(all)
        //if i�� ��n���� ��������
            // ((i+n)*2-4) == brown �̸� ����

    int all = brown + yellow;

    for (int i = all; i >= sqrt(all); i--) {
        if (all % i == 0) {
            int n = (int) (all / i);
            if ((i+n)*2-4 == brown) {
                answer.push_back(i);
                answer.push_back(n);
                return answer;
            }
        }
    }

    return answer;
}

int main() {
    solution(8,1);
    return 0;
}