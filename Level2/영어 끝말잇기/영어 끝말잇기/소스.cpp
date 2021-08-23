#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//탈락하는 사람의 번호, 그사람의 몇번째 순서에 탈락하는지 수
// 중복이면 탈락, 쿵쿵따에 맞는 단어인지, 한글자면 안됨

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m; //중복된 단어 모으기
    char lastChar = words[0][words[0].size() - 1]; //마지막 단어
    
    m.insert({ words[0],0 });
    map<string, int>::iterator iter; 

    if (words[0].size() == 1) { //글자수 1개 첫번째 인간
        return {1,1};
    }
    else {
        for (int i = 1; i < words.size(); i++) {

            if (words[i].size() == 1) { //글자수 1개인지

                answer.push_back((i%n)+1); //몇번째 사람인지
                answer.push_back((int)i/n + 1); //몇번째 턴인지
                return answer;
            }
            else {
                if (lastChar == words[i][0]) //쿵쿵따에 맞는 단어인지
                {
                    for (iter = m.begin(); iter != m.end(); iter++) { //중복된 단어가 있는 경우인지
                        if (m.find(words[i]) != m.end()) { //중복된 단어가 있음
                            answer.push_back((i % n) + 1);
                            answer.push_back((int)i / n + 1);
                            return answer;
                        }
                    }
                    //중복된 단어가 없음
                    m.insert({ words[i], i }); //단어, 순서
                    lastChar = words[i][words[i].size() - 1];
                }
                else { //쿵쿵따에 맞는 단어가 아님

                    answer.push_back((i % n) + 1);
                    answer.push_back((int)i / n + 1);
                    return answer;
                }
            }

        }
    }

    //탈락자가 없음
    return {0,0};
}

int main() {
    solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
    return 0;
}