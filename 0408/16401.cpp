//
// Created by 82108 on 2022-04-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int childNum(int len, vector<int> &snacks) {
    int cnt = 0; //나눠줄 수 있는 조카 수를 0으로 초기화

    for (int i = snacks.size() - 1; i >= 0; i--) { //과자 수만큼 반복
        if (snacks[i] < len) {
            //나눠주려는 길이보다 과자의 길이가 짧은 경우
            break; //반복 종료
        }
        //과자를 나눠줄 수 있는 경우
        //(현재 과자의 길이 / 나눠주려는 길이)의 몫만큼을 cnt에 더하기
        cnt += (snacks[i] / len);
    }

    return cnt;
}

int upperSearch(int left, int right, int target, vector<int> &snacks) {
    while (left <= right) {
        int mid = (left + right) / 2; //left와 right의 평균을 mid로 초기화

        //과자 길이가 mid일 때 몇 명에게 과자를 줄 수 있는지를 계산해 이를 cnt에 저장
        int cnt = childNum(mid, snacks);

        if (cnt >= target) {
            //실제 조카 수보다 더 많이 나눠줄 수 있는 경우
            left = mid + 1; //과자 길이 늘리기
        } else {
            //조카들에게 모두 나눠주지 못하는 경우
            right = mid - 1; //과자 길이 줄이기
        }
    }

    //cnt = target인 경우에도 left가 mid + 1이 되므로
    //left 값에 다시 1을 뺀 후 return
    return left - 1;
}

int main() {
    int m, n; //m: 조카 수, n: 과자 수
    cin >> m >> n; //m과 n 입력 받기

    vector<int> snacks(n, 0); //n개의 과자들 길이를 저장하는 배열 snacks 선언
    for (int i = 0; i < n; i++) { //n번 반복
        cin >> snacks[i]; //과자 길이 저장
    }

    sort(snacks.begin(), snacks.end()); //과자 길이 오름차순으로 정렬

    int left = 1, right = snacks[n - 1]; //right: 가장 긴 과자의 길이

    //left, right를 input으로 해
    //upperSearch() 수행 후 그 결과를 출력
    cout << upperSearch(left, right, m, snacks);

    return 0;
}