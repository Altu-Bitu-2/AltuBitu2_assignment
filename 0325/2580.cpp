//
// Created by 82108 on 2022-03-30.
//

#include <iostream>

using namespace std;

const int MAX = 9;

int sudoku[MAX][MAX];
bool Row[MAX][MAX + 1]; //row 체크 [row 번호][숫자]
bool Col[MAX][MAX + 1]; //column 체크 [column 번호][숫자]
bool Square[MAX][MAX + 1]; //square 체크 [정사각형의 상대적 위치][숫자]

bool findAnswer(int fill) {
    if (fill == 81) { //81 = 9 * 9
        return true;
    }

    int r = fill / MAX; //row 위치
    int c = fill % MAX; //column 위치

    if (sudoku[r][c]) {
        return findAnswer(fill + 1);
    }

    for (int i = 1; i <= MAX; i++) {
        if (!Row[r][i] && !Col[c][i] && !Square[(r / 3) * 3 + (c / 3)][i]) {
            Row[r][i] = Col[c][i] = Square[(r / 3) * 3 + (c / 3)][i] = true;
            sudoku[r][c] = i;

            if(findAnswer(fill+1)) {
                return true;
            }

            //리셋
            Row[r][i] = Col[c][i] = Square[(r / 3) * 3 + (c / 3)][i] = false;
            sudoku[r][c] = 0;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력 받기
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] != 0) {
                //이미 채워진 숫자라면
                Row[i][sudoku[i][j]] = true;
                Col[j][sudoku[i][j]] = true;
                Square[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true;
            }
        }
    }

    //문제 풀기
    findAnswer(0);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}