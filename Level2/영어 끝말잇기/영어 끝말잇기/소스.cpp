#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//Ż���ϴ� ����� ��ȣ, �׻���� ���° ������ Ż���ϴ��� ��
// �ߺ��̸� Ż��, �������� �´� �ܾ�����, �ѱ��ڸ� �ȵ�

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m; //�ߺ��� �ܾ� ������
    char lastChar = words[0][words[0].size() - 1]; //������ �ܾ�
    
    m.insert({ words[0],0 });
    map<string, int>::iterator iter; 

    if (words[0].size() == 1) { //���ڼ� 1�� ù��° �ΰ�
        return {1,1};
    }
    else {
        for (int i = 1; i < words.size(); i++) {

            if (words[i].size() == 1) { //���ڼ� 1������

                answer.push_back((i%n)+1); //���° �������
                answer.push_back((int)i/n + 1); //���° ������
                return answer;
            }
            else {
                if (lastChar == words[i][0]) //�������� �´� �ܾ�����
                {
                    for (iter = m.begin(); iter != m.end(); iter++) { //�ߺ��� �ܾ �ִ� �������
                        if (m.find(words[i]) != m.end()) { //�ߺ��� �ܾ ����
                            answer.push_back((i % n) + 1);
                            answer.push_back((int)i / n + 1);
                            return answer;
                        }
                    }
                    //�ߺ��� �ܾ ����
                    m.insert({ words[i], i }); //�ܾ�, ����
                    lastChar = words[i][words[i].size() - 1];
                }
                else { //�������� �´� �ܾ �ƴ�

                    answer.push_back((i % n) + 1);
                    answer.push_back((int)i / n + 1);
                    return answer;
                }
            }

        }
    }

    //Ż���ڰ� ����
    return {0,0};
}

int main() {
    solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
    return 0;
}