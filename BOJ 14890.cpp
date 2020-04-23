/*
<14890 - 경사로>
먼저 가로방향을 본다.
바로 옆보다 낮은 점을 기준으로 한다.
만약 나보다 오른쪽이 한칸 높다면 나부터 왼쪽으로 경사로 크기만큼 보면서 나랑 같은지 or 이미 경사로를 놓은적이 있는지를 확인한다

이를 만족하지 못하거나 경사로를 둘만큼 충분히 공간이 남아있지 않다면 그 경우는 실패한 경우이다.

총 성공하는 경우의 수를 구한다.
*/
#include<stdio.h>

int n, m;
int p[102][102];
int t[101][102];

int main() {
	int i, j, k;
	int count = 0;
	int check;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) scanf("%d", &p[i][j]);
	}


	for (i = 1; i <= n; i++) {  //가로 방향 먼저
		check = 0;
		for (j = 1; j <= n; j++) {
			if (p[i][j] < p[i][j - 1]) { //이전칸이 나보다 높은 경우
				if (p[i][j - 1] - p[i][j] > 1) { check = 1; break; } //2칸보다 높음
				else { //1칸 높음
					for (k = j; k <= j + m - 1; k++) {
						if (k > n) { check = 1; break; }  //경사로 자리가 없음
						if (t[i][k] == 1 || p[i][j] != p[i][k]) { check = 1; break; }  //이미 경사로를 놓았거나 높이가 달라 경사로를 못 놓는 경우
						t[i][k] = 1;
					}

					if (check) break; //실패한 경우 더 이상 볼 필요 없이 넘어감
				}
			}

			if (p[i][j] < p[i][j + 1]) { //다음칸이 나보다 높은 경우
				if (p[i][j + 1] - p[i][j] > 1) { check = 1; break; } //2칸보다 높음
				else { //1칸 높음
					for (k = j; k >= j - m + 1; k--) {
						if (k < 1) { check = 1; break; }  //경사로 자리가 없음
						if (t[i][k] == 1 || p[i][j] != p[i][k]) { check = 1; break; }  //이미 경사로를 놓았거나 높이가 달라 경사로를 못 놓는 경우
						t[i][k] = 1;
					}

					if (check) break; //실패한 경우 더 이상 볼 필요 없이 넘어감
				}
			}
		}
		//printf("%d %d\n", i, check);
		if (check == 0) count++;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) t[i][j] = 0;
	}

	//세로방향
	for (j = 1; j <= n; j++) {
		check = 0;
		for (i = 1; i <= n; i++) {
			if (p[i][j] < p[i - 1][j]) { //이전칸이 나보다 높은 경우
				if (p[i - 1][j] - p[i][j] > 1) { check = 1; break; } //2칸보다 높음
				else { //1칸 높음
					for (k = i; k <= i + m - 1; k++) {
						if (k > n) { check = 1; break; }  //경사로 자리가 없음
						if (t[k][j] == 1 || p[i][j] != p[k][j]) { check = 1; break; }  //이미 경사로를 놓았거나 높이가 달라 경사로를 못 놓는 경우
						t[k][j] = 1;
					}

					if (check) break; //실패한 경우 더 이상 볼 필요 없이 넘어감
				}
			}

			if (p[i][j] < p[i + 1][j]) { //다음칸이 나보다 높은 경우
				if (p[i + 1][j] - p[i][j] > 1) { check = 1; break; } //2칸보다 높음
				else { //1칸 높음
					for (k = i; k >= i - m + 1; k--) {
						if (k < 1) { check = 1; break; }  //경사로 자리가 없음
						if (t[k][j] == 1 || p[i][j] != p[k][j]) { check = 1; break; }  //이미 경사로를 놓았거나 높이가 달라 경사로를 못 놓는 경우
						t[k][j] = 1;
					}

					if (check) break; //실패한 경우 더 이상 볼 필요 없이 넘어감
				}
			}
		}
		if (check == 0) count++;
	}


	printf("%d\n", count);
}