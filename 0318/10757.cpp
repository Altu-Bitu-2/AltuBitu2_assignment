//
// Created by 82108 on 2022-03-23.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A_num;
vector<int> B_num;

void pushNum(vector<int> arr, string str) {
    for (int i = 0; i < str.length(); i++) {
        arr.push_back(str[i] - '0');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    cin >> A >> B;
    //입력받은 문자열 뒤집기
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    if (A.length() < B.length()) {
        //더 긴 숫자를 A로 정하기
        string tmp = A;
        A = B;
        B = tmp;
    }

    //A와 B를 int 배열에 저장
    //거꾸로 저장됨
    pushNum(A_num, A);
    pushNum(B_num, B);

    //A+B 수행
    vector<int> result;
    int carry = 0; //받아올림 고려
    int sum;
    for (int i = 0; i < B.length(); i++) {
        sum = A_num[i] + B_num[i] + carry;
        result[i] = sum % 10;
        carry = 0; //carry 초기화
        if (sum >= 10) {
            //합이 10보다 클 경우(받아올림 필요)
            carry = 1;
        }
    }

    for (int i = B.length(); i < A.length(); i++) {
        //A가 아직 남아있을 경우
        result[i] = A_num[i] + carry;
        if (carry == 1) {
            //carry 초기화
            carry = 0;
        }
    }

    //다시 뒤집기
    reverse(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << "\n";

    return 0;
}

//잘못된 부분을 모르겠습니다..
//힌트 주실 수 있을까요?ㅠㅠ