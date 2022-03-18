//
// Created by 82108 on 2022-03-17.
//

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; //카드 개수
    cin >> N;

    int method; //카드 기술 번호
    vector<int> method_list;
    for (int i = 0; i < N; i++) {
        //배열에 카드 기술 번호 넣기
        cin >> method;
        method_list.push_back(method);
    }

    //기술들 거꾸로
    //1번 기술: 바닥에 내려진 카드를 가져와 제일 위(front)에 쌓기
    //2번 기술: 바닥에 내려진 카드를 가져와 맨 위에서 2번째에 놓기
    //3번 기술: 바닥에 내려진 카드를 가져와 맨 아래(back)에 놓기기
    reverse(method_list.begin(), method_list.end());

    int card = 1;
    deque<int> card_dq;
    for (int i = 0; i < N; i++) {
        if (method_list[i] == 1) {
            card_dq.push_front(card);
        } else if (method_list[i] == 2) {
            int temp = card_dq[0];
            card_dq.pop_front();
            card_dq.push_front(card);
            card_dq.push_front(temp);
        } else if (method_list[i] == 3) {
            card_dq.push_back(card);
        }
        card++;
    }

    for (int i = 0; i < N; i++) {
        cout << card_dq[i] << " ";
    }

    return 0;
}