#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�ݺ������� �ε����� �˻��ؼ� idx�� ����Ű�� ������� ������ ���;���, �˻��ؼ� ������ ���� ���� �Ѿ

bool isRight(string str, string skill) { //skill�� ���������� ������ ���� �ȵ�
    int idx = 0; // skill�� �ε���

    for (int i = 0; i < str.size(); i++) {

        if (skill.find(str[i]) == string::npos) {
            continue; //��ųƮ���� ���� ��Ÿ ��ų�� ���
        }
        else { //��ųƮ���� �ִ� ��ų�� ���
            if (str[i] == skill[idx]) { //������ �¾��� ���
                idx++;
            }
            else { //������ Ʋ���� ���
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