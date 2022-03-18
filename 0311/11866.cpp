//
// Created by 82108 on 2022-03-17.
//

#include <iostream>
#include <queue>

using namespace std;

queue<int> josephus;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        //사람들 번호대로 집어넣기
        josephus.push(i);
    }

    cout << "<";
    while (!josephus.empty()) {
        //josephus가 빌 때까지 반복
        for (int i = 0; i < K - 1; i++) {
            //k-1번만큼 제일 앞에 있는 것을 꺼내 맨 뒤에 집어넣기
            josephus.push(josephus.front());
            josephus.pop();
        }
        //k번째 숫자 출력 후 꺼내기
        cout << josephus.front();
        josephus.pop();
        if (!josephus.empty()) {
            //아직 큐가 비지 않았다면
            cout << ", ";
        }
    }
    cout << ">" << "\n";

    return 0;
}