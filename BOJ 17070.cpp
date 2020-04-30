/*
<17070 - 파이프 옮기기 1>
(1,2)에서 가로로 놓여있는 상황에서
(n,n)으로 가는 경로를 구하면 된다

단 다음 파이프를 놓을때 벽이 있는지 조건만
잘 세워서 단계를 넘어가면 된다.

(n,n)에 도착하는 경우의 수를 모두 세어
출력한다.
*/
#include<stdio.h>

int p[17][17];
int n;
int ans;

void dfs(int x, int y, int dir) {
	if (x == n && y == n) {
		ans++;
		return;
	}

	if (dir == 1) { //가로
		if (y + 1 <= n && p[x][y + 1] == 0) dfs(x, y + 1, 1);
		if (y + 1 <= n && x + 1 <= n && p[x + 1][y + 1] == 0 && p[x][y + 1] == 0 && p[x + 1][y] == 0) dfs(x + 1, y + 1, 3);
	}
	else if (dir == 2) { //세로
		if (x + 1 <= n && p[x + 1][y] == 0) dfs(x + 1, y, 2);
		if (y + 1 <= n && x + 1 <= n && p[x + 1][y + 1] == 0 && p[x][y + 1] == 0 && p[x + 1][y] == 0) dfs(x + 1, y + 1, 3);
	}
	else { //대각선
		if (y + 1 <= n && p[x][y + 1] == 0) dfs(x, y + 1, 1);
		if (x + 1 <= n && p[x + 1][y] == 0) dfs(x + 1, y, 2);
		if (y + 1 <= n && x + 1 <= n && p[x + 1][y + 1] == 0 && p[x][y + 1] == 0 && p[x + 1][y] == 0) dfs(x + 1, y + 1, 3);
	}
}

int main() {
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) scanf("%d", &p[i][j]);
	}

	dfs(1, 2, 1);

	printf("%d\n", ans);
}