#include <string>
#include <vector>
#include<iostream>

#include<string.h>
#include<map>

using namespace std;

map<string, int> m;
vector<int> tmp;
int visited[9];
vector<vector<int>> ans;

bool checking(vector<vector<string>> relation) {
    int i, j;
    string str;

    m.clear();
    for (i = 0; i < relation.size(); i++) {
        str = "";
        for (j = 0; j < relation[i].size(); j++) {
            if (visited[j] == 1) {
                str += relation[i][j];
            }
        }
        
        m[str]++;
        if (m[str] >= 2) return false;
    }

    return true;
}

void per(int v, int now, int sizeb, int size, vector<vector<string>> relation) {
    if (v == size) {
              
        int i, check;
        for (i = 0; i < ans.size(); i++) {
            check = 0;
            for (int j = 0; j < ans[i].size(); j++) {
                if (visited[ans[i][j]] == 0) {
                    check = 1; break;
                }
            }
            if (check == 0) {
                return;
            }
        }

        bool flag = checking(relation);
        if (flag == true) {
            for (i = 0; i < sizeb; i++) {
                if (visited[i] == 1) tmp.push_back(i);
            }
            ans.push_back(tmp);
        }
        
        return;
    }
    for (int i = now; i < sizeb; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            per(v + 1, i + 1, sizeb, size, relation);
            visited[i] = 0;
        }
    }
    return;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int i;

    for (i = 1; i <= relation[0].size(); i++) {
        memset(visited, 0,sizeof(visited));
        per(0, 0, relation[0].size(), i, relation);
    }

    answer = ans.size();
    return answer;
}

int main() {
    vector<vector<string>> relation = { {"100","ryan","music","2"} ,{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},
    {"500","muzi","music","3"},{"600","apeach","music","2"} };

    int answer = solution(relation);

    printf("%d\n", answer);
}