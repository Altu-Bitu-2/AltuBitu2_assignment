//
// Created by 82108 on 2022-03-17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 8001; //최대 범위(-4000 ~ 4000)
int num_cnt[MAX]; //최빈값 파악을 위한 배열

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> num_list; //평균, 중앙값, 범위 파악을 위해
    int num; //입력받는 숫자
    float sum = 0; //숫자들의 합

    int N; //숫자 개수
    cin >> N;

    for (int i = 0; i < N; i++) {
        //숫자들 입력받기
        cin >> num;
        sum += num; //숫자를 전체 합에 더하기
        num_list.push_back(num); //숫자 리스트에 포함
        num_cnt[num + 4000]++; //해당 숫자의 개수 증가
    }
    //숫자들 오름차순 정렬
    sort(num_list.begin(), num_list.end());
    int range = num_list[N - 1] - num_list[0]; //범위
    int median = num_list[(N - 1) / 2];; //중앙값

    int max_iter = 1;
    for (int i = 0; i < MAX; i++) {
        //최빈값 찾기
        if (num_cnt[i] > max_iter) {
            //최빈값 등장 횟수 업데이트
            max_iter = num_cnt[i];
        }
    }

    vector<int> mode_list;
    for (int i = 0; i < MAX; i++) {
        if (num_cnt[i] == max_iter) {
            //최빈값 list에 저장하기
            mode_list.push_back(i - 4000);
        }
    }
    sort(mode_list.begin(), mode_list.end());

    int mode;
    if (mode_list.size() == 1) {
        mode = mode_list[0];
    } else {
        mode = mode_list[1];
    }

    int avg = round(sum / (N * 1.0));

    cout << avg << "\n";
    cout << median << "\n";
    cout << mode << "\n";
    cout << range;

    return 0;
}

//도저히 틀린 이유를 모르겠습니다ㅠㅠ
//예제 입력에 따른 출력은 그대로 나와요.........