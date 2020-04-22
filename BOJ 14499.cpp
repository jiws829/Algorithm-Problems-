/*
<14499 - 주사위 굴리기>
주사위를 입력으로 주어진 방향대로 굴리면서 각 면을 잘 이동시켜주면 된다
이동 후 바닥면과 지도를 비교하며 값을 바꿔주면 됨
*/
#include<stdio.h>

int n, m, x, y, k;
int p[21][21];  //지도
int t[1001];   //이동하는 명령  1:동  2:서  3:북  4:남
int dice[7];  //주사위 1:윗  2:뒷  3:오른  4:왼  5:앞  6:아래

int main() {
	int i, j;
	int tmp[7];

	//입력
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) scanf("%d", &p[i][j]);
	}
	for (i = 1; i <= k; i++) scanf("%d", &t[i]);

	for (int kk = 1; kk <= k; kk++) {
		for (i = 1; i <= 6; i++) tmp[i] = dice[i];

		if (t[kk] == 1) {  //동
			if (y + 1 > m - 1) continue;
			y++;
			tmp[3] = dice[1];
			tmp[6] = dice[3];
			tmp[4] = dice[6];
			tmp[1] = dice[4];
		}
		else if (t[kk] == 2) {  //서
			if (y - 1 < 0) continue;
			y--;
			tmp[4] = dice[1];
			tmp[6] = dice[4];
			tmp[3] = dice[6];
			tmp[1] = dice[3];
		}
		else if (t[kk] == 3) {  //북
			if (x - 1 < 0) continue;
			x--;
			tmp[2] = dice[1];
			tmp[6] = dice[2];
			tmp[5] = dice[6];
			tmp[1] = dice[5];
		}
		else {  //남
			if (x + 1 > n - 1) continue;
			x++;
			tmp[5] = dice[1];
			tmp[6] = dice[5];
			tmp[2] = dice[6];
			tmp[1] = dice[2];
		}


		if (p[x][y] == 0) p[x][y] = tmp[6];
		else { tmp[6] = p[x][y]; p[x][y] = 0; }
		printf("%d\n", tmp[1]);

		for (i = 1; i <= 6; i++) dice[i] = tmp[i];
	}

}