//
// Created by 82108 on 2022-03-08.
//

#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int h, m, s;
    int q; //쿼리 개수
    int time; //현재 시간을 초로 변환한 것
    int t; //쿼리 번호
    int second; //조작할 시간

    const int DAY = 86400;

    cin >> h >> m >> s >> q;
    time = 3600 * h + 60 * m + s;

    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 3) { //시계 상황 출력
            cout << time / 3600 << " " << (time / 60) % 60 << " " << time % 60 << "\n";
        }
        else if(t == 1) { //시계 미래로 돌리기
            cin >> second;
            time = (time + second) % DAY;
        }
        else if(t == 2) { //시계 과거로 돌리기
            cin >> second;
            time = (time - second) % DAY;
            if(time < 0) {
                time += DAY;
            }
        }
        else { //예외 처리
            cout << "undefined query";
        }
    }

    return 0;
}