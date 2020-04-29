/*
<17825 - 주사위 윷놀이>
윷놀이판을 5가지 길로 분해해서 나눈다.

입력받은 10개의 턴을 4개의 말에 분배하는 것을 완전탐색으로 구현한다.
완전탐색으로 구현한 순서대로 말을 움직이되
말이 서로 겹치거나, 도착한 말을 움직이는 경우는 더이상 보지 않고 끝낸다.

5가지로 분해한 길이 서로 잘 연결되게 겹치는 부분만 신경써주고 도착한 지점의 값을 더해주면 된다.
*/
#include<stdio.h>

int p[10];
int turn[10];

int a[22] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0 };
int b[5] = { 10,13,16,19,25 };
int c[4] = { 20,22,24,25 };
int d[4] = { 30,28,27,26 };
int e[4] = { 25,30,35,40 };

int maxx = -999;

void moving() {
	int horse[5][3] = { 0, };
	int i, j;
	int now;
	int ans = 0;

	for (i = 1; i <= 4; i++) horse[i][1] = 1;

	for (i = 0; i < 10; i++) {
		now = turn[i];
		
		//이미 끝난 말을 움직이려는 경우도 더 보지 않고 끝냄
		if (horse[now][0] == 1) return;

		//말 이동
		horse[now][2] += p[i];

		//말 노선 변경
		if (horse[now][1] == 1 && horse[now][2] == 5) {
			horse[now][1] = 2;
			horse[now][2] = 0;
		}
		if (horse[now][1] == 1 && horse[now][2] == 10) {
			horse[now][1] = 3;
			horse[now][2] = 0;
		}
		if (horse[now][1] == 1 && horse[now][2] == 15) {
			horse[now][1] = 4;
			horse[now][2] = 0;
		}

		//2,3,4번 경로가 25번 교차로를 만난 이후
		if (horse[now][1] == 2 && horse[now][2] >= 4) {
			horse[now][1] = 5;
			horse[now][2] -= 4;
		}
		if (horse[now][1] == 3 && horse[now][2] >= 3) {
			horse[now][1] = 5;
			horse[now][2] -= 3;
		}
		if (horse[now][1] == 4 && horse[now][2] >= 4) {
			horse[now][1] = 5;
			horse[now][2] -= 4;
		}
		if (horse[now][1] == 5 && horse[now][2] >= 3) {
			horse[now][1] = 1;
			horse[now][2] += 17;
		}

		//말이 도착 지점을 넘어섰는가
		if (horse[now][1] == 1 && horse[now][2] >= 21) {
			horse[now][0] = 1; //끝남
		}

		//말이 겹치면 말이 안되는 경우의수이므로 끝냄
		if (horse[now][0] != 1) {
			for (j = 1; j <= 4; j++) {
				if (now == j) continue;
				if (horse[j][0] == 1) continue; //죽은 말은 볼 필요 없음

				if (horse[now][1] == horse[j][1] && horse[now][2] == horse[j][2]) return;
			}
		}
		

		if (horse[now][0] == 0) {
			if (horse[now][1] == 1) ans += a[horse[now][2]];
			else if (horse[now][1] == 2) ans += b[horse[now][2]];
			else if (horse[now][1] == 3) ans += c[horse[now][2]];
			else if (horse[now][1] == 4) ans += d[horse[now][2]];
			else if (horse[now][1] == 5) ans += e[horse[now][2]];
		}
	}
	
	if (maxx < ans) maxx = ans;
}

void per(int v) {
	if (v == 10) {
		moving();
		return;
	}
	for (int i = 1; i <= 4; i++) {
		turn[v] = i;
		per(v + 1);
	}
}

int main() {
	int i;

	for (i = 0; i < 10; i++) scanf("%d", &p[i]);

	per(0);

	printf("%d\n", maxx);
}