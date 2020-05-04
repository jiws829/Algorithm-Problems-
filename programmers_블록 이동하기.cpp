#include <string>
#include <vector>
#include<iostream>

using namespace std;

struct robots {
    int ax, ay, bx, by;
    int cnt;
};

int visited[101][101][101][101];

int solution(vector<vector<int>> board) {
    int answer = 210000000;
    vector<robots> r;
    int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
    int a, b, c, d;
    int n = board.size();
    


    r.push_back({ 0,0,0,1 });
    visited[0][0][0][1] = 1;

    while (!r.empty()) {
        a = r.front().ax;
        b = r.front().ay;
        c = r.front().bx;
        d = r.front().by;    
        

        if ((a == n - 1 && b == n - 1) || (c == n - 1 && d == n - 1)) { 
            if (answer > r.front().cnt) answer = r.front().cnt;
            r.erase(r.begin());
            continue;
        }

        //이동
        for (int i = 0; i < 4; i++) {
            if (a + dx[i] < 0 || a + dx[i] >= n || b + dy[i] < 0 || b + dy[i] >= n || c + dx[i] < 0 || c + dx[i] >= n || d + dy[i] < 0 || d + dy[i] >= n) continue;
            if (board[a + dx[i]][b + dy[i]] == 0 && board[c + dx[i]][d + dy[i]] == 0 && visited[a + dx[i]][b + dy[i]][c + dx[i]][d + dy[i]] == 0) {
                r.push_back({ a + dx[i],b + dy[i],c + dx[i],d + dy[i],r.front().cnt + 1 });
                visited[a + dx[i]][b + dy[i]][c + dx[i]][d + dy[i]] = 1;
            }
        }

        //회전
        //a축 기준
        if (b == d) {  //세로
            if (b - 1 >= 0 && board[a][b - 1] == 0 && board[c][b - 1] == 0 && visited[a][b][a][b - 1] == 0) {
                r.push_back({ a,b,a,b - 1,r.front().cnt + 1 }); visited[a][b][a][b - 1] = 1; 
            }
            if (b + 1 < n && board[a][b + 1] == 0 && board[c][b + 1] == 0 && visited[a][b][a][b + 1] == 0) {
                r.push_back({ a,b,a,b + 1,r.front().cnt + 1 }); visited[a][b][a][b + 1] = 1;
            }
        }
        else {  //가로
            if (a - 1 >= 0 && board[a - 1][b] == 0 && board[a - 1][d] == 0 && visited[a][b][a - 1][b] == 0) {
                r.push_back({ a,b,a - 1,b,r.front().cnt + 1 }); visited[a][b][a - 1][b] = 1;
            }
            if (a + 1 < n && board[a + 1][b] == 0 && board[a + 1][d] == 0 && visited[a][b][a + 1][b] == 0) {
                r.push_back({ a,b,a + 1,b,r.front().cnt + 1 }); visited[a][b][a + 1][b] = 1;
            }
        }

        //c축 기준
        if (b == d) {  //세로
            if (d - 1 >= 0 && board[c][d - 1] == 0 && board[a][d - 1] == 0 && visited[c][d - 1][c][d] == 0) {
                r.push_back({ c,d - 1,c,d,r.front().cnt + 1 }); visited[c][d - 1][c][d] = 1;
            }
            if (d + 1 < n && board[c][d + 1] == 0 && board[a][d + 1] == 0 && visited[c][d + 1][c][d] == 0) {
                r.push_back({ c,d + 1,c,d,r.front().cnt + 1 }); visited[c][d + 1][c][d] = 1;
            }
        }
        else {  //가로
            if (c - 1 >= 0 && board[c - 1][d] == 0 && board[c - 1][b] == 0 && visited[c - 1][d][c][d] == 0) {
                r.push_back({ c - 1,d,c,d,r.front().cnt + 1 }); visited[c - 1][d][c][d] = 1;
            }
            if (c + 1 < n && board[c + 1][d] == 0 && board[c + 1][b] == 0 && visited[c + 1][d][c][d] == 0) {
                r.push_back({ c + 1,d,c,d,r.front().cnt + 1 }); visited[c + 1][d][c][d] = 1;
            }
        }

        r.erase(r.begin());
    }

    return answer;
}

int main() {
    vector<vector<int>> board = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} };

    //vector<vector<int>> board = { {0, 0, 1, 1, 1},{0, 0, 1, 1, 1},{1, 0, 0, 1, 1},{1, 0, 0, 0, 0},{1, 1, 1, 0, 0} };
    int answer = solution(board);

    cout << answer;
}