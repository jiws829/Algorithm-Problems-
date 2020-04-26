/*
<15686 - 치킨 배달>
치킨집과 집의 위치를 각각 따로 저장해둔 후

전체 치킨집 중 m개의 치킨집을 선택해가며 도시 치킨거리의 최소값을 구해준다
*/
#include<stdio.h>
#include<math.h>

int n, m;
int p[51][51];
int t[14];

int house[101][2], cnt;
int chi[14][2], cn;
int minn = 2100000000;

void cal() {
	int i, j;

	int sum = 0;
	for (i = 0; i < cnt; i++) {
		int mi = 2100000000;
		for (j = 0; j < cn; j++) {
			if (t[j] == 1) {
				int a = abs(house[i][0] - chi[j][0]) + abs(house[i][1] - chi[j][1]);
				if (mi > a) mi = a;
			}
		}
		sum += mi;
	}
	if (minn > sum) minn = sum;
}

void dfs(int now, int count) {
	if (count == m) {
		cal();
		return;
	}
	for (int i = now; i < cn; i++) {
		if (t[i] == 0) {
			t[i] = 1;
			dfs(i + 1, count + 1);
			t[i] = 0;
		}
	}
}

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
			if (p[i][j] == 1) { house[cnt][0] = i; house[cnt++][1] = j; }
			else if (p[i][j] == 2) { chi[cn][0] = i; chi[cn++][1] = j; }
		}
	}

	dfs(0, 0);

	printf("%d\n", minn);
}