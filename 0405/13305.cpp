//
// Created by 82108 on 2022-04-10.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1e5;

int dist[MAX];
int cost[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; //도시 개수
    cin >> N;

    long long minCost;
    long long currentCost;

    for (int i = 1; i < N; i++) { //도시 사이 거리 저장
        cin >> dist[i];
    }
    for (int i = 0; i < N; i++) { //기름 값 저장
        cin >> cost[i];
    }
    currentCost = cost[0];
    minCost = currentCost * dist[1];

    for (int i = 1; i < N; i++) {
        if (currentCost > cost[i]) { //현재 기름 값이 더 비싸면
            currentCost = cost[i];
        }
        minCost += currentCost * dist[i + 1];
    }

    cout << minCost;

    return 0;
}