/*
<17135 - 캐슬 디펜스>
먼저 완전탐색으로 궁수 3명을 배치하는 모든 경우의 수를 구한다

이후 정해진 궁수의 위치에 맞게
궁수에 공격할 적들을 탐지하고
적을 얼마나 없애는지 카운트하고
적이 한칸 아래로 내려오는 과정을 반복한다

모든 과정이 끝나고 적을 몇명 제거하는지 최대값을 출력하면 된다.
*/
#include<stdio.h>
#include<limits.h>
#include<vector>
#include<math.h>
using namespace std;


int p[16][16];
int t[16];
int n, m, d;
int maxx = INT_MIN;

void simulation() {
	int q[16][16];
	int i, j, k;
	int count = 0;  //죽인 적의 수
	vector<int> x, y; //궁수에게 공격당한 적의 좌표를 임시저장
	int a, b, minn;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			q[i][j] = p[i][j];
		}
	}

	for (int kk = 1; kk <= n; kk++) {
		
		//궁수 공격
		for (k = 1; k <= m; k++) {
			if (t[k] == 1) {
				minn = INT_MAX;
				for (i = 1; i <= n; i++) {
					for (j = 1; j <= m; j++) {
						if (q[i][j] == 1 && (n + 1 - i) + abs(k - j) <= d) {
							if (minn == (n + 1 - i) + abs(k - j) && j < b) { a = i; b = j; }
							if (minn > (n + 1 - i) + abs(k - j)) { minn = (n + 1 - i) + abs(k - j); a = i; b = j; }
						}
					}
				}
				if (minn != INT_MAX) {
					x.push_back(a);
					y.push_back(b);
				}
			}
		}
		
		//잡은 적 없애기
		while (!x.empty()) {
			if (q[x.front()][y.front()] == 1) {
				count++;
				q[x.front()][y.front()] = 0;
			}
			x.erase(x.begin());
			y.erase(y.begin());
		}

		//적 이동
		for (i = n; i > 1; i--) {
			for (j = 1; j <= m; j++) q[i][j] = q[i - 1][j];
		}
		for (j = 1; j <= m; j++) q[1][j] = 0;
	}

	if (maxx < count) maxx = count;
}

void per(int v, int num) {
	if (num==0) {
		simulation();

		return;
	}
	if (v > m) return;

	t[v] = 1;
	per(v + 1, num - 1);
	t[v] = 0;
	per(v + 1, num);
}

int main() {
	int i, j;

	scanf("%d %d %d", &n, &m, &d);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) scanf("%d", &p[i][j]);
	}

	per(1, 3);


	printf("%d\n", maxx);
}