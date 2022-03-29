//
// Created by 82108 on 2022-03-30.
//

#include <iostream>
#include <vector>

using namespace std;

int N; //수의 개수
vector<int> numList; //숫자들
vector<int> calcList; //연산자 개수
int MIN = 1e9 + 1;
int MAX = -1e9 - 1;

void calc(int result, int num) {
    if (num == N) {
        //사용된 숫자 개수가 N과 같다면
        MIN = min(result, MIN);
        MAX = max(result, MAX);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (calcList[i] > 0) {
            //해당 연산자가 존재한다면
            calcList[i]--; //사용하기
            if (i == 0) {
                // + 연산자
                calc(result + numList[num], num + 1);
            } else if (i == 1) {
                // - 연산자
                calc(result - numList[num], num + 1);
            } else if (i == 2) {
                // * 연산자
                calc(result * numList[num], num + 1);
            } else {
                // / 연산자
                calc(result / numList[num], num + 1);
            }
            //연산자 개수 리셋
            calcList[i]++;
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        //숫자들 입력받기
        int x;
        cin >> x;
        numList.push_back(x);
    }
    for (int i = 0; i < 4; i++) {
        //연산자 개수 입력받기
        int y;
        cin >> y;
        calcList.push_back(y);
    }

    //처음 등장하는 두 수를 이용해 연산 시작
    calc(numList[0], 1);

    cout << MAX << "\n" << MIN;

    return 0;
}