/*
<17142 - 연구소 3>
1. 바이러스의 위치를 따로 저장해둔다.
2. DFS로 바이러스 중 어떤 것을 활성화할지 선택한다
3. BFS로 활성화된 바이러스가 퍼졌을 때 전체 빈칸을 채울때 걸리는 최소거리를 구한다

이 결과를 출력한다
*/
#include<stdio.h>
#include<vector>
using namespace std;

int n, m;
int p[51][51];
int virus[11][3], cnt;
int blank;
int minn = 210000000;
int check;

int bfs() {
	int i, j;
	int visited[51][51] = { 0, };
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	vector<int> x, y, z;
	int cn = 0;

	for (i = 0; i < cnt; i++) {
		if (virus[i][2] == 1) {
			x.push_back(virus[i][0]);
			y.push_back(virus[i][1]);
			z.push_back(0);
			visited[virus[i][0]][virus[i][1]] = 1;
		}
	}

	while (!x.empty()) {
		for (i = 0; i < 4; i++) {
			if (x.front() + dx[i] < 0 || x.front() + dx[i] >= n || y.front() + dy[i] < 0 || y.front() + dy[i] >= n) continue;
			if (visited[x.front() + dx[i]][y.front() + dy[i]] == 1 || p[x.front() + dx[i]][y.front() + dy[i]] == 1) continue;

			x.push_back(x.front() + dx[i]);
			y.push_back(y.front() + dy[i]);
			z.push_back(z.front() + 1);
			visited[x.front() + dx[i]][y.front() + dy[i]] = 1;
			if (p[x.front() + dx[i]][y.front() + dy[i]] == 0) {
				cn++;
				if (cn == blank) return z.front() + 1;
			}
		}
		x.erase(x.begin());
		y.erase(y.begin());
		z.erase(z.begin());
	}
	return -1;
}

void dfs(int now, int count) {
	if (count == m) {
		int ans = bfs(); //바이러스 퍼뜨림

		if (ans != -1) {
			check = 1;
			if (minn > ans) minn = ans;
		}
		return;
	}
	if (now == cnt - 1) return;

	for (int i = now + 1; i < cnt; i++) {
		virus[i][2] = 1;
		dfs(i, count + 1);
		virus[i][2] = 0;
	}
}

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
			if (p[i][j] == 2) {
				virus[cnt][0] = i;
				virus[cnt++][1] = j;
			}
			else if (p[i][j] == 0) blank++;
		}
	}

	if (blank == 0) printf("0\n");
	else {

		dfs(-1, 0); //활성바이러스 지정

		if (check == 0) minn = -1;
		printf("%d\n", minn);
	}
}