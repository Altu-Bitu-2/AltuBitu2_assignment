//
// Created by 82108 on 2022-03-24.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> yeongsu; //영수가 답한 스트라이크, 볼 개수

struct baseball {
    string num; //민혁이가 말한 3자리 수 (1~9로 구성된, 서로 다른 숫자로 구성된)
    int strike, ball;
};

yeongsu cntStrikeBall(string &s1, string &s2) {
    //민혁이가 말한 수와 정답 사이의 strike 개수, ball 개수 비교
    int strikeCnt = 0;
    int ballCnt = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (s1[i] == s2[j] && i == j) {
                //스트라이크일 경우
                strikeCnt++;
            } else if (s1[i] == s2[j] && i != j) {
                ballCnt++;
            }
        }
    }
    return yeongsu(strikeCnt, ballCnt);
}

int game(int n, vector<baseball> &minhyuk) {
    int possible = 0; //정답으로 가능한 개수

    for (int i = 123; i <= 987; i++) {
        bool check = true;
        string s1 = to_string(i); //123~987까지의 수를 string으로 전환

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') {
            //0이 하나라도 존재한다면 (존재해서는 안 됨)
            continue;
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) {
            //서로 다른 숫자로 구성되어 있지 않다면
            continue;
        }

        for (int j = 0; j < n; j++) {
            string s2 = minhyuk[j].num; //민혁이가 질문한 수
            yeongsu cnt = cntStrikeBall(s1, s2);  //s1과 s2의 strike와 ball 개수
            if (cnt.first != minhyuk[j].strike || cnt.second != minhyuk[j].ball) {
                //민혁이의 strike/ball 개수와 정답 기준 strike/ball 개수가 다르다면
                check = false;
                break;
            }
        }
        if (check) {
            possible++;
        }
    }
    return possible;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q; //질문 개수
    cin >> q;

    vector<baseball> minhyuk(q);
    for (int i = 0; i < q; i++) {
        cin >> minhyuk[i].num >> minhyuk[i].strike >> minhyuk[i].ball;
    }
    cout << game(q, minhyuk);

    return 0;
}