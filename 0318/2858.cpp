//
// Created by 82108 on 2022-03-24.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, B;
    cin >> R >> B;

    int tile = R + B; //전체 타일 개수
    int L, W;
    int red, brown;
    for (int l = 3; l <= sqrt(tile); l++) {
        //i가 1 또는 2라면 갈색 타일이 존재할 수 없음
        int w = tile / l;

        if (w < 3) {
            continue;
        }
        if (l * w == tile) {
            red = 2 * l + 2 * (w - 2);
            brown = (l - 2) * (w - 2);
            if (red == R && brown == B) {
                L = l;
                W = w;
                break;
            }
        }
    }
    if (L < W) {
        int tmp = L;
        L = W;
        W = tmp;
    }
    cout << L << " " << W;

    return 0;
}