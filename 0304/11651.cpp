//
// Created by 82108 on 2022-03-09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct xy {
    int x, y;
};

bool cmp(const xy &a, const xy &b) {
    if(a.y != b.y) { //y좌표가 다르면 y좌표가 증가하는 순으로
        return a.y < b.y;
    }
    return a.x < b.x; //y좌표가 같으면 x좌표가 증가하는 순으로
}

int main() {
    int N;
    cin >> N;

    vector<xy> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }
    return 0;
}