#include <string>
#include <vector>
#include<iostream>

using namespace std;

bool check(int count, vector<vector<int>> key, vector<vector<int>> lock) {
    int i, j;
    int x, y;
    int cnt;
    int flag;
    int size = lock.size() / 3;

    for (x = 1; x < lock.size()-key.size(); x++) {
        for (y = 1; y < lock.size()-key.size(); y++) {
            cnt = count;
            flag = 0;
            
            for (i = 0; i < key.size(); i++) {
                if (flag == 1) break;
                for (j = 0; j < key.size(); j++) {
                    if (!(x + i >= size && x + i < 2 * size && y + j >= size && y + j < 2 * size)) continue;

                    if (lock[x + i][y + j] == 1 && key[i][j] == 1) { flag = 1; break; }
                    
                    if (lock[x + i][y + j] == 0 && key[i][j] == 1) cnt--;
                }
            }

            if (flag == 0 && cnt == 0) return true;
        }
    }

    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    vector<vector<int>> p(key.size(), vector<int>(key.size(), 0));
    vector<vector<int>> t(lock.size() * 3, vector<int>(lock.size()*3,0));
    int i, j;
    int count = 0;  //자물쇠 구멍 개수
    bool flag;

    //자물쇠 구멍 개수 확인
    for (i = 0; i < lock.size(); i++) {
        for (j = 0; j < lock.size(); j++) {
            if (lock[i][j] == 0) count++;
            t[lock.size() + i][lock.size() + j] = lock[i][j];
        }
    }
    /*for (i = 0; i < 3*lock.size(); i++) {
        for (j = 0; j < 3*lock.size(); j++) printf("%d ",t[i][j]);
        printf("\n");
    }*/
    

    for (int kk = 0; kk < 4; kk++) {
        //시계방향으로 회전
        for (i = 0; i < key.size(); i++) {
            for (j = 0; j < key.size(); j++) {
                p[i][j] = key[key.size() - j - 1][i];
            }
        }

        key = p;

        //열쇠가 들어가는지 확인
        flag = check(count, key, t);
        if (flag == true) {
            //printf("%d\n", flag);
            return true;
        }
         
    }
    
    return false;
}

int main() {
    vector<vector<int>> key = { {0, 0, 0},{1, 0, 0},{0, 1, 1} };
    vector<vector<int>> lock = { {1, 1, 1},{1, 1, 0},{1, 0, 1} };

    bool answer = solution(key, lock);

    cout << answer;
}