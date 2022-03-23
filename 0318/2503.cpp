//
// Created by 82108 on 2022-03-24.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> isPossible;
int result = 0;

//숫자야구에 등장할 수 있는 수인가?
void findPossible() {
    //false로 초기화
    for (int i = 0; i < 1000; i++) {
        isPossible.push_back(false);
    }

    string tmp;
    for (int i = 123; i < 999; i++) {
        tmp = to_string(i);
        if (tmp[0] != tmp[1] && tmp[0] != tmp[2] && tmp[1] != tmp[2]) {
            isPossible[i] = true;
        }
    }
}

//숫자 찾기
void findNum(int n, int s, int b) {
    int strikeCnt = 0;
    int ballCnt = 0;

    for (int i = 123; i < 999; i++) {
        if (isPossible[i]) {
            string minhyuk = to_string(n);
            string quiz = to_string(i);

            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (minhyuk[j] == quiz[k] && j == k) {
                        //strike
                        strikeCnt++;
                    } else if (minhyuk[j] == quiz[k] && j != k) {
                        //ball
                        ballCnt++;
                    }
                }
            }
            if (strikeCnt != s || ballCnt != b) {
                isPossible[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q; //질문 개수
    cin >> q;

    findPossible();

    int num, strike, ball;

    while (q--) {
        cin >> num >> strike >> ball;
        findNum(num, strike, ball);
    }

    for (int i = 123; i < 999; i++) {
        if (isPossible[i]) {
            result++;
        }
    }

    cout << result << "\n";

    return 0;
}

//이것도.... 힌트 주실 수 있을까요?ㅠㅠ
//정말 죄송합니다ㅠㅠㅠ