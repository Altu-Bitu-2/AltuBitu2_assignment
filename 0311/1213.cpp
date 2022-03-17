//
// Created by 82108 on 2022-03-16.
//

#include <iostream>
#include <string>

using namespace std;
const int ALPHABET_CNT = 26; //알파벳 총 개수
int alphabet[ALPHABET_CNT];

bool isImpossible() {
    //palindrome 만드는 게 불가능한지?
    // (홀수 번 등장하는 알파벳이 2개 이상이면 불가)
    int cnt = 0;
    for (int i = 0; i < ALPHABET_CNT; i++) {
        if (alphabet[i] % 2 == 1) {
            cnt++;
        }
    }
    return cnt >= 2; //cnt가 2 이상이면 impossible
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string eng_name;
    cin >> eng_name; //영어 이름 입력 받기

    for (int i = 0; i < eng_name.length(); i++) {
        //한수의 영어 이름에 들어간 알파벳이 등장했을 때,
        //해당 인덱스의 값 증가
        alphabet[eng_name[i] - 'A']++;
    }

    if (isImpossible()) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    string palindrome;

    //수정본
    //palindrome의 앞부분
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alphabet[i] / 2; j++) {
            //alphabet이 포함된 개수의 절반만큼 반복
            palindrome += i + 'A';
        }
    }
    //palindrome의 가운데
    if (eng_name.length() % 2 == 1) {
        //이름의 길이가 홀수일 때만 수행
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] % 2 == 1) {
                palindrome += i + 'A';
            }
        }
    }
    //palindrome의 뒷부분
    for (int i = 25; i >= 0; i--)
        for (int j = 0; j < alphabet[i] / 2; j++)
            palindrome += i + 'A';

    cout << palindrome << "\n";

    return 0;
}