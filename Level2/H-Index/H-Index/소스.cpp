#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
H-Index�� �� ���� : 
    n���� �迭���� ���� h�̻��� h�� �̻� �ְ�, ������ ������ ���� h����
*/
int solution(vector<int> cit) {
    int h = 0;
    int n = cit.size();

    sort(cit.rbegin(), cit.rend());
    
    for (int j = n; j >= 0; j--) {
        h = j;

        for (int i = 0; i < n; i++) {
            if (cit[i] >= h) {
                if (i + 1 >= h) {

                    return h;
                }
                continue;
            }
            break;
        }
    }
  
    return h;
}

