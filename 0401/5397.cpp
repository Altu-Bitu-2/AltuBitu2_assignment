//
// Created by 82108 on 2022-04-08.
//

#include <iostream>
#include <deque>

using namespace std;

string dqToString(deque<char> &dq) { //string을 return하는 dqToString() 함수
    string ans = ""; //빈 문자열 ans
    while (!dq.empty()) { //dq가 빌 때까지 반복
        ans += dq.front(); //dq의 앞에서부터 ans에 저장
        dq.pop_front(); //ans에 저장한 내용을 dq에서 삭제
    }
    return ans; //완성된 문자열 ans를 return
}

string findPass(string s) { //string을 return하는 findPass() 함수
    deque<char> dq_left;  //현재 커서의 앞 내용을 저장
    deque<char> dq_right; //현재 커서의 뒷 내용을 저장

    for (int i = 0; i < s.length(); i++) { //s의 길이만큼 반복
        switch (s[i]) { //s의 i번째 문자에 따라 case 결정
            case '-':
                //강산이가 backspace를 입력했다면
                //현재 커서 앞에 있는 글자를 지우기
                if (!dq_left.empty()) { //현재 커서 앞에 내용이 존재한다면
                    dq_left.pop_back(); //커서 바로 앞에 있는 글자 지우기
                }
                break;
            case '<':
                //강산이가 커서를 왼쪽으로 이동시켰다면
                if (!dq_left.empty()) { //현재 커서 앞에 내용이 존재한다면
                    dq_right.push_front(dq_left.back()); //dq_left의 맨 뒤 요소를 dq_right의 맨 앞에 삽입
                    dq_left.pop_back(); //dq_left의 맨 뒤 요소 삭제
                }
                break;
            case '>':
                //강산이가 커서를 오른쪽으로 이동시켰다면
                if (!dq_right.empty()) { //현재 커서 뒤에 내용이 존재한다면
                    dq_left.push_back(dq_right.front()); //dq_right의 맨 앞 요소를 dq_left의 맨 뒤에 삽입
                    dq_right.pop_front(); //dq_right의 맨 앞 요소 삭제
                }
                break;
            default:
                //강산이가 문자를 입력했다면
                dq_left.push_back(s[i]); //해당 문자를 dq_left의 맨 뒤에 삽입
                break;
        }
    }

    string pass = dqToString(dq_left); //커서 앞에 존재하는 모든 문자들을 비밀번호로 저장
    pass += dqToString(dq_right); //커서 뒤에 존재하는 모든 문자들을 비밀번호에 덧붙이기
    return pass; //비밀번호 return
}

int main() {
    int t; //테스트 케이스 개수
    string s; //길이가 L인 문자열

    cin >> t; //t 입력받기
    while (t--) { //t번 반복
        cin >> s; //s 입력 받기

        //findPass(s) 계산 후 그 결과를 출력
        cout << findPass(s) << '\n';
    }
    return 0;
}