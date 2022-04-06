//
// Created by 82108 on 2022-03-30.
//

#include <iostream>
#include <deque>

using namespace std;

int N; //컨베이어 벨트의 길이 (전체 벨트 길이는 2N)
int K; //내구도가 0인 칸의 개수가 K개 이상이면 종료
int stage = 0; //진행 중인 단계
deque<bool> isRobotThere; //로봇의 존재 여부 판단
deque<int> belt; //벨트의 내구도 저장

int findZero() {
    int zeroCnt = 0; //내구도 0인 칸의 개수

    for (int i = 0; i < 2 * N; i++) {
        if (belt[i] == 0) {
            zeroCnt++;
        }
    }
    return zeroCnt;
}


void moveRobot() {
    for (int i = N - 2; i >= 0; i--) {
        if (isRobotThere[i] == true && isRobotThere[i + 1] == false && belt[i + 1] > 0) {
            //i 위치에 로봇이 존재하고 i+1 위치에 로봇이 없고
            //i+1 위치의 벨트 내구도가 0이 아니면

            //로봇 옮기기
            belt[i + 1]--;
            isRobotThere[i] = false;
            if (i == N - 2) {
                //로봇이 내리는 위치로 이동한 것이라면
                continue;
            }
            //내리는 위치가 아닌 곳으로 이동한 것이라면
            isRobotThere[i + 1] = true;
        }
    }

    if (belt[0] > 0 && isRobotThere[0] == false) {
        //시작 위치의 내구도가 0이 아니면 로봇 올리기
        isRobotThere[0] = true;
        belt[0]--;
    }
}

void rotate() {
    //컨베이어 벨트 & 로봇 회전
    while (findZero() < K) {
        //컨베이어 벨트 회전
        belt.push_front(belt.back());
        belt.pop_back();

        //로봇 회전
        isRobotThere.push_front(isRobotThere.back());
        isRobotThere.pop_back();

        if (isRobotThere[N - 1] == true) {
            //로봇이 내리는 위치에 왔다면 로봇 내리기
            isRobotThere[N - 1] = false;
        }

        moveRobot();
        stage++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int power;
    for (int i = 0; i < 2 * N; i++) {
        cin >> power;
        belt.push_back(power); //내구도 저장
        isRobotThere.push_back(false);
    }
    rotate();

    cout << stage;

    return 0;
}