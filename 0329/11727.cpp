//
// Created by 82108 on 2022-04-05.
//

#include <iostream>
#include <vector>

using namespace std;
const int MOD = 10007; //문제의 조건에 의해, 방법의 가짓수를 나눌 수 10007 선언

int fillTile(int n) { //직사각형의 가로 길이를 input으로 갖고, int를 return하는 함수 fillTile()
    vector<int> dp(n + 1, 0); //0~n번 인덱스를 갖는 배열 선언 & 0으로 값을 초기화

    if (n == 1) { //직사각형의 가로 길이가 1일 경우, 채우는 방법이 1가지이기 때문에 (2*1 타일 1개로 채우기)
        return 1; //바로 1 return
    }

    dp[1] = 1; //n이 1일 때, 타일을 채우는 방법 가짓수는 1 (2*1 타일 1개)
    dp[2] = 3; //n이 2일 때, 타일을 채우는 방법 가짓수는 3 (2*1 타일 2개, 1*2 타일 2개, 2*2 타일 1개)
    for (int i = 3; i <= n; i++) { //미리 가짓수 구해서 배열 채우기
        //가로 길이가 i인 직사각형의 경우,
        //가로 길이가 i-1인 직사각형을 먼저 채우고
        //그 왼쪽 or 오른쪽에, 가로 길이가 i-2인 직사각형을 채우면 됨 (왼쪽 or 오른쪽이므로 "*2" 연산 수행)
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        //미리 MOD로 나누기
        dp[i] %= MOD;
    }
    return dp[n]; //가로 길이가 n인 직사각형을 채우는 방법 가짓수 return
}

int main() {
    int n; //직사각형의 가로 길이

    //입력
    cin >> n; //n 입력받기

    //연산 & 출력
    cout << fillTile(n); //fillTile(n)의 결과 출력하기
    return 0;
}