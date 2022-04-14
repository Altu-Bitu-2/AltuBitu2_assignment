//
// Created by 82108 on 2022-04-10.
//

#include <iostream>
#include <vector>

using namespace std;

void changeMatrix(int row, int col, vector<string> &mat_a) {
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (mat_a[i][j] == '1') {
                mat_a[i][j] = '0';
            } else {
                mat_a[i][j] = '1';
            }
        }
    }
}

bool isPossible(int n, int m, vector<string> &mat_a, vector<string> &mat_b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat_a[i][j] != mat_b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; //N: 행렬의 row 개수, M: 행렬의 column 개수
    cin >> N >> M;

    vector<string> a(N); //0과 1을 그 자체로 입력 받기 위해 string으로 설정
    vector<string> b(N);

    for (int i = 0; i < N; i++) { //행렬 A 채우기
        cin >> a[i]; //cin은 공백을 기준으로 입력 받음
    }

    for (int i = 0; i < N; i++) { //행렬 B 채우기
        cin >> b[i];
    }

    int change = 0; //최소 변환 횟수 저장
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (a[i][j] != b[i][j]) { //변환이 필요한 경우
                changeMatrix(i, j, a);
                change++;
            }
        }
    }

    if (!isPossible(N, M, a, b)) {
        change = -1;
    }
    cout << change;

    return 0;
}