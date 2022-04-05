//
// Created by 82108 on 2022-04-05.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lisFinal(int n, vector<int> &arr) { //수열의 크기 n과 배열을 input으로 갖는 함수 lisFinal()
    vector<int> dp; //부분 수열의 길이를 구하기 위한 배열 dp 선언

    for (int i = 0; i < n; i++) { //n번 반복
        //lower_bound는 key 값 이상의 값이 몇 번 인덱스에 처음 나오는지를 알기 위한 용도
        //여기서의 key는 arr[i]이고, 탐색 범위는 dp의 시작부터 끝까지
        //인덱스 번호를 알기 위해 lower_bound() 수행 후 dp.begin()의 값을 뺌
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (pos == dp.size()) { //arr[i]가 존재하는 위치인 pos가 dp의 크기와 같다면
            //dp에 새로운 요소를 추가해야 할 경우 실행되는 코드
            dp.push_back(arr[i]); //dp에 arr[i] 삽입 & dp 크기 증가
        }
        //dp의 pos번 인덱스의 값을 arr[i]로 갱신
        dp[pos] = arr[i];
    }
    return dp.size(); //dp의 크기 return
}

int main() {
    int n; //수열의 크기

    //입력
    cin >> n; //n 입력받기
    vector<int> arr(n, 0); //크기가 n인 배열 선언 & 값을 0으로 초기화
    for (int i = 0; i < n; i++) { //n번 반복하며
        cin >> arr[i]; //배열 arr의 요소 삽입
    }

    //연산 & 출력
    cout << lisFinal(n, arr); //lisFinal 수행 후 출력
    return 0;
}