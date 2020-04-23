/*
<14502- 연구소>
dfs로 벽 3개를 생성할 수 있는 모든 경우의 수를 만든다

이후 벽 3개가 생성될때마다 바이러스를 모두 flood_fill로 퍼뜨린다
모든 바이러스가 다 퍼지고 안전영역의 개수를 세어 최대값을 갱신해준다.
*/
#include<stdio.h>

int n, m;
int p[9][9];
int t[9][9];
int maxx = -999;

void flood(int x, int y) {  //dfs로 인근지역 바이러스로 변환
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int i;

	for (i = 0; i < 4; i++) {
		if (x + dx[i] > n || x + dx[i] < 1 || y + dy[i] > m || y + dy[i] < 1) continue;

		if(t[x + dx[i]][y + dy[i]] == 0 || t[x + dx[i]][y + dy[i]] == 2) {
			t[x + dx[i]][y + dy[i]] = -1;
			flood(x + dx[i], y + dy[i]);
		}
	}
}

void virus() {
	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) t[i][j] = p[i][j];
	}
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (t[i][j] == 2) {  //바이러스가 발견되면 그 점부터 flood fill로 인근지역 바이러스로 바꿔줌
				t[i][j] = -1;
				flood(i, j);
			}
		}
	}
	int cnt = 0;
	for (i = 1; i <= n; i++) {  //안전영역 개수
		for (j = 1; j <= m; j++) {
			if (t[i][j] == 0) cnt++;
		}
	}
	if (maxx < cnt) {  //안전영역 최대개수 갱신
		maxx = cnt;
	}
}

void dfs(int v) {
	int i, j;

	if (v == 3) {  //벽 3개가 다 생성된 경우
		virus();
		return;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (p[i][j] == 0) {
				p[i][j] = 1;
				dfs(v + 1);
				p[i][j] = 0;
			}
		}
	}
}

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) scanf("%d", &p[i][j]);
	}

	dfs(0);  //dfs로 벽 생성

	printf("%d\n", maxx);
}