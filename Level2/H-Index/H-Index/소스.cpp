#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
H-Index가 될 조건 : 
    n개의 배열에서 값이 h이상이 h개 이상 있고, 나머지 논문들의 값이 h이하
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

