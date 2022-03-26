//
// Created by 82108 on 2022-03-27.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int groupCnt = 0; //그룹 단어 개수
vector<bool> alphabet; //알파벳 등장 여부를 나타내는 배열 선언
//a: 0번 인덱스 ~ z: 25번 인덱스

void isGroupWord(string ss) {
    bool isGroup = true; //그룹단어인지를 판단

    alphabet.assign(26, false); //false로 초기화
    alphabet[(int) (ss[0]) - 97] = true; //첫번째 문자 true로 바꾸기

    for (int i = 1; i < ss.length(); i++) {
        if (ss[i] == ss[i - 1]) {
            //이전에 등장한 문자와 동일하면
            continue;
        } else if (ss[i] != ss[i - 1] && !alphabet[(int) (ss[i]) - 97]) {
            //처음 등장하는 문자라면
            alphabet[(int) (ss[i]) - 97] = true;
            continue;
        } else if(ss[i] != ss[i-1] && alphabet[(int) (ss[i]) - 97]) {
            //기존에 등장했던 문자가 재등장했다면
            isGroup = false;
        }
    }
    if(isGroup) {
        //그룹단어라면
        groupCnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; //단어의 개수
    cin >> N;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        isGroupWord(str);
    }

    cout << groupCnt;

    return 0;
}