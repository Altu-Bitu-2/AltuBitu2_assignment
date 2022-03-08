//
// Created by 82108 on 2022-03-09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
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

    int maxValue;
    int sum = 0;
    int tmp = 100; //원소가 될 수 있는 최댓값보다 큼

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
    }

    cout << sum;

    return 0;
}

//입력에 따른 결과는 잘 나오는데, 백준에서 "틀렸습니다"라고 합니다ㅠㅠ