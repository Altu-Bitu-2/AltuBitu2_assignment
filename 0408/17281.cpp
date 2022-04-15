//
// Created by 82108 on 2022-04-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score, player;
vector<int> entry = {0, 1, 2, 3, 4, 5, 6, 7, 8}; //선수 순서
vector<vector<int>> board; //n * 9 크기의 2차원 배열 board 선언

void running(int &run, int num) {
    run |= (1 << 0); //0번 플레이트에 타자가 진출했음을 표시
    for (int i = (4 - num); i < 4; i++) { //홈까지 진루할 수 있는 주자들의 수만큼 반복
        if (run & (1 << i)) { //주자가 남아있다면
            run &= ~(1 << i); //주자가 홈에 들어왔기 때문에 플레이트를 비워줌
            score++; //주자가 들어왔으므로 점수 증가
        }
    }
    run = run << num; //진루한 만큼 주자들 이동
}

//각 이닝 별 경기
void playGame(int idx) { //idx번째 이닝
    int out = 0, run = 0; //out: 아웃 개수, run: 진루 상태
    while (out != 3) { //3아웃 되기 전까지 반복
        int hit = board[idx][entry[player]]; //이번 주자의 결과를 board에서 확인
        if (!hit) {
            //아웃일 경우
            out++; //out 개수 증가
        }
        else {
            //1루타, 2루타, 3루타, 홈런의 경우
            running(run, hit);
        }
        //다음 선수로 교체
        player = (player + 1) % 9;
    }
}

int main() {
    int n, ans = 0; //n: 이닝 수, ans: 아인타 팀이 얻게 되는 최대 점수
    cin >> n; //n 입력 받기

    board.assign(n, vector<int>(9)); //board 초기화
    for (int i = 0; i < n; i++) { //n번 반복
        for (int j = 0; j < 9; j++) { //9번 반복
            cin >> board[i][j]; //board[i][j]에 각 이닝 별 선수들의 점수 저장
        }
    }

    do {
        swap(entry[0], entry[3]); //1번 선수가 4번 타자가 되도록 위치 변경
        score = player = 0; //score과 player 초기화
        for (int i = 0; i < n; i++) { //n번 반복
            playGame(i); //각 이닝 별 경기 진행
        }
        ans = max(ans, score); //ans와 score 값 중 더 큰 값을 ans에 저장
        swap(entry[3], entry[0]); //1번 선수를 다시 원래 자리로 복구
    } while (next_permutation(entry.begin() + 1, entry.end())); //1번 선수를 제외한 나머지 선수들을 순열로 돌리기

    cout << ans; //ans 출력

   return 0;
}