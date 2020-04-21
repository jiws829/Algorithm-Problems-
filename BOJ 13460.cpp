#include<stdio.h>
#include<vector>
using namespace std;

int p[11][11];
int visited[11][11][11][11];
int n, m;
int rx, ry, bx, by;

struct str_ball {
	int a, b, c, d;
	int num;
}tmp;
vector<str_ball> ball;

int bfs() {
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int i, j, k;
	int aa, bb, cc, dd;
	int check;

	tmp.a = rx;
	tmp.b = ry;
	tmp.c = bx;
	tmp.d = by;
	tmp.num = 1;
	visited[rx][ry][bx][by] = 1;
	ball.push_back(tmp);

	while (!ball.empty()) {
		if (ball.front().num > 10) return -1;

		for (i = 0; i < 4; i++) {
			aa = ball.front().a;
			bb = ball.front().b;
			cc = ball.front().c;
			dd = ball.front().d;
			check = 0;

			//1 빨간공이 먼저 움직임
			for (j = 1;; j++) {
				if (p[aa + j * dx[i]][bb + j * dy[i]] == 4) { check = 1; break; }
				if ((aa + j * dx[i] == cc && bb + j * dy[i] == dd) || p[aa + j * dx[i]][bb + j * dy[i]] == -1) { j--; break; }
			}
			aa = aa + j * dx[i];
			bb = bb + j * dy[i];

			//2 파란공이 움직임
			for (k = 1;; k++) {
				if (p[cc + k * dx[i]][dd + k * dy[i]] == 4) { check = 2; break; }
				if ((cc + k * dx[i] == aa && dd + k * dy[i] == bb) || p[cc + k * dx[i]][dd + k * dy[i]] == -1) { k--; break; }
			}
			cc = cc + k * dx[i];
			dd = dd + k * dy[i];

			if (check == 2) continue; //실패한 경우

			//3 빨간공 더 움직일 수 있으면 움직임
			for (j = 1;; j++) {
				if (p[aa + j * dx[i]][bb + j * dy[i]] == 4) { check = 1; break; }
				if ((aa + j * dx[i] == cc && bb + j * dy[i] == dd) || p[aa + j * dx[i]][bb + j * dy[i]] == -1) { j--; break; }
			}
			aa = aa + j * dx[i];
			bb = bb + j * dy[i];

			if (check == 1) { //성공한 경우
				return ball.front().num;
			}

			//안끝날 경우
			if (visited[aa][bb][cc][dd] == 0) {
				visited[aa][bb][cc][dd] = 1;
				tmp.a = aa;
				tmp.b = bb;
				tmp.c = cc;
				tmp.d = dd;
				tmp.num = ball.front().num + 1;
				ball.push_back(tmp);
			}
		}

		ball.erase(ball.begin());
	}
	return -1;
}

int main() {
	int i, j;
	char c[12];

	//입력
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%s", c);

		for (j = 0; j < m; j++) {
			if (c[j] == '.') p[i][j + 1] = 0;
			else if (c[j] == '#') p[i][j + 1] = -1;
			else if (c[j] == 'R') { rx = i; ry = j + 1; }
			else if (c[j] == 'B') { bx = i; by = j + 1; }
			else if (c[j] == 'O') p[i][j + 1] = 4;
		}
	}


	int ans = bfs();

	printf("%d\n", ans);


}