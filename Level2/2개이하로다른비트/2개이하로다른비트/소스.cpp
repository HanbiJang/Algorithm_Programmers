#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

//경우1 : 끝자리가 1인경우 : 홀수 =>
    // 비트들을 끝부터 앞까지 순회하면서 
    // 1) 1 다음에 0이 나오면 (01) => 10으로 바꿔줌
    // 2) 비트를 숫자로 바꿔줌

//경우2 : 끝자리가 0인경우 : 짝수 => 답 무조건 1큰수


string changeNum(long long num) { //숫자를 비트 문자열로 바꿔줌
    string result = "";
    
    while (num > 0) {
        if(num % 2 >= 1) result.insert(result.begin(), '1');
        else result.insert(result.begin(), '0');
        num /= 2;
    }
    result.insert(result.begin(), '0');
    cout << result;
    return result;
}

long long changeStr(string strNum) { //비트 문자열을 숫자로 바꿔줌
    long long result = 0;

    for (int i = strNum.size() - 1; i >= 0; i--) {
        result += (strNum[i] -'0') * (pow(2, strNum.size() - 1 - i));
    }
    return result;
}

long long CalNum(long long num)
{
    //짝수
    if (num % 2 == 0) { 
        return num + 1; 
    }
    
    //홀수
    else 
    {  
        string strNum  = changeNum(num); //숫자를 비트 문자열로 바꿔줌
        for (int i = strNum.size()-1; i>0; i--) 
        {   
            char n = strNum[i];

            if (strNum[i] == '1' && strNum[i-1] == '0' ) 
            { 
                strNum[i] = '0';
                strNum[i - 1] = '1';

                return changeStr(strNum); //비트 문자열을 숫자로 바꿔줌
            }
        }
    }
}


vector<long long> solution(vector<long long> numbers) {

    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        answer.push_back(CalNum(numbers[i]));
    }

    return answer;
}
