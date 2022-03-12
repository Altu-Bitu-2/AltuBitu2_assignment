//
// Created by 82108 on 2022-03-12.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N; //파일 개수 N

    string str; //파일 이름
    map<string, int> str_map; //확장자 이름과 개수를 mapping
    //string은 key, int는 value

    for(int i = 0; i < N; i++) {
        cin >> str;
        str = str.substr(str.find('.') +1); //. 이후부터의 부분 문자열
        //파일 이름을 key로 하여 value에 접근해 파일 이름을 찾을 때마다 value 하나씩 증가
        str_map[str]++;
    }

    for(auto iter:str_map) {
        //map을 돌며 확장자 이름과 횟수 출력
        cout << iter.first << " " << iter.second << "\n";
    }
}