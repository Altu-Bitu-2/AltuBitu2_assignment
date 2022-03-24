//
// Created by 82108 on 2022-03-18.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N; //미르코가 본 양수
    cin >> N;

    //N을 오름차순 정렬
    sort(N.begin(), N.end());

    //30의 배수가 되려면 10의 배수 & 3의 배수가 되어야 함
    if (N[0] != '0') {
        //10의 배수가 아닌 경우
        cout << -1;
    } else {
        long sum = 0;
        for (auto i: N) {
            //N의 각 자릿수 합 구하기
            sum += i - '0';
        }
        if (sum % 3 != 0) {
            //3의 배수가 아닌 경우
            cout << -1;
        } else {
            //30의 배수인 경우
            reverse(N.begin(), N.end());
            cout << N;
        }
    }
    return 0;
}