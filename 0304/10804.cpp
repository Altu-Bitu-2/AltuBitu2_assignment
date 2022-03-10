//
// Created by 82108 on 2022-03-08.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr; //배열을 전역변수로 선언

//역배치 함수
void reverseArray(int start, int end) {
    while (start <= end) {
        swap(arr[start++ - 1], arr[end-- - 1]);
    }
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int s, e;
    arr.assign(20, 0); //길이가 20인 배열 선언
    //배열 초기화
    for (int i = 1; i <= 20; i++) {
        arr[i - 1] = i;
    }

    //배열 역배치
    for (int i = 0; i < 10; i++) {
        cin >> s >> e;
        reverseArray(s, e);
    }

    //배열 출력
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}