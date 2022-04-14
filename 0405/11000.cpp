//
// Created by 82108 on 2022-04-10.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> st; //시작 시간 & 종료 시간

int findMin(int n, vector<st> lec) { //n: 수업 개수
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙 pq 선언

    pq.push(-1);

    for(int i= 0; i<n; i++) {
        if (lec[i].first >= pq.top()) {
            //현재 종료 시간이 가장 이른 수업보다
            //lec[i]의 시작시간이 같거나 더 느리다면
            pq.pop(); //강의실 함께 사용 가능하므로
        }

        //(if 조건에 만족하지 않을 경우) 새로운 강의실을 하나 추가하거나
        //(if 조건을 만족하는 경우) 기존 강의실 종료 시간 갱신신
       pq.push(lec[i].second);
    }

    return pq.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; //N: 수업 개수
    cin >> N;

    vector<st> lecture(N, st(0, 0));

    for (int i = 0; i < N; i++) {
        cin >> lecture[i].first >> lecture[i].second;
    }
    sort(lecture.begin(), lecture.end()); //종료 시간이 빠른 순으로 정렬

    cout << findMin(N, lecture) << "\n";

    return 0;
}
