//
// Created by 82108 on 2022-03-24.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> numList;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; //N은 카드 개수, M은 기준
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        //숫자 저장
        int tmp;
        cin >> tmp;
        numList.push_back(tmp);
    }

    int sum;
    int result = 0;

    for (int i = 0; i < numList.size() - 2; i++) {
        for (int j = i + 1; j < numList.size() - 1; j++) {
            for (int k = j + 1; k < numList.size(); k++) {
                sum = numList[i] + numList[j] + numList[k];
                if (sum > result && sum <= M) {
                    result = sum;
                }
            }
        }
    }

    cout << result << "\n";

    return 0;
}