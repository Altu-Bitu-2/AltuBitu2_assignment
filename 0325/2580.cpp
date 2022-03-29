//
// Created by 82108 on 2022-03-30.
//

#include <iostream>

using namespace std;

int sudoku[9][9];
bool Row[9][9]; //row 체크 [row 번호][숫자]
bool Col[9][9]; //column 체크 [column 번호][숫자]
bool Square[9][9]; //square 체크 [정사각형의 상대적 위치][숫자]

void findAnswer(int fill) {
    int r = fill / 9; //row 위치
    int c = fill % 9; //column 위치

    if (fill == 81) {
        //출력하기
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        //exit(0);
    }

    if (sudoku[r][c] == 0) {
        for (int i = 0; i < 9; i++) {
            if (Row[r][i + 1] == false && Col[c][i + 1] == false && Square[(r / 3) * 3 + (c / 3)][i + 1] == false) {
                Row[r][i + 1] = true;
                Col[c][i + 1] = true;
                Square[(r / 3) * 3 + (c / 3)][i + 1] = true;
                sudoku[r][c] = i + 1;

                findAnswer(fill + 1);

                //리셋
                Row[r][i + 1] = false;
                Col[c][i + 1] = false;
                Square[(r / 3) * 3 + (c / 3)][i + 1] = false;
                sudoku[r][c] = 0;
            }
        }
    } else {
        findAnswer(fill + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력 받기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
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

    return 0;
}