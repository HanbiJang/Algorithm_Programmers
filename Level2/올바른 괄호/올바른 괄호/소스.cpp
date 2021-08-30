#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    vector<char> box;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            box.push_back(')');
        }
        else {
            if (box.empty()) return false;
            else {
                if ( box[box.size()-1] == ')') {
                    box.pop_back();
                }
                else return false;
            }
        }
    }
    
    if (box.empty()) return true;
    else return false;

}

int main() {

    solution("()()"); //true
    return 0;

}