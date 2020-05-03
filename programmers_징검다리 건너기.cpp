#include <string>
#include <vector>
#include<stdio.h>

using namespace std;

int checking(vector<int> stones, int k, int m) {
    int i;
    int cnt = 0;
    
    for (i = 0; i < stones.size(); i++) {
        if (stones[i] < m) {
            cnt++;
            if (cnt >= k) return 0;  //못 건너는 경우
        }
        else cnt = 0;
    }

    return 1;  //건널수 있음
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    int st=0, en=-999, mid;
    int i, flag;
    for (i = 0; i < stones.size(); i++) {
        if (en < stones[i]) en = stones[i];
    }
   
    while (st <= en) {
        mid = (st + en) / 2;

        flag = checking(stones, k, mid);

        if (flag == 1) {
            st = mid + 1;
            answer = mid;
        }
        else {
            en = mid - 1;
        }
    }

    return answer;
}

int main() {
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    int k = 3;

    int answer = solution(stones, k);

    printf("%d\n", answer);
}