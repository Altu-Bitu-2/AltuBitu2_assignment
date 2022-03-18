//
// Created by 82108 on 2022-03-17.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> str_stack;

int solveProblem(string str) {
    int result = 0;
    int temp = 1;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            temp *= 2;
            str_stack.push('(');
        } else if (str[i] == '[') {
            temp *= 3;
            str_stack.push('[');
        } else if (str[i] == ')') {
            if (str_stack.empty() || str_stack.top() != '(') {
                //잘못된 문자열
                result = 0;
                break;
            }
            if (str[i - 1] == '(') {
                //()의 경우
                result += temp;
                temp /= 2;
                str_stack.pop();
            } else {
                //(...)의 경우
                temp /= 2;
                str_stack.pop();
            }
        } else if (str[i] == ']') {
            if (str_stack.empty() || str_stack.top() != '[') {
                //잘못된 문자열
                result = 0;
                break;
            }
            if (str[i - 1] == '[') {
                //[]의 경우
                result += temp;
                temp /= 3;
                str_stack.pop();
            } else {
                //[...]의 경우
                temp /= 3;
                str_stack.pop();
            }
        }
    }

    if (!str_stack.empty()) {
        //아직도 stack에 뭔가 남았을 때
        result = 0;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string ss; //문자열 입력받기
    cin >> ss;

    int nn = solveProblem(ss);

    cout << nn << "\n";

    return 0;
}