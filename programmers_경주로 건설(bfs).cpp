#include <string>
#include <vector>

using namespace std;

struct pp {
    int x, y, dir, cost;
};

int visited[26][26];

int solution(vector<vector<int>> board) {
    int answer = 21000000;

    int n = board.size();
    vector<pp> p;
    int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };

    p.push_back({ 0,0,-1,0 });

    while (!p.empty()) {
        int x = p.front().x;
        int y = p.front().y;
        //printf("%d %d  %d cost:%d\n", x, y,p.front().dir,p.front().cost);

        if (x == n - 1 && y == n - 1) {
            //printf("%d\n", p.front().cost);
            if (answer > p.front().cost) answer = p.front().cost;
            p.erase(p.begin());
            continue;
        }

        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= n || board[x + dx[i]][y + dy[i]] == 1) continue;

            int cost;
            if (p.front().dir == -1 || p.front().dir == i) cost = p.front().cost + 100;
            else cost = p.front().cost + 600;

            if (visited[x + dx[i]][y + dy[i]] == 0) {
                visited[x + dx[i]][y + dy[i]] = cost;
                p.push_back({ x + dx[i],y + dy[i],i,cost });
            }
            else if (visited[x + dx[i]][y + dy[i]] >= cost) {
                visited[x + dx[i]][y + dy[i]] = cost;
                p.push_back({ x + dx[i],y + dy[i],i,cost });
            }
        }
        p.erase(p.begin());
    }
    return answer;
}