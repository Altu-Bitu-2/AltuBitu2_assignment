//
// Created by 82108 on 2022-04-15.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //칭호의 전투력 상한값과 해당 칭호를 저장하는 map인 title 선언
    //전투력이 key
    map<int, string> title;

    int n, m, power; //n: 칭호의 개수, m: 캐릭터 개수, power: 전투력 상한값
    string name; //name: 칭호

    cin >> n >> m; //n과 m 입력받기

    while (n--) { //n번 반복
        cin >> name >> power; //칭호의 이름과 해당 칭호의 전투력 상한값 입력받기
        if (title[power].empty()) {
            //power에 해당하는 칭호가 존재하지 않는 경우
            title[power] = name; //칭호 저장하기
        }
    }

    while (m--) { //m번 반복
        cin >> power; //전투력을 입력 받아
        //입력받은 전투력 이상의 값이 처음 존재하는 곳을 찾아
        //해당 위치의 칭호를 출력
       cout << title.lower_bound(power)->second << '\n';
    }
}