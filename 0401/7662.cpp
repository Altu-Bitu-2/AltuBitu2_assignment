//
// Created by 82108 on 2022-04-08.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k, n; //t: 입력 데이터 수, k: 큐에 적용할 연산 개수, n: 삽입/삭제할 정수
    char cmd; //수행할 연산 D: 삭제, I: 삽입

    cin >> t; //t 입력받기
    while (t--) { //t번 반복
        multiset<int> ms; //중복을 허용하는 multiset 선언
        cin >> k; //k 입력받기
        while (k--) { //k번 반복
            cin >> cmd >> n; //cmd랑 n 입력받기

            switch (cmd) { //cmd에 따라 case 결정
                case 'I': //삽입 연산 (동일한 정수 삽입 가능)
                    ms.insert(n); //multiset에 n 삽입
                    break;
                case 'D': //삭제 연산
                    if (ms.empty()) { //ms가 비어있다면 연산 무시하기
                        break;
                    }
                    if (n == 1) { //최댓값 삭제
                        //ms는 set이기 때문에 자동 정렬됨
                        //최댓값을 삭제하기 위해 ms.end()에 접근해 이를 지우기
                        ms.erase(--ms.end());
                    }
                    if (n == -1) { //최솟값 삭제
                        //최솟값을 삭제하기 위해 ms.begin()에 접근해 이를 지우기
                        ms.erase(ms.begin());
                    }
                    break;
            }
        }

        if (ms.empty()) //ms가 비어있다면
            cout << "EMPTY\n"; //EMPTY 출력
        else //ms가 비어있지 않다면
            //ms.end() (= 최댓값)와 ms.begin() (= 최솟값)을 공백으로 구분해 출력
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
    }
}