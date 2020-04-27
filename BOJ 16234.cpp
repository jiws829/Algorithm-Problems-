/*
<16234 - 인구 이동>
먼저 flood fill로 국가들을 연합한다
연합하는 과정에서 각 연합국 별로 인구수와 나라수를 구해준다.
이것을 미리 구하지 않으면 시간초과가 난다.

이후 미리 구해둔 연합국 별 인구수/나라수로 새로운 인구수를 넣어준다

이 과정을 더이상 연합국이 없을때까지 반복해준다.
*/
#include<stdio.h>
#include<string.h>
#include<math.h>

int n, l, r;
int p[51][51], t[51][51];
int q[2502][2];
int count;

void dfs(int x, int y, int num) {
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int sum;

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i]>=n) continue;
		sum = abs(p[x][y]-p[x+dx[i]][y+dy[i]]);
		if (t[x+dx[i]][y+dy[i]]==0 && sum >= l && sum <= r) {
			t[x + dx[i]][y + dy[i]] = num;
			q[count][0] += p[x + dx[i]][y + dy[i]];
			q[count][1]++;
			dfs(x + dx[i], y + dy[i], num);
		}
	}
}

void uni() {
	int i, j;

	memset(t, 0, sizeof(t));
	memset(q, 0, sizeof(q));
	count = 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (t[i][j] == 0) {
				t[i][j] = count;
				q[count][0] += p[i][j];
				q[count][1]++;
				dfs(i, j, count);
				count++;
			}
		}
	}
}

void moving() {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			p[i][j] = q[t[i][j]][0] / q[t[i][j]][1];

		}
	}
}

int main() {
	int i, j;

	scanf("%d %d %d", &n, &l, &r);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) scanf("%d", &p[i][j]);
	}

	int ans = 0;
	while (1) {
		uni();

		if (count - 1 == n * n) break;

		moving();

		ans++;
	}
	printf("%d\n", ans);
}