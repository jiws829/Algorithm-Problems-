/*
<17822 - 원판 돌리기>
입력조건에 따라

원판 돌리기 -> 원판 같은 수 찾아서 지우기 -> 같은 수 없을 경우 평균으로 숫자 바꾸기

를 진행하는 시뮬레이션 문제이다.
*/
#include<stdio.h>
#include<string.h>

int n, m, t;
int p[51][51];

int main() {
	int i, j, k;
	int a, b, c;
	int flag;
	int x, y;
	int same[51][51];

	scanf("%d %d %d", &n, &m, &t);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) scanf("%d", &p[i][j]);
	}
	for (k = 1; k <= t; k++) {
		scanf("%d %d %d", &a, &b, &c);

		//원판 돌리기
		for (i = 1; i <= n; i++) {
			if (i % a == 0) {
				int tmp[51] = { 0, }, cnt = 1;

				if (b == 0) {  //시계방향
					for (j = m - c + 1; j <= m; j++) tmp[cnt++] = p[i][j];
					for (j = 1; j < m - c + 1; j++) tmp[cnt++] = p[i][j];

					for (j = 1; j <= m; j++) p[i][j] = tmp[j];
				}
				else {  //반시계방향
					for (j = 1 + c; j <= m; j++) tmp[cnt++] = p[i][j];
					for (j = 1; j < 1 + c; j++) tmp[cnt++] = p[i][j];

					for (j = 1; j <= m; j++) p[i][j] = tmp[j];
				}
			}
		}

		//원판 합치기
		flag = 0;
		memset(same, 0, sizeof(same));
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (p[i][j] == -1) continue;
				x = i;
				y = j + 1;
				if (y > m) y = 1;
				if (p[i][j] == p[x][y]) same[i][j] = same[x][y] = 1;

				x = i;
				y = j - 1;
				if (y < 1) y = m;
				if (p[i][j] == p[x][y]) same[i][j] = same[x][y] = 1;

				x = i - 1;
				y = j;
				if (x >= 1 && p[i][j] == p[x][y]) same[i][j] = same[x][y] = 1;

				x = i + 1;
				y = j;
				if (x <= n && p[i][j] == p[x][y]) same[i][j] = same[x][y] = 1;
			}
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (same[i][j] == 1) {
					p[i][j] = -1;
					flag = 1;
				}
			}
		}

		if (flag == 0) { //합쳐진게 없으면 
			double sum=0;
			int cnt=0;
			for (i = 1; i <= n; i++) {	
				for (j = 1; j <= m; j++) {
					if (p[i][j] == -1) continue;
					sum += p[i][j];
					cnt++;
				}
			}
			sum /= (double)cnt;
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= m; j++) {
					if (p[i][j] == -1) continue;
					if (p[i][j] > sum) p[i][j]--;
					else if (p[i][j] < sum) p[i][j]++;
				}
			}
		}
	}
	int ans = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (p[i][j] != -1) ans += p[i][j];
		}
	}
	printf("%d\n", ans);
}