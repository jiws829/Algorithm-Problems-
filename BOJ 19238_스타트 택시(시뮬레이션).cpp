#include<stdio.h>
#include<queue>
using namespace std;

int n, m, fuel;
int map[21][21];
int xx, yy;
int cnt;
struct passenger {
	int a, b, c, d;
	int done;
}t[401];
int path[401];

int bfs(int x, int y, int z, int w) {
	queue<int> aa, bb, cc;
	int a, b;
	int i;
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int visited[21][21] = { 0, };

	aa.push(x);
	bb.push(y);
	cc.push(0);

	while (!aa.empty()) {
		a = aa.front();
		b = bb.front();

		if (a == z && b == w) return cc.front();

		for (i = 0; i < 4; i++) {
			if (a + dx[i] < 1 || a + dx[i] > n || b + dy[i] < 1 || b + dy[i] > n || visited[a + dx[i]][b + dy[i]] == 1 || map[a + dx[i]][b + dy[i]] == 1) continue;
			visited[a + dx[i]][b + dy[i]] = 1;
			aa.push(a + dx[i]);
			bb.push(b + dy[i]);
			cc.push(cc.front() + 1);
		}
		aa.pop();
		bb.pop();
		cc.pop();
	}

	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);

	int i, j;

	scanf("%d %d %d", &n, &m, &fuel);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) scanf("%d", &map[i][j]);
	}
	scanf("%d %d", &xx, &yy);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &t[i].a, &t[i].b, &t[i].c, &t[i].d);
	}

	while (1) {
		int min = 2100000;
		int v;
		int dist;

		for (i = 1; i <= m; i++) {
			if (t[i].done == 1) continue;
			dist = bfs(xx, yy, t[i].a, t[i].b);
			//printf("%d %d\n", i, dist);
			if (dist >= 0 && min > dist || (min==dist && t[i].a < t[v].a) || (min == dist && t[i].a == t[v].a && t[i].b < t[v].b)) {
				min = dist;
				v = i;
			}
		}
		//printf("!!%d\n", v);

		if (min == 2100000) break;

		//픽업
		fuel -= min;
		xx = t[v].a;
		yy = t[v].b;
		if (fuel < 0) break;


		//데려다줌
		dist = bfs(xx, yy, t[v].c, t[v].d);
		if (dist < 0) break;

		fuel -= dist;
		xx = t[v].c;
		yy = t[v].d;
		if (fuel < 0) break;
		fuel += 2 * dist;
		t[v].done = 1;
		cnt++;
		
		//printf("fuel: %d\n", fuel);

		if (cnt == m) break;
	}

	if (cnt == m) printf("%d\n", fuel);
	else printf("-1\n");
}
