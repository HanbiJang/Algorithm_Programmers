#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) { 
    int answer_size = number.size()-k;

    for (int j = 0; j < k; j++) {
        
        for (int i = 0; i < number.size()-1; i++) {
            if (number[i] < number[i+1]) {
                number.erase(number.begin() + i);
                break;
            }
           
        }

    }

    //예외처리 72771 (2)
    if (number.size() != answer_size) {
        for (int i = number.size(); i > answer_size; i--) {
            number.erase(number.end()-1);
        }
    }

    return number;
}

int main() {
    solution("72771",2);
    return 0;
}
