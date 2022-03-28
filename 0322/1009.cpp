//
// Created by 82108 on 2022-03-26.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> findNum(int aa) {
    vector<int> numA; //패턴을 저장할 배열 선언

    int first = aa; //첫 데이터가 처리되는 컴퓨터 번호
    numA.push_back(first);

    int temp = first;
    while (first != (temp * first) % 10) {
        temp = (temp * first) % 10;
        numA.push_back(temp);
    }

    return numA;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; //테스트 케이스 개수
    cin >> T;

    int a, b; //데이터의 개수는 항상 a^b개
    vector<int> arr;
    while (T--) {
        cin >> a >> b;
        arr = findNum(a);
        cout << arr[(b - 1) % arr.size()] << "\n";
    }

    return 0;
}