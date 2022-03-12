//
// Created by 82108 on 2022-03-13.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> word_map;

bool cmp(string a, string b) {
    if (a.size() == b.size() && word_map[a] == word_map[b]) {
        //길이와 등장 횟수 모두 같은 경우
        return a < b;
    } else if (word_map[a] == word_map[b]) {
        //등장 횟수만 같은 경우
        return a.size() > b.size();
    }
    return word_map[a] > word_map[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<string> word;
    string str;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str.size() < M)  { //str의 길이가 m 이하인 경우
            continue;
        }
        if (word_map.find(str) == word_map.end()) {
            word_map[str] = 0; //첫 등장 시 횟수 초기화
            word.push_back(str); //배열에 str 추가
            //push_back()은 맨 뒤에 요소를 추가하는 함수
        }
        word_map[str]++; //횟수 증가
    }
    sort(word.begin(), word.end(), cmp);

    for (int i = 0; i < word.size(); i++) {
        cout << word[i] << '\n';
    }
}