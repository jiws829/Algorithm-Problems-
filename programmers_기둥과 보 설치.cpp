#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

int sort_n(vector<int> a, vector<int> b) {
    if (a[0] == b[0] && a[1] == b[1] && a[2] < b[2]) return 1;
    else if (a[0] == b[0] && a[1] < b[1]) return 1;
    else if (a[0] < b[0]) return 1;
    else return 0;
}

int check[103][103][2];

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int i, j;
    int x, y, a, b;
    int flag;

    for (i = 0; i < build_frame.size(); i++) {
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];

        if (b == 1) {  //삽입
            
            if (a == 0) {  //기둥
                if (y == 0 || check[y - 1][x][0] == 1 || (x >= 1 && check[y][x - 1][1] == 1) || check[y][x][1] == 1) {
                    check[y][x][0] = 1;
                    answer.push_back({x,y,a});
                }
            }
            else {  //보
                if ((y >= 1 && check[y - 1][x][0] == 1) || (y >= 1 && check[y - 1][x + 1][0] == 1) || (x >= 1 && x < n && check[y][x - 1][1] == 1 && check[y][x + 1][1] == 1)) {
                    check[y][x][1] = 1;
                    answer.push_back({x,y,a});
                }
            }
        }
        else {  //삭제
            check[y][x][a] = 0;
            flag = 0;


            for (int yy = 0; yy < n; yy++) {
                if (flag) break;
                for (int xx = 0; xx < n; xx++) {
                    if (yy<n && check[yy][xx][0] == 1) {  //기둥
                        if (!(yy == 0 || check[yy - 1][xx][0] == 1 || (xx >= 1 && check[yy][xx - 1][1] == 1) || check[yy][xx][1] == 1)) {
                            flag = 1;
                            break;
                        }
                    }
                    if (xx<n && check[yy][xx][1] == 1) { //보
                        if (yy == 0) continue;
                        if (!((yy >= 1 && check[yy - 1][xx][0] == 1) || (yy >= 1 && check[yy - 1][xx + 1][0] == 1) || (xx >= 1 && xx < n && check[yy][xx - 1][1] == 1 && check[yy][xx + 1][1] == 1))) {
                            flag = 1;
                            break;
                        }
                    }
                }
            }

            if (flag) {  //지우면 안되는 경우
                check[y][x][a] = 1;
            }
            else {  //지워도 되는경우
                for (j = 0; j < answer.size(); j++) {
                    if (answer[j][0] == x && answer[j][1] == y && answer[j][2] == a) break;
                }
                answer.erase(answer.begin() + j);
            }
        }
    }



    sort(answer.begin(), answer.end(), sort_n);
    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> build_frame = { {0,0,0,1} ,{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1 }};

    vector<vector<int>> answer = solution(n, build_frame);
    int i, j;
    for (i = 0; i < answer.size(); i++) {
        for (j = 0; j < answer[i].size(); j++) cout << answer[i][j] << " ";
        cout << endl;
    }
}