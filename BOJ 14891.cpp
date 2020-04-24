/*
<14891 - 톱니바퀴>
먼저 t 배열에 움직이게 된 바퀴에 방향을 저장한다
그 바퀴를 기준으로 왼쪽과 오른쪽으로 나가면서 회전해야할 경우 회전 방향을 기록해주고
더이상 회전하지 않으면 멈춘다

이후 회전방향에 맞게 회전을 다 마친 후, 점수를 계산한다.
*/
#include<cstdio>
#include<string.h>

int p[4][8];

int main() {
	char c[10];
	int i, j;
	int n, a, b;

	for (i = 0; i < 4; i++) {
		scanf("%s", c);

		for (j = 0; j < strlen(c); j++) {
			p[i][j] = c[j] - '0';
		}
	}
	scanf("%d", &n);
	for (int kk = 0; kk < n; kk++) {
		scanf("%d %d", &a, &b);
		a--;

		int t[4] = { 0, }; //움직이는 방향 1:시계  -1:반시계
		t[a] = b;
		for (i = a - 1; i >= 0; i--) {
			if (t[i + 1] == 0) break;
			if (p[i][2] != p[i + 1][6]) {
				if (t[i + 1] == 1) t[i] = -1;
				else t[i] = 1;
			}
		}
		for (i = a + 1; i < 4; i++) {
			if (t[i - 1] == 0) break;
			if (p[i - 1][2] != p[i][6]) {
				if (t[i - 1] == 1) t[i] = -1;
				else t[i] = 1;
			}
		}

		//지정된 방향으로 회전
		for (i = 0; i < 4; i++) {
			if (t[i] == 0) continue;

			if (t[i] == 1) {  //시계
				int tmp = p[i][7];
				for (j = 7; j >= 0; j--) p[i][j] = p[i][j - 1];
				p[i][0] = tmp;
			}
			else { //반시계
				int tmp = p[i][0];
				for (j = 0; j < 7; j++) p[i][j] = p[i][j + 1];
				p[i][7] = tmp;
			}
		}
	}

	int ans = p[0][0] + p[1][0]*2 + p[2][0]*4 + p[3][0]*8;

	printf("%d\n", ans);



}