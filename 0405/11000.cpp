//
// Created by 82108 on 2022-04-10.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> ts; //수업 시작 시간 & 종료 시간을 저장하는 pair
priority_queue<int, vector<int>, greater<>> pq; //최소 힙 pq 선언

int findMin(int n) { //n: 수업 개수
    pq.push(ts[0].first); //가장 빨리 끝나는 수업의 종료 시간을 pq에 삽입

    for (int i = 1; i < n; i++) {
        if (ts[i].second < pq.top()) {
            //i번째 수업의 시작 시간이 현재 pq의 top보다 빠르다면
            //같은 강의실 사용 불가 >> 강의실 추가하기
            pq.push(ts[i].first);
        }
    }

    return pq.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; //N: 수업 개수
    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, t; //s: 시작 시간, t: 종료 시간
        cin >> s >> t;

        ts.push_back(make_pair(t, s));
    }
    sort(ts.begin(), ts.end()); //종료 시간이 빠른 순으로 정렬

    cout << findMin(N);

    return 0;
}

//이것도 코드 봐주실 수 있을까요ㅠㅠ
//주어진 예제 입력이랑 제가 임의로 몇개 더 넣어봤는데도 잘 나오는데
//백준에서는 틀렸다고 나오네요ㅠㅠㅠ