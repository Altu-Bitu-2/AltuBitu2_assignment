//
// Created by 82108 on 2022-04-10.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[50][50]; //행렬 A
int B[50][50]; //행렬 B

void changeMatrix(int ii, int jj) {
    for (int i = ii - 1; i <= ii + 1; i++) {
        for (int j = jj - 1; j <= jj + 1; j++) {
            A[i][j] = 1 - A[i][j];
        }
    }
}

bool isPossible(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
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

    for (int i = 0; i < N; i++) { //행렬 A 채우기
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++) { //행렬 B 채우기
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
        }
    }

    int change = 0; //최소 변환 횟수 저장
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (A[i][j] != B[i][j]) { //변환이 필요한 경우
                change++;
                changeMatrix(i + 1, j + 1);
            }
        }
    }

    bool possible = isPossible(N, M);
    if (!possible) {
        cout << -1;
    } else {
        cout << change;
    }

    return 0;
}

// 계속 코드가 실행이 안 되는데...
// 혹시 코드에서 오류 찾아주실 수 있을까요?