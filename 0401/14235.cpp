//
// Created by 82108 on 2022-04-08.
//

#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input; //n: 방문 횟수(0일 때에는 아이들 만남), a: 선물 충전 개수, input: 선물 가치
    priority_queue<int> pq; //정수를 저장하는 최대 힙 pq 선언

    cin >> n; //n 입력받기
    while (n--) { //n번 반복
        cin >> a; //a 입력받기
        if (!a) { //a가 0일 때 실행되는 코드 >> 아이들을 만난 경우
            if (pq.empty()) { //산타가 선물을 갖고있지 않다면
               cout << "-1\n"; //-1 출력
            } else { //산타가 선물을 갖고 있다면
                cout << pq.top() << '\n'; //pq에 저장된 최댓값 출력
                pq.pop(); //pq의 최댓값 삭제
            }
        } else { //a가 0이 아닐 때 실행되는 코드 >> 선물을 충전하는 경우
            while (a--) { //a번 반복
                cin >> input; //input 입력받기
                pq.push(input); //pq에 input 삽입
            }
        }
    }
    return 0;
}