#include <string>
#include <vector>

using namespace std;

string changeNum(int num) { //���ڸ� ��Ʈ ���ڿ��� �ٲ���
    string result = "";

    while (num > 0) {
        if (num % 2 >= 1) result.insert(result.begin(), '1');
        else result.insert(result.begin(), '0');
        num /= 2;
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int eraseSum = 0;
    int binaryNum = 0;

    //"������ȯ"
    while (s.size() != 1) {
        int eraseNum = 0;
        binaryNum++;
        int origSize = s.size();

        // x�� ��� 0�� �����ϱ�
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') eraseNum++;
        }   

        //������ȯ�ϱ�
        s = changeNum(origSize - eraseNum);

        eraseSum += eraseNum;
    }

    answer.push_back(binaryNum);
    answer.push_back(eraseSum);
    return answer;
}

int main() {
    solution("110010101001");
    return 0;
}