/*
<15684 - 사다리 조작>
사다리를 움직이는 원리는 다음과 같다
시작은 1 2 3 4 5로 시작하는데 1과 2 사이를 연결하면
결과는 2 1 3 4 5로 바뀌게 된다
이를 위에서부터 순차적으로 시행하면 사다리결과값을 알수가 있게 된다

dfs로 사다리를 둘 수 있는 곳에 두면서 i번째가 i번째로 가는 경우가 완성되면 멈추면 된다
처음엔 사다리를 안놓고 그대로 확인해보고
다음부터 1개, 2개, 3개 순서로 모두 둬본다

그래도 없는 경우는 -1을 출력해준다
*/
#include<stdio.h>

int n, m, h;
int p[32][12];
int flag;

int check() {
	int t[11], i, j;
	int tmp;

	for (i = 1; i <= n; i++) t[i] = i;

	for (i = 1; i <= h; i++) {
		for (j = 1; j < n; j++) {
			if (p[i][j] >= 1) {
				tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
		}
	}

	for (i = 1; i <= n; i++) {
		if (t[i] != i) return 0;
	}
	return 1;
}

void dfs(int pos,int v) {
	if (flag) return;
	if (v == 0) {
		int ans = check();
		if (ans) flag = 1;

		return;
	}
	int i, a, b;

	for (i = pos + 1; i <= (n - 1) * h; i++) {
		a = ((i-1) / (n - 1)) + 1;
		b = ((i - 1) % (n - 1)) + 1;

		if (p[a][b] == 0 && p[a][b - 1] == 0 && p[a][b + 1] == 0) {
			p[a][b] = 2;
			dfs(i, v - 1);
			p[a][b] = 0;
		}
	}
}

int main() {
	int i, j;
	int a, b;

	scanf("%d %d %d", &n, &m, &h);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		p[a][b] = 1;
	}

	int ans=check();
	if (ans) {
		printf("0");
		return 0;
	}

	for (i = 1; i <= 3; i++) {
		dfs(0,i);
		if (flag) {
			printf("%d\n", i);
			return 0;
		}
	}
	if(flag==0) printf("-1\n");
}