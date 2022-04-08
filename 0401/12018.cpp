//
// Created by 82108 on 2022-04-08.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//최대한 많은 수업을 듣기 위해서는
//가장 마일리지가 적게 드는 과목부터 수강해야 함
int maxClass(int m, priority_queue<int, vector<int>, greater<>> &pq) {
    int result = 0; //수강 가능한 과목 수를 0으로 초기화
    while (!pq.empty() && pq.top() <= m) {
        //더 이상 들을 과목이 없거나 마일리지가 모자랄 경우, 반복문 종료
        m -= pq.top(); //성준이가 가진 마일리지 m에서 pq.top() 빼기 (pq.top()에는 성준이가 필요로 하는 최소 마일리지가 저장되어 있음)
        pq.pop(); //pq.top() 삭제
        result++; //수강 가능한 과목 수 증가시키기
    }
    return result; //result return
}

int main() {
    int n, m, p, l; //n: 과목 수, m: 마일리지, p: 과목 신청자 수, l: 수강인원
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙 pq 선언

    cin >> n >> m; //n과 m 입력받기
    while (n--) { //n번 반복
        cin >> p >> l; //p와 l 입력받기
        vector<int> arr(p); //크기가 p인 배열 arr 선언
        for (int i = 0; i < p; i++) { //p번 반복
            cin >> arr[i]; //arr에 해당 과목 신청자들의 마일리지 저장
        }

        if (p < l) { //과목 신청자 수가 수강인원보다 적은 경우에 실행되는 코드
            //미달이기 때문에 마일리지를 1만 넣어도 됨
            pq.push(1);
            continue; //다음 반복으로
        }
        //해당 과목 신청자들의 마일리지를 내림차순 정렬
        sort(arr.begin(), arr.end(), greater<>());
        //마일리지는 최대한 적게 넣을수록 좋음 (최대한 많은 과목을 들어야 하므로)
        //성준이는 l번째로 마일리지를 많이 넣은 사람과 동일한 양의 마일리지를 넣으면 됨
        //넣은 마일리지가 동일할 때, 성준이에게 우선권이 있으므로
        pq.push(arr[l - 1]);
    } //성준이가 특정 과목을 수강하기 위해 필요로 하는 마일리지들이 pq에 저장됨

    //출력
    cout << maxClass(m, pq); //maxClass의 결과 출력
}