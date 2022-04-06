//
// Created by 82108 on 2022-04-05.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10; //문제 조건에 의해 정수 n으로 주어질 수 있는 최대 값은 10

//bottom-up 방식 dp 배열 채우기
vector<int> numberOfAllCases() {
    //int 배열을 return 값으로 갖는 numberOfAllCases() 함수
    vector<int> dp(MAX + 1, 0);
    //0~10번 인덱스를 갖는, 총 11개의 요소를 갖는 배열 dp 선언 & 모든 값을 0으로 초기화

    dp[0] = dp[1] = 1;
    //1을 1, 2, 3의 합으로 나타내는 방법은 1가지 (1 = 1)
    //0번째 인덱스는 문제의 필요하지 않은 인덱스이지만,
    // 아래 for문에서 3번 인덱스부터 일괄적으로 계산할 수 있도록 1을 값으로 갖도록 함 (dp[3] = 2 + 1 + 1이 될 수 있도록)
    dp[2] = 2;
    //2를 1, 2, 3의 합으로 나타내는 방법은 2가지 (2 = 2, 1+1)
    //3을 1, 2, 3의 합으로 나타내는 방법은 4가지 (3 = 3, 2+1, 1+2, 1+1+1)
    for (int i = 3; i <= MAX; i++) { //3번 인덱스부터 마지막 인덱스까지 반복해 미리 값 채우기
        //dp의 i번째 값을 i보다 바로 작은 3가지 수의 합을 통해 구하기
        //ex. 4 = (3을 표현하는 방법 가짓수) + (2를 표현하는 방법 가짓수) + (1을 표현하는 방법 가짓수)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp; //모든 경우의 수를 다 구해서 저장한 배열 dp를 return
}

int main() {
    int t, n; //t는 테스트 케이스의 개수, n은 1, 2, 3의 합으로 표현할 정수

    //미리 dp 채우기
    vector<int> dp = numberOfAllCases();
    //main()의 dp에는 numberOfAllCases()에서 return하는 dp가 대입됨

    //입력
    cin >> t; //t 입력받기
    while (t--) { //t번 반복
        cin >> n; //n 입력받기

        //출력
        cout << dp[n] << '\n';
        //dp에서 n번째 인덱스에 존재하는 값을 출력
    }
    return 0;
}