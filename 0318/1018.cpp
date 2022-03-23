//
// Created by 82108 on 2022-03-24.
//

#include <iostream>
#include <vector>

using namespace std;

int whiteCnt = 0;
int blackCnt = 0;
vector<int> paint; //색칠할 개수 list
char chess[50][50]; //체스판
char mainColor; //맨 왼쪽 위 칸 색

void findSquare(int ii, int jj) {
    int cnt = 0; //초기화
    for (int i = ii; i < ii + 8; i++) {
        for (int j = jj; j < jj + 8; j++) {
            if (mainColor == 'W') {
                //짝수 = W, 홀수 = B
                if ((i + j) % 2 == 0 && chess[i][j] == 'B') {
                    whiteCnt++;
                } else if ((i + j) % 2 == 1 && chess[i][j] == 'W') {
                    blackCnt++;
                }
            } else if (mainColor == 'B') {
                //짝수 = B, 홀수 = W
                if ((i + j) % 2 == 0 && chess[i][j] == 'W') {
                    blackCnt++;
                } else if ((i + j) % 2 == 1 && chess[i][j] == 'B') {
                    whiteCnt++;
                }
            }
        }
    }

    cnt = whiteCnt + blackCnt;
    paint.push_back(cnt);
}

int findMin() {
    int min = 64; //최소 색칠
    for (int i = 0; i < paint.size(); i++) {
        if (paint[i] < min) {
            //최솟값 갱신
            min = paint[i];
        }
    }
    return min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    //현재 색칠된 모양
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> chess[i][j];
        }
    }

    mainColor = chess[0][0];

    //색칠할 것 찾기
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            findSquare(i, j);
        }
    }

    cout << findMin;

    return 0;
}

//이것도 코드 봐주실 수 있을까요.....?ㅠㅠ