//
// Created by 82108 on 2022-03-09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) { //y좌표가 다르면 y좌표가 증가하는 순으로
        return a.second < b.second;
    }
    return a.first < b.first; //y좌표가 같으면 x좌표가 증가하는 순으로
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    return 0;
}