//
// Created by 82108 on 2022-03-26.
//

#include <iostream>
#include <algorithm>

using namespace std;

int findLast(int aa, int bb) {
    int last = 1; //마지막 데이터가 처리되는 컴퓨터 번호

    for (int i = 0; i < bb; i++) {
        //aa의 bb제곱 구하기 ex) aa = 2, bb = 3이라면 temp가 8이 되도록
        last = (last * aa) % 10;
    }
    //1, 5, 6 등은 1개의 숫자가 계속 반복되는 걸 알긴 하는데
    //배열에 특정 요소가 존재하는지 판단하는 방법을 모르겠어서...ㅠㅠ
    //우선 이렇게 둡니다....!!

    if (last == 0) {
        //1의 자리가 0이라면 10번 컴퓨터가 처리함
        last = 10;
    }

    return last;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; //테스트 케이스 개수
    cin >> T;

    int a, b; //데이터의 개수는 항상 a^b개
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        cout << findLast(a, b) << "\n";
    }

    return 0;
}