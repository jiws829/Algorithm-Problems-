#include<stdio.h>
#include<queue>
using namespace std;

queue<pair<int,int>> q;
int p[1001][1001];
int n, m;
int cnt, visit_count;

int bfs() {
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int max = -999;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;

		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && p[x + dx[i]][y + dy[i]] == 0) {
				
				p[x + dx[i]][y + dy[i]] = p[x][y] + 1;
				if (max < p[x][y]) max = p[x][y];

				q.push(make_pair(x + dx[i], y + dy[i]));
			}
		}
		q.pop();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (p[i][j] == 0) return -1;
		}
	}

	return max;
}


int main() {
	int i, j;
	int answer;
	
	int flag = 0;
	
	scanf("%d %d", &m, &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &p[i][j]);
			if (p[i][j] != -1) cnt++;
			if (p[i][j] == 1) {
				q.push(make_pair(i, j));
				visit_count++;
			}
		}
	}

	if (cnt == visit_count) {
		answer = 0;
	}
	else {
		answer = bfs();
	}

	printf("%d\n", answer);
}