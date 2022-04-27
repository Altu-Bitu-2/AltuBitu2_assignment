//
// Created by 82108 on 2022-04-15.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci; //int와 char의 pair를 ci로 선언

string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
    string ans = ""; //바퀴에 적힌 문자들을 문자열로 표현하기 위한 ans 선언
    int start = arrow_point; //넘겨받은 마지막 idx를 start로 함
    do {
        ans += wheel[arrow_point]; //현재 화살표가 가리키는 문자부터 ans에 추가
        arrow_point = (arrow_point + 1) % n; //화살표 한 칸씩 옆으로 넘기기
    } while (arrow_point != start); //화살표가 다시 처음 자리로 돌아오면 멈추도록

    //바퀴에 적힌 전체 문자열 return
    return ans;
}

string makeWheel(int n, vector<ci> &record) {
    //크기가 n인 배열 wheel의 요소들을 모두 ?로 초기화
    vector<char> wheel(n, '?');
    //알파벳의 중복 여부를 확인하는 배열 is_available 선언
    //문제에서 글자는 중복되지 않는다고 함
    vector<bool> is_available(26, false);

    int idx = 0; //화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) { //record의 크기만큼 반복
        int rot = record[i].first; //record에 적힌 글자 변경 횟수를 rot에 저장
        char alpha = record[i].second; //record에 적힌 현재 글자를 alpha에 저장

        idx = (idx - rot % n + n) % n; //화살표 위치 변경

        if (wheel[idx] == alpha) {
            //idx가 가리키는 곳에 이미 적힌 문자가 alpha와 같다면
            continue; //다음 반복으로
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) {
            //idx가 가리키는 곳에 이미 alpha와 다른 문자가 적혀 있거나
            //alpha가 이미 다른 곳에 적힌 문자라면
            return "!"; //존재할 수 없는 바퀴이므로 ! return
        }
        //위의 어느 경우도 해당하지 않는 경우 (= idx 위치가 비어있고 alpha도 적힐 수 있는 경우)
        wheel[idx] = alpha; //idx 위치에 alpha 적고
        is_available[alpha - 'A'] = true; //alpha 사용했다고 체크하기
    }
    //현재 idx를 input으로 해
    //arrowStartWheel() 수행 후 그 결과를 return
    return arrowStartWheel(idx, n, wheel);
}

int main() {
    int n, k; //n: 바퀴 칸 수, k: 바퀴 돌리는 횟수
    cin >> n >> k; //n과 k 입력받기

    //바퀴 회전 시, 글자가 바뀐 횟수와 멈춘 글자를 저장하는 배열 record 선언
    vector<ci> record(k, {0, 0});
    for (int i = 0; i < k; i++) { //k번 반복
        //record에 글자가 바뀐 횟수(int)와 멈춘 글자(char) 저장
        cin >> record[i].first >> record[i].second;
    }

    //makeWheel() 수행 후 그 결과를 출력
    cout << makeWheel(n, record);
    return 0;
}