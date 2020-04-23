/*
<14889 - 스타트와 링크>
dfs로 스타트팀에 들어갈 구성원을 만들어주는데, 잘못하면 시간 초과가 뜨고 만다
잘 조절해서 dfs를 구현해야함

그후 스타트팀에 뽑히지 않은 사람들을 링크팀으로 분류하고
각 팀의 점수를 계산한 뒤 차이의 최소값을 구하면 된다.
*/
#include<stdio.h>

int n;
int p[21][21];
int t[11];
int minn = 2100000000;

void cal() {
	int i, j;
	int a, b;
	a = b = 0;

	//링크팀 구성
	int tt[11], check, cnt = 1;
	for (i = 1; i <= n; i++) {
		check = 0;
		for (j = 1; j <= n / 2; j++) {
			if (i == t[j]) { check = 1; break; }
		}
		if (check == 0) tt[cnt++] = i;
	}


	//스타트팀과 링크팀 점수합 계산
	for (i = 1; i <= n / 2; i++) {
		for (j = i + 1; j <= n / 2; j++) {
			a += p[t[i]][t[j]] + p[t[j]][t[i]];
			b += p[tt[i]][tt[j]] + p[tt[j]][tt[i]];
		}
	}

	if (a >= b) a -= b;
	else a = b - a;

	if (minn > a) minn = a;
}

void dfs(int v) {
	if (v == (n / 2) + 1) {
		cal();
		return;
	}
	for (int i = t[v - 1] + 1; i <= n; i++) {
		t[v] = i;
		dfs(v + 1);
		t[v] = 0;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);

	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) scanf("%d", &p[i][j]);
	}

	dfs(1);  //dfs로 팀 구성

	printf("%d\n", minn);
}