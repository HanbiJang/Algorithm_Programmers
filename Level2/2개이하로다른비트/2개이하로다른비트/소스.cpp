#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

//���1 : ���ڸ��� 1�ΰ�� : Ȧ�� =>
    // ��Ʈ���� ������ �ձ��� ��ȸ�ϸ鼭 
    // 1) 1 ������ 0�� ������ (01) => 10���� �ٲ���
    // 2) ��Ʈ�� ���ڷ� �ٲ���

//���2 : ���ڸ��� 0�ΰ�� : ¦�� => �� ������ 1ū��


string changeNum(long long num) { //���ڸ� ��Ʈ ���ڿ��� �ٲ���
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

long long changeStr(string strNum) { //��Ʈ ���ڿ��� ���ڷ� �ٲ���
    long long result = 0;

    for (int i = strNum.size() - 1; i >= 0; i--) {
        result += (strNum[i] -'0') * (pow(2, strNum.size() - 1 - i));
    }
    return result;
}

long long CalNum(long long num)
{
    //¦��
    if (num % 2 == 0) { 
        return num + 1; 
    }
    
    //Ȧ��
    else 
    {  
        string strNum  = changeNum(num); //���ڸ� ��Ʈ ���ڿ��� �ٲ���
        for (int i = strNum.size()-1; i>0; i--) 
        {   
            char n = strNum[i];

            if (strNum[i] == '1' && strNum[i-1] == '0' ) 
            { 
                strNum[i] = '0';
                strNum[i - 1] = '1';

                return changeStr(strNum); //��Ʈ ���ڿ��� ���ڷ� �ٲ���
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
