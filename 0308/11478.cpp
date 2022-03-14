//
// Created by 82108 on 2022-03-12.
//

#include <iostream>
#include <set>

using namespace std;

set<string> s_set;

string subStr(string str) {
    string ss = ""; //빈 문자열

    for (int i = 0; i < str.size(); i++) { //앞에서부터 차례대로 부분 문자열 파악
        for (int j = i; j < str.size(); j++) {
            //빈 문자열에 덧붙이기
            ss += str[j];

            //set에 생성된 부분 문자열 ss 삽입
            //set이기 때문에 중복 삽입되지 않음
            s_set.insert(ss);
        }
        ss = ""; //부분 문자열 reset
    }
    return str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s; //전체 문자열 입력 받기

    subStr(s);

    cout << s_set.size();

    return 0;
}

//메모리를 엄청 사용하네요.......