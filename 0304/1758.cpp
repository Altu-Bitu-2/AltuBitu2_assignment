//
// Created by 82108 on 2022-03-08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; //손님 수
    cin >> N;

    vector<int> guest(N);

    for (int i = 0; i < N; i++) {
        cin >> guest[i]; //손님들의 팁을 배열에 넣기
    }
    //내림차순 정렬
    sort(guest.begin(), guest.end(), greater<>());

    long tip = 0; //팁의 범위는 1 이상 10만 미만인 자연수

    for (int i = 0; i < N; i++) {
        long money = guest[i] - i;
        if(money <= 0) {
            break;
        }
        tip += money;
    }

    cout << tip << "\n";

    return 0;
}