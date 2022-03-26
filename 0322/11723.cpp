//
// Created by 82108 on 2022-03-27.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string operation; //집합 연산
    int x; //집합 연산에 활용되는 수
    vector<int> setResult;
    setResult.assign(21, 0);//21개의 요소를 모두 0으로 초기화

    int M; //연산 개수
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> operation;

        if (operation == "add") {
            cin >> x;
            if (setResult[x] == 0) {
                //집합에 없을 경우 추가
                setResult[x] = 1;
            }
        } else if (operation == "remove") {
            cin >> x;
            if (setResult[x] == 1) {
                //집합에 있을 경우 삭제
                setResult[x] = 0;
            }
        } else if (operation == "check") {
            cin >> x;
            //결과 출력
            cout << setResult[x] << "\n";
        } else if (operation == "toggle") {
            cin >> x;
            if (setResult[x] == 0) {
                //없으면 추가
                setResult[x] = 1;
            } else if (setResult[x] == 1) {
                //있으면 삭제
                setResult[x] = 0;
            }
        } else if (operation == "all") {
            for (int i = 1; i < setResult.size(); i++) {
                if (setResult[i] == 0) {
                    //없으면 추가
                    setResult[i] = 1;
                }
            }
        } else if (operation == "empty") {
            for (int i = 1; i < setResult.size(); i++) {
                if (setResult[i] == 1) {
                    //있으면 삭제
                    setResult[i] = 0;
                }
            }
        }
    }

    return 0;
}