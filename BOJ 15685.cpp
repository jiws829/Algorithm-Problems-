/*
<15685 - 드래곤 커브>
입력을 받고 드래곤 커브 0세대 좌표를 먼저 벡터에 넣어준다.
이후 다음 세대로 넘어가는 방법은 다음과 같다. 맨 마지막에 생성된 좌표를 기준으로 늦게 생성된 좌표 순으로 90도 회전변환을 해주면 된다.
회전변환은 이 문제의 좌표가 뒤집혀 있어 반시계 90도가 이 문제의 시계방향 90도와 같게 된다.

이때는 좌표 범위를 넘어가더라도 모두 생성해서 벡터에 넣어준다. 예를 들어 2세대에서 좌표를 넘어가더라도 이게 3세대 때 좌표안으로 들어올 수 있다

세대 생성이 끝나면 좌표에 기억해주고 i,j 기준으로 i+1,j / i,j+1 / i+1,j+1 모두 체크가 되어있으면 count해준다
*/
#include<stdio.h>
#include<vector>
using namespace std;

int n;
int p[101][101];

struct pp {
	int x, y;
}tmp;

int main() {
	int i, j;
	int x, y, dir, g;
	int a, b, c, d;
	int e, f;
	vector<pp> dragon;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x, &y, &dir, &g);

		dragon.clear();
		tmp.x = x;
		tmp.y = y;
		dragon.push_back(tmp);

		if (dir == 0) tmp.x++;
		if (dir == 1) tmp.y--;
		if (dir == 2) tmp.x--;
		if (dir == 3) tmp.y++;

		dragon.push_back(tmp);

		while (g>0) {
			g--;
			int cnt = dragon.size() - 1;
			a = dragon[cnt].x;
			b = dragon[cnt].y;
			for (j = cnt - 1; j >= 0; j--) {
				c = dragon[j].x;
				d = dragon[j].y;

				e = a + b - d;
				f = c - a + b;
				tmp.x = e;
				tmp.y = f;
				dragon.push_back(tmp);
			}
		}
		for (j = 0; j < dragon.size(); j++) {
			if(dragon[j].x>=0 && dragon[j].x<=100 && dragon[j].y>=0 && dragon[j].y<=100) p[dragon[j].y][dragon[j].x] = 1;
		}
	}
	int count = 0;
	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++) {
			if (p[i][j] == 1 && p[i + 1][j] == 1 && p[i][j + 1] == 1 && p[i + 1][j + 1] == 1) {
				count++;
			}
		}
	}
	printf("%d\n", count);
}