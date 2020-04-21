/*
<12100 - 2048 (Easy)>
2048은 최소 경우의수가 아니라 DFS로 길이가 5인 수열을 만들어 놓고
그 수열에 맞춰 보드를 움직이면서 움직인 직후 max 값을 찾고, 또 움직이고 max 값을 찾고를 반복함

보드를 움직일때는 움직이는 방향을 기준으로 줄마다 큐에 모두 넣고 큐에서 값을 빼내면서 확인하면 편리
*/
#include<stdio.h>
#include<vector>
using namespace std;

int n;
int p[21][21], t[21][21];
int dir[6];
int maxx = -999;

void move() {
	int i, j, k;
	int cnt;
	vector<int> a;

	for (k = 1; k <= 5; k++) {

		//왼쪽
		if (dir[k] == 1) {
			for (i = 1; i <= n; i++) {
				a.clear();
				for (j = 1; j <= n; j++) {
					if (t[i][j] == 0) continue;
					a.push_back(t[i][j]);
					t[i][j] = 0;
				}
				cnt = 1;
				while (!a.empty()) {
					if (a.size() == 1 || a[0] != a[1]) {
						t[i][cnt++] = a[0];
						a.erase(a.begin());
					}
					else {
						t[i][cnt++] = a[0] * 2;
						a.erase(a.begin(), a.begin() + 2);
					}
				}
			}
		}
		//오른쪽
		if (dir[k] == 2) {
			for (i = 1; i <= n; i++) {
				a.clear();
				for (j = n; j >= 1; j--) {
					if (t[i][j] == 0) continue;
					a.push_back(t[i][j]);
					t[i][j] = 0;
				}
				cnt = n;
				while (!a.empty()) {
					if (a.size() == 1 || a[0] != a[1]) {
						t[i][cnt--] = a[0];
						a.erase(a.begin());
					}
					else {
						t[i][cnt--] = a[0] * 2;
						a.erase(a.begin(), a.begin() + 2);
					}
				}
			}
		}

		//위쪽
		if (dir[k] == 3) {
			for (j = 1; j <= n; j++) {
				a.clear();
				for (i = 1; i <= n; i++) {
					if (t[i][j] == 0) continue;
					a.push_back(t[i][j]);
					t[i][j] = 0;
				}
				cnt = 1;
				while (!a.empty()) {
					if (a.size() == 1 || a[0] != a[1]) {
						t[cnt++][j] = a[0];
						a.erase(a.begin());
					}
					else {
						t[cnt++][j] = a[0] * 2;
						a.erase(a.begin(), a.begin() + 2);
					}
				}
			}
		}

		//아래쪽
		if (dir[k] == 4) {
			for (j = 1; j <= n; j++) {
				a.clear();
				for (i = n; i >= 1; i--) {
					if (t[i][j] == 0) continue;
					a.push_back(t[i][j]);
					t[i][j] = 0;
				}
				cnt = n;
				while (!a.empty()) {
					if (a.size() == 1 || a[0] != a[1]) {
						t[cnt--][j] = a[0];
						a.erase(a.begin());
					}
					else {
						t[cnt--][j] = a[0] * 2;
						a.erase(a.begin(), a.begin() + 2);
					}
				}
			}
		}

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (maxx < t[i][j]) maxx = t[i][j];
			}
		}
	}
}

void dfs(int num) {
	if (num == 6) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) t[i][j] = p[i][j];
		}
		move();
		return;
	}
	for (int i = 1; i <= 4; i++) {
		dir[num] = i;
		dfs(num + 1);
		dir[num] = 0;
	}
}

int main() {
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) scanf("%d", &p[i][j]);
	}

	dfs(1);

	printf("%d\n", maxx);
}