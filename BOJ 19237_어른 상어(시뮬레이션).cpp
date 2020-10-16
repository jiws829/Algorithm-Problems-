#include<stdio.h>

int n, m, smell;
int dir[401];
struct sharks {
	int x, y;
	int dead;
}s[401];
int next[401][5][5];

struct dist {
	int num;
	int cnt;
}p[21][21];

int main() {
	//freopen("input.txt", "r", stdin);

	int i, j, k;
	int a;
	int answer = 0;
	int count;

	scanf("%d %d %d", &n, &m, &smell);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a);
			if (a > 0) { s[a].x = i; s[a].y = j; p[i][j].num = a; p[i][j].cnt = smell; }
		}
	}
	for (i = 1; i <= m; i++) scanf("%d", &dir[i]);
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= 4; j++) {
			for (k = 1; k <= 4; k++) scanf("%d", &next[i][j][k]);
		}
	}

	
	count = m;
	int next_dir, flag;
	while (1) {
		if (count == 1) break;

		answer++;
		if (answer > 1000) { answer = -1; break; }

		/*for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) printf("%d(%d) ", p[i][j].num, p[i][j].cnt);
			printf("\n");
		}*/


		//상어이동
		for (i = 1; i <= m; i++) {
			if (s[i].dead == 1) continue;

			flag = 0;

			//빈칸 찾기
			for (j = 1; j <= 4; j++) {
				next_dir = next[i][dir[i]][j];
				if (next_dir == 1 && s[i].x - 1 >= 1 && p[s[i].x - 1][s[i].y].num == 0) {
					dir[i] = next_dir;
					s[i].x--;
					flag = 1;
					break;
				}
				else if (next_dir == 2 && s[i].x + 1 <= n && p[s[i].x + 1][s[i].y].num == 0) {
					dir[i] = next_dir;
					s[i].x++;
					flag = 1;
					break;
				}
				else if (next_dir == 3 && s[i].y - 1 >= 1 && p[s[i].x][s[i].y - 1].num == 0) {
					dir[i] = next_dir;
					s[i].y--;
					flag = 1;
					break;
				}
				else if (next_dir == 4 && s[i].y + 1 <= n && p[s[i].x][s[i].y + 1].num == 0) {
					dir[i] = next_dir;
					s[i].y++;
					flag = 1;
					break;
				}
			}
			if (flag == 1) continue;
			

			//자신의 냄새가 있는 칸
			for (j = 1; j <= 4; j++) {
				next_dir = next[i][dir[i]][j];
				if (next_dir == 1 && s[i].x - 1 >= 1 && p[s[i].x - 1][s[i].y].num == i) {
					dir[i] = next_dir;
					s[i].x--;
					flag = 1;
					break;
				}
				else if (next_dir == 2 && s[i].x + 1 <= n && p[s[i].x + 1][s[i].y].num == i) {
					dir[i] = next_dir;
					s[i].x++;
					flag = 1;
					break;
				}
				else if (next_dir == 3 && s[i].y - 1 >= 1 && p[s[i].x][s[i].y - 1].num == i) {
					dir[i] = next_dir;
					s[i].y--;
					flag = 1;
					break;
				}
				else if (next_dir == 4 && s[i].y + 1 <= n && p[s[i].x][s[i].y + 1].num == i) {
					dir[i] = next_dir;
					s[i].y++;
					flag = 1;
					break;
				}
			}
		}

		/*printf("상어 이동후\n");
		for (i = 1; i <= m; i++) printf("%d %d  dead:%d\n", s[i].x, s[i].y, s[i].dead);
		printf("\n");*/


		//내쫓기
		for (i = m; i > 1; i--) {
			if (s[i].dead == 1) continue;
			for (j = i-1; j >= 1; j--) {
				if (s[j].dead == 1) continue;
				if (i == j) continue;
				if (s[i].x == s[j].x && s[i].y == s[j].y) {
					s[i].dead = 1;
					count--;
					break;
				}
			}
		}

		/*printf("상어 내쫓은후\n");
		for (i = 1; i <= m; i++) printf("%d %d  dead:%d\n", s[i].x, s[i].y, s[i].dead);
		printf("count: %d\n",count);
		printf("---------------------\n");*/

		//냄새 1감소
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (p[i][j].cnt > 0) {
					p[i][j].cnt--;
					if (p[i][j].cnt == 0) p[i][j].num = 0;
				}
			}
		}

		//냄새뿌리기
		for (i = 1; i <= m; i++) {
			if (s[i].dead == 1) continue;

			p[s[i].x][s[i].y].num = i;
			p[s[i].x][s[i].y].cnt = smell;
		}
	}

	printf("%d\n", answer);

}
