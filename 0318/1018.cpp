//
// Created by 82108 on 2022-03-24.
//

#include <iostream>
#include <vector>

using namespace std;

const int CHESS_SIZE = 64;
//체스판의 크기

//칠해야 하는 칸 수 찾기
//(0, 0)이 검정인 체스판을 기준으로 해서 계산한 값이
//32 초과일 경우 64 - (계산 결과) return
int findChange(int row, int col, vector<vector<char>> &chess) {
    int repaint = 0; //다시 칠해야 하는 칸 수
    for (int i = 0; i < 8; i++) { //row
        for (int j = 0; j < 8; j++) { //column
            if ((i + j) % 2 == 0 && chess[row + i][col + j] == 'W') {
                //row 값 + column 값이 짝수인 경우
                //검정이 칠해져야 하는데 흰색인 경우
                repaint++;
            } else if ((i + j) % 2 == 1 && chess[row + i][col + j] == 'B') {
                //row 값 + column 값이 홀수인 경우
                //흰색이 칠해져야 하는데 검정색인 경우
                repaint++;
            }
        }
    }
    if (repaint > CHESS_SIZE / 2) {
        //검정 기준이 아닌 흰색 기준으로 계산하기
        return CHESS_SIZE - repaint;
    }
    return repaint;
}

int main() {
    int N, M;
    cin >> N >> M; //N: 전체 체스판의 row, M: 전체 체스판의 column

    //현재 색칠된 모양
    vector<vector<char>> chess(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> chess[i][j];
        }
    }

    int result = CHESS_SIZE + 1; //가능한 정답 수보다 크도록 초기화
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            //findChange 함수에서 8*8 크기로 계산할 것이므로 범위를 N-8, M-8까지 잡기
            int cnt = findChange(i, j, chess);
            result = min(cnt, result); //최솟값 갱신
        }
    }
    cout << result << "\n";

    return 0;
}