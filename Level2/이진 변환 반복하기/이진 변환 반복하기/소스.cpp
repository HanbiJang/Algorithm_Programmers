#include <string>
#include <vector>

using namespace std;

string changeNum(int num) { //숫자를 비트 문자열로 바꿔줌
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

    //"이진변환"
    while (s.size() != 1) {
        int eraseNum = 0;
        binaryNum++;
        int origSize = s.size();

        // x의 모든 0을 제거하기
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') eraseNum++;
        }   

        //이진변환하기
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