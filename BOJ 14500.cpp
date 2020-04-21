#include<stdio.h>

int n, m;
int p[501][501];
int maxx = -999;

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) scanf("%d", &p[i][j]);
	}

	int sum;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {

			if (j + 3 <= m) sum = p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i][j + 3]; //1
			if (maxx < sum) maxx = sum;


			if (i + 3 <= n) sum = p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 3][j]; //2
			if (maxx < sum) maxx = sum;

			if (i + 1 <= n && j + 1 <= m) sum = p[i][j] + p[i + 1][j] + p[i][j + 1] + p[i + 1][j + 1];  //3
			if (maxx < sum) maxx = sum;

			if (i + 2 <= n && j + 1 <= m) {
				sum = p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 2][j + 1];//4
				if (maxx < sum) maxx = sum;
				sum = p[i][j] + p[i][j + 1] + p[i + 1][j + 1] + p[i + 2][j + 1];//6
				if (maxx < sum) maxx = sum;
				sum = p[i][j + 1] + p[i + 1][j + 1] + p[i + 2][j] + p[i + 2][j + 1];//8
				if (maxx < sum) maxx = sum;
				sum = p[i][j] + p[i][j + 1] + p[i + 1][j] + p[i + 2][j];//10
				if (maxx < sum) maxx = sum;
				sum = p[i][j] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 2][j + 1];//12
				if (maxx < sum) maxx = sum;
				sum = p[i][j + 1] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 2][j];//14
				if (maxx < sum) maxx = sum;
				sum = p[i][j] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 2][j];//17
				if (maxx < sum) maxx = sum;
				sum = p[i][j + 1] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 2][j + 1];//19
				if (maxx < sum) maxx = sum;
			}

			if (i + 1 <= n && j + 2 <= m) {
				sum = p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j];//5
				if (maxx < sum) maxx = sum;
				sum = p[i][j + 2] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2];//7
				if (maxx < sum) maxx = sum;
				sum = p[i][j] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2];//9
				if (maxx < sum) maxx = sum;
				sum = p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j + 2];//11
				if (maxx < sum) maxx = sum;
				sum = p[i][j + 1] + p[i][j + 2] + p[i + 1][j] + p[i + 1][j + 1];//13
				if (maxx < sum) maxx = sum;
				sum = p[i][j] + p[i][j + 1] + p[i + 1][j + 1] + p[i + 1][j + 2];//15
				if (maxx < sum) maxx = sum;
				sum = p[i][j + 1] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2];//16
				if (maxx < sum) maxx = sum;
				sum = p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j + 1];//18
				if (maxx < sum) maxx = sum;
			}
		}
	}
	printf("%d\n", maxx);
}