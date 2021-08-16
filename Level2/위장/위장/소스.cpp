#include <string>
#include <vector>
#include <map>
using namespace std;

// [의상의 이름, 의상의 종류]
int solution(vector<vector<string>> clo) {
    int answer = 1;
    
    map<string, int> mclo; // 종류 : 갯수

    //map에 옷종류, 갯수 넣음
    //조합 구하기
        //옷종류 별 +1개 *곱 - 1 (알몸)
        

    for (int i = 0; i < clo.size(); i++) { //옷종류와 갯수를 map에 넣기
        if (mclo.find(clo[i][1]) != mclo.end()) {
            mclo[clo[i][1]]++;
        }
        else {
            mclo.insert(make_pair(clo[i][1], 1));
        }
    }

    //조합구하기
    map<string, int>::iterator iter;
    for (iter = mclo.begin(); iter != mclo.end(); iter++) {
        answer *= iter->second + 1;
    }

    return --answer;
}