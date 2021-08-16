#include <string>
#include <vector>
#include <map>
using namespace std;

// [�ǻ��� �̸�, �ǻ��� ����]
int solution(vector<vector<string>> clo) {
    int answer = 1;
    
    map<string, int> mclo; // ���� : ����

    //map�� ������, ���� ����
    //���� ���ϱ�
        //������ �� +1�� *�� - 1 (�˸�)
        

    for (int i = 0; i < clo.size(); i++) { //�������� ������ map�� �ֱ�
        if (mclo.find(clo[i][1]) != mclo.end()) {
            mclo[clo[i][1]]++;
        }
        else {
            mclo.insert(make_pair(clo[i][1], 1));
        }
    }

    //���ձ��ϱ�
    map<string, int>::iterator iter;
    for (iter = mclo.begin(); iter != mclo.end(); iter++) {
        answer *= iter->second + 1;
    }

    return --answer;
}