/*
<17779 - 게리맨더링2>
먼저 5번 선거구역의 위치를 정해준다.

맨 위의 좌표를 지정한 뒤, 각각 왼쪽과 오른쪽으로 얼마만큼 나갈건지 정해두면
선거구역을 정할 수 있다.

이후 각 선거구역별로 인구수를 구한 뒤 정렬을 해 최대값과 최소값을 빼주면 된다.
*/
#include<stdio.h>
#include<algorithm>
using namespace std;

int p[21][21];
int n;
int minn = 2100000000;

void per(int x, int y) {
	int a, b;
	int i, j;
	int sum[6] = { 0, };
	int left, right;
	int ll, rr;

	for (a = 1;; a++) {
		if (x + a > n || y - a < 0) break;
		
		for (b = 1;; b++) {
			sum[1] = sum[2] = sum[3] = sum[4] = sum[5] = 0;
			if (x + b > n || y + b > n || x + a + b > n || y - a + b > n || y - a + b < 0) break;

			for (i = 1; i < x; i++) {
				for (j = 1; j <= n; j++) {
					if (j <= y) sum[1] += p[i][j];
					else sum[2] += p[i][j];
				}
			}

			left = 1;
			right = 2;
			ll = rr = 0;
			for (i = x; i <= x + a + b; i++) {
				if (i == x + a) left = 3;

				for (j = 1; j < y- ll; j++) sum[left] += p[i][j];
				for (j = y - ll; j <= y + rr; j++) sum[5] += p[i][j];
				for (j = y + rr + 1; j <= n; j++) sum[right] += p[i][j];

				if (i >= x + b) { rr--; right = 4; }
				else rr++;
				if (i >= x + a) { ll--; }
				else ll++;
			}

			for (i = x + a + b + 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					if (j < y - a + b) sum[3] += p[i][j];
					else sum[4] += p[i][j];
				}
			}

			sort(sum + 1, sum + 6);

			if (minn > sum[5] - sum[1]) {
				minn = sum[5] - sum[1];
			}
		}
		
	}
}

int main() {
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) scanf("%d", &p[i][j]);
	}

	for (i = 1; i <= n - 2; i++) {
		for (j = 2; j <= n - 1; j++) {
			per(i, j);
		}
	}
	printf("%d\n", minn);
}