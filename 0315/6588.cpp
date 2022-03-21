//
// Created by 82108 on 2022-03-19.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6; //test case의 최대 개수
vector<bool> isPrime(MAX + 1, true);
//1000000+1개의 요소를 갖는 isPrime 배열(true로 초기화)

void findPrime() {
    //에라토스테네스의 체
    isPrime[0] = isPrime[1] = false; //0과 1은 소수가 아니므로

    for (int i = 2; i <= MAX; i++) {
        //i가 소수인지 판단
        if (!isPrime[i]) {
            //i가 소수가 아니라면
            continue;
        }
        for (int j = 2 * i; j <= MAX; j += i) {
            //i가 소수라면 j를 이용해 i의 배수 지우기
            if (!isPrime[j]) {
                //이미 j가 지워졌다면
                continue;
            }
            isPrime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1; //입력받는 수
    int a, b; //n = a + b (a < b)
    bool isCorrect = false;

    findPrime();

    while (n != 0) {
        cin >> n; //입력받기

        for (int i = 3; i <= n / 2; i += 2) {
            a = i;
            b = n - a;

            if (isPrime[a] && isPrime[b]) {
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