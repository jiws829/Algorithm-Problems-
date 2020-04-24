/*
<15683 - 감시>
먼저 CCTV의 위치를 배열 t에 저장해둔다
dfs로 각 CCTV의 방향을 설정해주고

설정된 방향으로 생기는 사각지대를 계산해준다
먼저 1 cctv의 방향을 설정해주고
cctv 2,3,4,5 모두 1을 합친 기능을 하는것이기 때문에 융합해서 사용하는 느낌으로
사각지대 범위를 계산해주었다.
*/
#include<stdio.h>

int n, m;
int p[9][9],q[9][9];
int t[65][3], cnt = 0;
int minn = 2100000000;

void check() {
	
	int i, j, k;
	int x, y, z;
	int dx[5] = { 0,-1,0,0,1 }, dy[5] = { 0,0,-1,1,0 };
	int dir;

	int two[3][3] = { {},{0,1,4},{0,2,3} };
	int three[5][3] = { {},{0,1,2},{0,1,3},{0,2,4},{0,3,4} };
	int four[5][4] = { {},{0,2,3,4},{0,1,3,4},{0,1,2,4},{0,1,2,3} };
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) q[i][j] = p[i][j];
	}
	
	for (i = 0; i < cnt; i++) {
		x = t[i][0];
		y = t[i][1];
		

		if (p[x][y] == 1) {  //1번 로봇
			dir = t[i][2];
			for (k = 1;; k++) {
				if (x + k * dx[dir] < 0 || x + k * dx[dir] >= n || y + k * dy[dir] < 0 || y + k * dy[dir] >= m || q[x + k * dx[dir]][y + k * dy[dir]] == 6) break;
				if (q[x + k * dx[dir]][y + k * dy[dir]] == 0) q[x + k * dx[dir]][y + k * dy[dir]] = -1;
			}
		}
		else if (p[x][y] == 2) {  //2번 로봇
			for (j = 1; j <= 2; j++) {
				dir = two[t[i][2]][j];
			
				for (k = 1;; k++) {
					if (x + k * dx[dir] < 0 || x + k * dx[dir] >= n || y + k * dy[dir] < 0 || y + k * dy[dir] >= m || q[x + k * dx[dir]][y + k * dy[dir]] == 6) break;
					if (q[x + k * dx[dir]][y + k * dy[dir]] == 0) q[x + k * dx[dir]][y + k * dy[dir]] = -1;
				}
			}
		}
		else if (p[x][y] == 3) {      //3번 로봇
			for (j = 1; j <= 2; j++) {
				dir = three[t[i][2]][j];
				for (k = 1;; k++) {
					if (x + k * dx[dir] < 0 || x + k * dx[dir] >= n || y + k * dy[dir] < 0 || y + k * dy[dir] >= m || q[x + k * dx[dir]][y + k * dy[dir]] == 6) break;
					if (q[x + k * dx[dir]][y + k * dy[dir]] == 0) q[x + k * dx[dir]][y + k * dy[dir]] = -1;
				}
			}
		}
		else if (p[x][y] == 4) {        //4번 로봇
			for (j = 1; j <= 3; j++) {
				dir = four[t[i][2]][j];
				for (k = 1;; k++) {
					if (x + k * dx[dir] < 0 || x + k * dx[dir] >= n || y + k * dy[dir] < 0 || y + k * dy[dir] >= m || q[x + k * dx[dir]][y + k * dy[dir]] == 6) break;
					if (q[x + k * dx[dir]][y + k * dy[dir]] == 0) q[x + k * dx[dir]][y + k * dy[dir]] = -1;
				}
			}
		}
		else if(p[x][y] == 5) {  //5번 로봇
			for (j = 1; j <= 4; j++) {
				dir = j;
				for (k = 1;; k++) {
					if (x + k * dx[dir] < 0 || x + k * dx[dir] >= n || y + k * dy[dir] < 0 || y + k * dy[dir] >= m || q[x + k * dx[dir]][y + k * dy[dir]] == 6) break;
					if (q[x + k * dx[dir]][y + k * dy[dir]] == 0) q[x + k * dx[dir]][y + k * dy[dir]] = -1;
				}
			}
		}
	}

	int count = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (q[i][j] == 0) count++;
		}
	}
	if (minn > count) minn = count;
}

void dfs(int v) {
	if (v == cnt) {
		check();
		return;
	}
	int i;
	if (p[t[v][0]][t[v][1]] == 1 || p[t[v][0]][t[v][1]] == 3 || p[t[v][0]][t[v][1]] == 4) {
		for (i = 1; i <= 4; i++) {
			t[v][2] = i;
			dfs(v + 1);
			t[v][2] = 0;
		}
	}
	else if (p[t[v][0]][t[v][1]] == 2) {
		for (i = 1; i <= 2; i++) {
			t[v][2] = i;
			dfs(v + 1);
			t[v][2] = 0;
		}
	}
	else {
		t[v][2] = 1;
		dfs(v + 1);
		t[v][2] = 0;
	}
}

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &p[i][j]);
			if (p[i][j] >= 1 && p[i][j] <= 5) { //로봇의 정보만 따로 빼둠
				t[cnt][0] = i;
				t[cnt++][1] = j;
			}
		}
	}

	//dfs로 로봇 방향 설정해줌
	dfs(0);

	printf("%d\n", minn);
}