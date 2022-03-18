//
// Created by 82108 on 2022-03-19.
//

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            //소수가 아니면
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1; //입력받는 수
    int a, b; //n = a + b (a < b)
    bool isCorrect = false;

    while (n) {
        cin >> n; //입력받기
        for (int i = 1; i < n / 2; i++) {
            //소수 찾기
            a = 2 * i + 1;
            b = n - a;

            if (isPrime(a) && isPrime(b)) {
                //a와 b가 모두 소수라면
                cout << n << " = " << a << " + " << b << "\n";
                isCorrect = true;
                break;
            }
        }
        if (!isCorrect) {
            //추측이 틀린 경우
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}