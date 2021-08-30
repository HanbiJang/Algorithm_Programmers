#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//반복문으로 인덱스를 검사해서 idx가 가르키는 순서대로 끝까지 나와야함, 검색해서 없으면 다음 수로 넘어감

bool isRight(string str, string skill) { //skill을 전역변수로 넣으면 값이 안들어감
    int idx = 0; // skill상 인덱스

    for (int i = 0; i < str.size(); i++) {

        if (skill.find(str[i]) == string::npos) {
            continue; //스킬트리에 없는 기타 스킬일 경우
        }
        else { //스킬트리에 있는 스킬일 경우
            if (str[i] == skill[idx]) { //순서가 맞았을 경우
                idx++;
            }
            else { //순서가 틀렸을 경우
                return false;
            }
        }

    }

    return true;

}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int a = 0; a < skill_trees.size(); a++) {

        if (isRight(skill_trees[a], skill)) {
            answer++;
        }

    }

    return answer;
}

int main() {
    solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });
    return 0;
}