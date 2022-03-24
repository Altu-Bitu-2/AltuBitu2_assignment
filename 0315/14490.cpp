//
// Created by 82108 on 2022-03-18.
//

#include <iostream>
#include <string>

using namespace std;

int findGCD(int nn, int mm) {
    if (mm == 0) {
        return nn;
    } else {
        return findGCD(mm, nn % mm);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string quiz; //입력받을 문자열
    cin >> quiz;

    int n, m;
    int temp; //

    temp = quiz.find(':');
    n = stoi(quiz.substr(0, temp));
    m = stoi(quiz.substr(temp + 1));

    int gcd = findGCD(n, m); //최대공약수
    n /= gcd;
    m /= gcd;
    cout << n << ':' << m;

    return 0;
}