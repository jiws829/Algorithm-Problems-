/*
<17144 - 미세먼지 안녕!>
문제 조건대로
1. 미세먼지 확산
2. 공기청정기 작동을 반복해서 수행한 뒤

남은 미세먼지의 양을 합한 것을 출력하는 시뮬레이션 문제
*/
#include<iostream>
#include<string.h>
using namespace std;

int n, m, t;
int p[52][52];
int q[52][52];
int a, b;

int main() {
	int i, j, k;
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int cnt, tmp;
	int ans = 0;

	cin >> n >> m >> t;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> p[i][j];
			if (p[i][j] == -1) {
				if (a == 0) a = i;
				else b = i;
			}
		}
	}
	
	while (t > 0) {
		t--;

		memset(q, 0, sizeof(q));

		//확산
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (p[i][j] > 0) {
					cnt = 0;
					tmp = p[i][j] / 5;
					for (k = 0; k < 4; k++) {
						if (i + dx[k]<1 || i + dx[k]>n || j + dy[k]<1 || j + dy[k]>m || p[i + dx[k]][j + dy[k]] == -1) continue;
						cnt++;
						q[i + dx[k]][j + dy[k]] += tmp;
						
					}
					q[i][j] += p[i][j] - tmp * cnt;
					p[i][j] = 0;
				}
			}
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (p[i][j] != -1) p[i][j] = q[i][j];
			}
		}

		//공기청정기 작동
		//위
		for (i = a - 1; i > 1; i--) p[i][1] = p[i - 1][1];
		for (i = 1; i < m; i++) p[1][i] = p[1][i + 1];
		for (i = 1; i < a; i++) p[i][m] = p[i + 1][m];
		for (i = m; i > 1; i--) p[a][i] = p[a][i - 1];
		p[a][2] = 0;

		//아래
		for (i = b + 1; i < n; i++) p[i][1] = p[i + 1][1];
		for (i = 1; i < m; i++) p[n][i] = p[n][i + 1];
		for (i = n; i > b; i--) p[i][m] = p[i - 1][m];
		for (i = m; i > 1; i--) p[b][i] = p[b][i - 1];
		p[b][2] = 0;

	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (p[i][j] > 0) ans += p[i][j];
		}
	}
	cout << ans;
}
