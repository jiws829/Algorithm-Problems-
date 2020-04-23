/*
<14503 - 로봇 청소기>
1. 현재 위치를 청소한다.
2. 현재 위치를 기준으로 4면 중 하나에 청소할 게 남았는지 확인한다.
만약 없다면 굳이 회전을 할 필요가 없다

3. 만약 4면 중 청소할게 없다면 후진을 하되, 후진을 할 곳이 벽이면 멈춘다.

4. 4면 중 청소할 곳이 있다면 왼쪽으로 회전하면서 청소할 곳을 찾아 그 곳으로 전진한다.

이 순서를 지켜가며 시뮬레이션하며 청소한 개수를 세면 정답이 나온다.
*/
#include<stdio.h>

int n, m;
int r, c, d;
int p[51][51];

int main() {
	int i, j;
	int count = 0;

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) scanf("%d", &p[i][j]);
	}

	while (1) {
		if (p[r][c] == 0) { count++; p[r][c] = 2; } //빈칸이면 청소한다. 후에 청소한 자리임을 2로 표시한다.

		if (p[r - 1][c] != 0 && p[r][c - 1] != 0 && p[r][c + 1] != 0 && p[r + 1][c] != 0) {  //4면이 벽이거나 이미 청소한 경우라면 회전할 필요가 없음
			if (d == 0) {  //북
				if (p[r + 1][c] == 1) break;
				else r++;
			}
			else if(d == 1) { //동
				if (p[r][c - 1] == 1) break;
				else c--;
			}
			else if (d == 2) { //남
				if (p[r - 1][c] == 1) break;
				else r--;
			}
			else { //서
				if (p[r][c + 1] == 1) break;
				else c++;
			}
		}
		else {  //청소할 공간이 하나라도 남아있다면 그 방향으로 갈때까지 왼쪽으로 회전
			if (d == 0) { //북
				if (p[r][c - 1] == 0) c--;
				d = 3;
			}
			else if (d == 1) { //동
				if (p[r - 1][c] == 0) r--;
				d = 0;
			}
			else if (d == 2) { //남
				if (p[r][c + 1] == 0) c++;
				d = 1;
			}
			else { //서
				if (p[r + 1][c] == 0) r++;
				d = 2;
			}
		}
	}
	printf("%d\n", count);
}