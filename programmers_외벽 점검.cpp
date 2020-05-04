#include <string>
#include <vector>
#include<iostream>
#include<string.h>

using namespace std;

int visited[10];
int per[10];
int minn = 2100000;

void check(int v, int n, vector<int> weak, vector<int> dist) {
    int i, j;
    vector<int> circle;
    int now;

    for (i = 0; i < weak.size(); i++) {
        circle.clear();
        for (j = i; j < weak.size(); j++) circle.push_back(weak[j]);
        for (j = 0; j < i; j++) circle.push_back(weak[j] + n);
        
        for (j = 0; j < v; j++) {
            if (circle.empty()) break;
            
            now = circle.front();
            circle.erase(circle.begin());
            while (!circle.empty()) {
                if (now + dist[per[j]] >= circle.front()) {
                    circle.erase(circle.begin());
                }
                else break;
            }
        }

        if (circle.size() == 0) {
            if (minn > v) minn = v;
        }
    }
}

void dfs(int v, int size, int n, vector<int> weak, vector<int> dist) {
    if (v == size) {
        check(v, n, weak, dist);

        return;
    }
    for (int i = 0; i < dist.size(); i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            per[v] = i;
            dfs(v + 1, size, n, weak, dist);
            per[v] = 0;
            visited[i] = 0;
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    int i;
    
    for (i = 1; i <= dist.size(); i++) {
        memset(visited, 0, sizeof(visited));
        dfs(0, i, n, weak, dist);
    }
    
    if (minn == 2100000) answer = -1;
    else answer = minn;

    return answer;
}

int main() {
    int n = 12;
    vector<int> weak = { 1, 3, 4, 9, 10 };
    vector<int> dist = { 3,5,7 };

    int answer = solution(n, weak, dist);
    cout << answer << endl;
}