#include <string>
#include <vector>

#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

int member[8][8], cnt[8];
int visited[8];
int cn;
vector<int> tt;
vector<vector<int>> pp;

void per(int v, int size) {
    if (v == size) {
        vector<int> tmp;
        for (int i = 0; i < size; i++) tmp.push_back(tt[i]);

        sort(tmp.begin(), tmp.end());

        int flag;
        if (pp.empty()) { pp.push_back(tmp); cn++; }
        else {
            for (int i = 0; i < pp.size(); i++) {
                flag = 0;
                for (int j = 0; j < size; j++) {
                    if (pp[i][j] != tmp[j]) { flag = 1; break; }
                }
                if (flag == 0) return;
            }

            pp.push_back(tmp);
            cn++;
        }
        return;
    }
    for (int i = 0; i < cnt[v]; i++) {
        if (visited[member[v][i]] == 0) {
            visited[member[v][i]] = 1;
            tt.push_back(member[v][i]);
            per(v + 1, size);
            visited[member[v][i]] = 0;
            tt.pop_back();
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int i, j, k;
    int check;

    for (i = 0; i < banned_id.size(); i++) {
        for (j = 0; j < user_id.size(); j++) {
            if (banned_id[i].size() != user_id[j].size()) continue;

            check = 0;
            for (k = 0; k < banned_id[i].size(); k++) {
                if (banned_id[i][k] != '*' && banned_id[i][k] != user_id[j][k]) {
                    check = 1;
                    break;
                }
            }
            if (check) continue;

            member[i][cnt[i]++] = j;
        }
    }

    per(0, banned_id.size());

    answer = cn;
    return answer;
}

int main() {
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> banned_id = { "fr*d*", "abc1**" };

    int ans = solution(user_id, banned_id);

    printf("%d\n", ans);

}