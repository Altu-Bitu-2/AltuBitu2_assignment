//
// Created by 82108 on 2022-03-29.
//

#include <iostream>
#include <vector>

using namespace std;

int N; //현재 리스트에 존재하는 점수들의 개수
int taesu; //태수의 새로운 점수
int P; //랭킹에 오를 수 있는 최대 개수
vector<int> scoreList; //기존 점수들 리스트

int rankingCheck() {
    int rank = 1; //최고 등수

    if (N == P && scoreList[N - 1] >= taesu) {
        //랭킹이 이미 가득 찼는데 꼴찌 점수가 taesu 이상이면
        rank = -1;
        return rank;
    } else {
        for (int i = 0; i < N; i++) {
            if (scoreList[i] <= taesu) {
                //기존 랭킹의 점수가 taesu 이하라면
                break;
            }
            rank++;
        }
        return rank;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> taesu >> P;

    for (int i = 0; i < N; i++) {
        //점수들 입력받기
        int score;
        cin >> score;
        scoreList.push_back(score);
    }

    cout << rankingCheck();

    return 0;
}