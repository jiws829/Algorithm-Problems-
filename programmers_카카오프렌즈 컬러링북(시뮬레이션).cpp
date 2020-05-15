#include <vector>

using namespace std;

vector<vector<int>> p;
int cnt;

void flood(int x, int y, int v) {
    int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };

    p[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        if (x + dx[i] >= 0 && x + dx[i] < p.size() && y + dy[i] >= 0 && y + dy[i] < p[0].size() && p[x + dx[i]][y + dy[i]] == v) {
            cnt++;
            flood(x + dx[i], y + dy[i], v);
        }
    }

    return;    
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    int i, j;
    int max = -999;

    p = picture;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (p[i][j] != 0) {
                answer[0]++;
                cnt = 1;
                flood(i, j, p[i][j]);

                if (max < cnt) max = cnt;
            }
        }
    }

    answer[1] = max;    
    return answer;
}

int main() {
    vector<int> answer = solution(6, 4, { {1, 1, 1, 0} ,{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} });

    printf("%d %d\n", answer[0], answer[1]);
}