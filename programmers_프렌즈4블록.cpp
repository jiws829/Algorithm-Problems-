#include <string>
#include <vector>
#include<iostream>

#include<string.h>
using namespace std;

int p[31][31];
int t[31][31];

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int i, j;
    int flag, num;
    vector<int> tmp;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            p[i][j] = board[i][j] - 'A' + 1;
        }
    }

    while (1) {
        flag = 0;
        memset(t, 0, sizeof(t));

        //블록 찾기
        for (i = 0; i < m - 1; i++) {
            for (j = 0; j < n - 1; j++) {
                if (p[i][j] == 0) continue;
                num = p[i][j];
                
                if (p[i + 1][j] == num && p[i][j + 1] == num && p[i + 1][j + 1] == num) {
                    t[i][j] = t[i + 1][j] = t[i][j + 1] = t[i + 1][j + 1] = 1;
                    //printf("%d %d -> %d\n", i, j, num);
                    flag = 1;
                }
            }
        }

        //블록 지우기 & 아래로 내리기
        for (j = 0; j < n; j++) {
            tmp.clear();
            for (i = m - 1; i >= 0; i--) {
                if (t[i][j] == 0) tmp.push_back(p[i][j]);
                else answer++;
                p[i][j] = 0;
            }

            i = m - 1;
            while (!tmp.empty()) {
                p[i--][j] = tmp.front();
                tmp.erase(tmp.begin());
            }
        }
        if (flag == 0) break;
    }
    return answer;
}

int main() {
    int answer = solution(6, 6, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" });

    cout << answer << endl;
}