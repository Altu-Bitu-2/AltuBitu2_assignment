//
// Created by 82108 on 2022-04-15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) {
    ll sum = 0; //잘리는 나무들의 길이 합을 0으로 초기화
    for (int i = 0; i < tree.size(); i++) { //tree 배열의 크기만큼 반복
        if (height >= tree[i]) {
            //height는 절단기의 높이
            //내림차순으로 정렬했기 때문에
            //절단기의 높이 >= 나무의 높이라면, 나무가 잘리지 않으므로
            return sum; //지금까지 계산된 sum을 return
        }
        //나무가 잘릴 경우
        //나무가 잘리는 만큼 sum에다가 더하기
        sum += (tree[i] - height);
    }
    return sum; //모든 나무가 잘린 후, sum을 return
}

int upperSearch(int left, int right, int target, vector<int> &tree) {
    while (left <= right) { //left <= right를 만족하는 동안 반복
        int mid = (left + right) / 2; //주어진 left 값과 right 갑의 평균으로 mid를 초기화

        //mid를 활용해 cntTree()를 수행한 후
        //이를 tree_cnt에 저장 (잘리는 나무들 길이 전체 합이 tree_cnt에 저장됨)
        ll tree_cnt = cntTree(mid, tree);

        //목표로 하는 길이: target
        if (tree_cnt >= target) {
            //목표 이상으로 나무가 잘리는 경우
            left = mid + 1; //절단기의 높이 올리기
        } else {
            //나무가 더 잘려야 하는경우
            right = mid - 1; //절단기의 높이 내리기
        }
    }
    //위의 반복문에서
    //tree_cnt = target을 만족할 때에도 left = mid + 1을 수행했으므로
    //최종 left 값으로는 (mid + 1) - 1을 return
    return left - 1;
}

int main() {
    int n, m; //n: 나무의 수, m: 상근이가 필요로 하는 나무의 길이
    cin >> n >> m; //n과 m 입력받기

    vector<int> tree(n, 0); //전체 나무들의 높이를 저장할 배열 tree 선언
    for (int i = 0; i < n; i++) { //n번 반복
        cin >> tree[i]; //나무들 높이 저장장
   }

    //나무들의 높이를 내림차순으로 정렬
    sort(tree.begin(), tree.end(), greater<>());

    //upperSearch() 수행 후 그 결과를 출력
    cout << upperSearch(0, tree[0], m, tree);

    return 0;
}