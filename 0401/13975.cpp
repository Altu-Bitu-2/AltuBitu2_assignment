//
// Created by 82108 on 2022-04-08.
//

#include <iostream>
#include <queue>

using namespace std;
typedef long long ll; //long long 타입을 ll로 정의

ll getCost(priority_queue<ll, vector<ll>, greater<>> &pq) { //long long을 return하는 getCost() 함수
    ll ans = 0; //최소 비용 ans를 0으로 초기화

    while (pq.size() > 1) { //pq의 크기가 1이 되기 전까지 반복
        ll card1 = pq.top(); //pq에 저장된 가장 작은 값을 card1에 저장
        pq.pop(); //pq.top() 삭제
        ll card2 = pq.top(); //pq에 저장된 그 다음으로 작은 값을 card2에 저장
        pq.pop(); //pq.top() 삭제
        ans += card1 + card2; //card1과 card2의 합을 ans에 저장
        pq.push(card1 + card2); //card1과 card2의 합을 pq에 저장 (새로운 파일 크기로)
    }
    return ans; //ans return
}

int main() {
    int t, k, file; //t: 테스트 데이터 개수, k: 소설 장 수, file: 파일 크기

    cin >> t; //t 입력받기
    while (t--) { //t번 반복
        priority_queue<ll, vector<ll>, greater<>> pq; //file 크기를 저장하는 최소힙 pq 선언

        cin >> k; //k 입력받기
        for (int i = 0; i < k; i++) { //k번 반복
            cin >> file; //file 입력받기
            pq.push(file); //pq에 file 삽입
        }

        cout << getCost(pq) << '\n'; //getCost(pq)의 값을 출력
    }
    return 0;
}