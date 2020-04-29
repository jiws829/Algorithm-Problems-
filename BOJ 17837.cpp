/*
<17837 - 새로운 게임2>
체스 말판을 순서대로 이동한다.
만약 벽이나 파란칸을 만나고 반대방향인 경우 이동하지 않고 방향만 바꾼다

그 외에는 그 말이 무조건 움직이게 된다.
만약 움직이는 경우 그 말부터 위에 쌓인 말들은 다시 순서대로 움직인 좌표의 vector에 쌓고
모두 움직인 좌표로 바꿔준다.

만약 빨간칸으로 이동한 경우는 좌표의 vector에 반대로 쌓아준다.
*/
#include<stdio.h>
#include<vector>
using namespace std;

int n, m;
int p[13][13];
struct horses {
	int x, y, dir;
}horse[11];

vector<int> q[13][13];

int main() {
	int i, j, k;
	int ans = 0;
	int check = 0;
	int x, y;
	int flag;
	vector<int> tmp;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) scanf("%d", &p[i][j]);
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &horse[i].x, &horse[i].y, &horse[i].dir);
		q[horse[i].x][horse[i].y].push_back(i);
	}

	
	while (1) {
		if (ans > 1000) { ans = -1; break; }
		
		//말이 4칸 모였는지 확인
		for (i = 1; i <= n; i++) {
			if (check) break;
			for (j = 1; j <= n; j++) {
				if (q[i][j].size() >= 4) { check = 1; break; }
			}
		}
		if (check) break;
		
		ans++;

		for (i = 1; i <= m; i++) {
			x = horse[i].x;
			y = horse[i].y;

			//말 이동(파란색칸이면 반대로 이동
			if (horse[i].dir == 1) {
				if (p[x][y + 1] == 2 || y + 1 > n) {
					horse[i].dir = 2;
					if (y - 1 >= 1 && p[x][y - 1] != 2) y--;
				}
				else y++;
			}
			else if (horse[i].dir == 2) {
				if (p[x][y - 1] == 2 || y - 1 < 1) {
					horse[i].dir = 1;
					if (y + 1 <= n && p[x][y + 1] != 2) y++;
				}
				else y--;
			}
			else if (horse[i].dir == 3) {
				if (p[x - 1][y] == 2 || x - 1 < 1) {
					horse[i].dir = 4;
					if (x + 1 <= n && p[x + 1][y] != 2) x++;
				}
				else x--;
			}
			else {
				if (p[x + 1][y] == 2 || x + 1 > n) {
					horse[i].dir = 3;
					if (x - 1 >= 1 && p[x - 1][y] != 2) x--;
				}
				else x++;
			}

			if (x != horse[i].x || y != horse[i].y) {  //이동한 경우만 빨간색 칸인지 흰색 칸인지 고려
				//쌓인 애들 같이 이동
				flag = 0;
				tmp.clear();
				for (k = 0; k < q[horse[i].x][horse[i].y].size(); ) {
					if (q[horse[i].x][horse[i].y][k] == i) flag = 1;

					if (flag == 1) {
						tmp.push_back(q[horse[i].x][horse[i].y][k]);
						q[horse[i].x][horse[i].y].erase(q[horse[i].x][horse[i].y].begin() + k);
					}
					else k++;
				}

				if (p[x][y] == 0) {  //옮기는 칸이 흰색인 경우
					while (!tmp.empty()) {
						q[x][y].push_back(tmp.front());
						horse[tmp.front()].x = x;
						horse[tmp.front()].y = y;
						tmp.erase(tmp.begin());
					}
				}
				else { //옮기는 칸이 빨간색인 경우
					while (!tmp.empty()) {
						q[x][y].push_back(tmp.back());
						horse[tmp.back()].x = x;
						horse[tmp.back()].y = y;
						tmp.pop_back();
					}
				}
			}
			if (q[x][y].size() >= 4) { check = 1; break; }
		}

	}

	printf("%d\n", ans);
}