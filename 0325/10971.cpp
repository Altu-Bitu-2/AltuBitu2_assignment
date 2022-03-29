//
// Created by 82108 on 2022-03-30.
//

#include <iostream>

using namespace std;

int travel[10][10]; //최대로 도시 10개가 주어지기 때문
int minCost = 1e8; //순회 비용 (최대 비용 이상으로 초기화)
bool visited[10]; //방문 여부 판단
int city; //도시 총 개수
int cnt = 0; //방문한 도시 수

void findRoute(int current, int cost) {
    //current: 현재 위치
    if (cnt == city && current == 0) {
        //모든 도시를 다 돌아 다시 원위치로 돌아왔다면
        minCost = min(minCost, cost);
        return;
    }

    for (int i = 0; i < city; i++) {
        if (travel[current][i] == 0) {
            //현재 위치에서 i로 가는 방법이 없다면
            continue;
        }
        if (visited[i] == false) {
            //현재 위치에서 i 도시로 가는 방법이 있고
            //i 도시를 방문한 적이 없다면
            visited[i] = true;
            cnt++;
            //i 도시에서 다시 findRoute
            findRoute(i, cost + travel[current][i]);

            //방문 여부 및 도시 개수 초기화
            visited[i] = false;
            cnt--;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> city; //도시 개수

    for (int r = 0; r < city; r++) {
        for (int c = 0; c < city; c++) {
            cin >> travel[r][c];
        }
    }
    findRoute(0, 0); //0 도시에서 0원 비용으로 순회 시작
    cout << minCost;

    return 0;
}