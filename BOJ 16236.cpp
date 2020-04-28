/*
<16236 - 아기 상어>
먼저 상어의 위치를 기억해둔다

이후 상어의 위치를 시작으로 bfs를 돌며 먹을 수 있는 물고기를 찾고
찾으면 먹고 상어가 그 위치로 가고
못 찾으면 그 상태에서 종료한 후 이동한 거리를 출력한다.
*/
#include<stdio.h>
#include<vector>
using namespace std;

int n;
int p[21][21];
int sx, sy, sz;
int ss;
int ans;
int finish;

void bfs() {
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int k;
	vector<int> x, y, z;
	int visited[21][21] = { 0, };
	int newx, newy, newz;
	newz = 0;

	x.push_back(sx);
	y.push_back(sy);
	z.push_back(0);
	visited[sx][sy] = 1;

	while (!x.empty()) {
		if (newz != 0 && z.front() != newz-1) {  //더이상 찾지 않아도 되는경우
			p[newx][newy] = 0;
			ss++;
			if (sz == ss) {
				sz++;
				ss = 0;
			}
			sx = newx;
			sy = newy;
			ans += newz;
			return;
		}
		
		for (k = 0; k < 4; k++) {
			if (x.front() + dx[k] < 0 || x.front() + dx[k] >= n || y.front() + dy[k] < 0 || y.front() + dy[k] >= n) continue;
			if (p[x.front() + dx[k]][y.front() + dy[k]] > sz || visited[x.front() + dx[k]][y.front() + dy[k]] ==1) continue;
			
			if (p[x.front() + dx[k]][y.front() + dy[k]]!=0 && p[x.front() + dx[k]][y.front() + dy[k]] < sz) {  //잡아먹을 수 있는 경우
				if (newz == 0) {
					newx = x.front() + dx[k];
					newy = y.front() + dy[k];
					newz = z.front() + 1;
				}
				else {
					if (x.front() + dx[k] < newx || (x.front() + dx[k] == newx && y.front() + dy[k] < newy)) {
						newx = x.front() + dx[k];
						newy = y.front() + dy[k];
						newz = z.front() + 1;
					}
				}
			}
			
			x.push_back(x.front() + dx[k]);
			y.push_back(y.front() + dy[k]);
			z.push_back(z.front() + 1);
			visited[x.front() + dx[k]][y.front() + dy[k]] = 1;			
		}
		x.erase(x.begin());
		y.erase(y.begin());
		z.erase(z.begin());
	}
	finish = 1;  // 더 이상 먹을게 없는 경우
	return;
}

int main() {
	

	int i, j;
	int flag;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
			if (p[i][j] == 9) { p[i][j] = 0; sx = i; sy = j; }
		}
	}

	sz = 2; //처음 상어 크기는 2

	while (1) {		
		bfs();

		if (finish) break;
	}

	printf("%d\n", ans);
}