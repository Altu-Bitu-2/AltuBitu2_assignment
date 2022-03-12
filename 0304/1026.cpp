//
// Created by 82108 on 2022-03-09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    //배열 생성
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    //A를 오름차순 정렬
    sort(A.begin(), A.end());
    //B를 내림차순 정렬 (내림차순 정렬 안 하고 해보려 했는데 안 됨ㅠㅠ)
    sort(B.begin(), B.end(), greater<>());

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (A[i] * B[i]);
    }
    cout << sum;

    return 0;
}

/*
    int tmp = 100; //원소가 될 수 있는 최댓값

    //B 배열 순회
    for (int i = 0; i < N; i++) {
        maxValue = 0;
        for(int j=0; j < N; j++) {
            if(B[j] < tmp) {
                maxValue = max(maxValue, B[j]);
            }
        }
        sum+= maxValue * A[i];
        tmp = maxValue;
    } */