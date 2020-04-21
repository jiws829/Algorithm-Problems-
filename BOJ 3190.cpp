#include<stdio.h>
#include<vector>
using namespace std;

int n, m, l;
int p[101][101];
int t[101][3], cnt = 1;
struct str_snake {
	int x, y;
	int dir;
}tmp;
vector<str_snake> snake, s;


int main() {
	int i, k;
	int a, b;
	char c;
	int check;//부딪혔는지 확인하는 변수

	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		p[a][b] = 2; //사과 위치는 2로 표시
	}
	scanf("%d", &l);
	for (i = 1; i <= l; i++) {
		scanf("%d %c", &t[i][1], &c);
		if (c == 'D') t[i][2] = 1;
		else t[i][2] = 2;
	}

	tmp.x = tmp.y = tmp.dir = 1;
	snake.push_back(tmp);

	for (k = 1;; k++) {

		//이동
		if (snake[0].dir == 1) {
			tmp.x = snake[0].x;
			tmp.y = snake[0].y + 1;
			tmp.dir = snake[0].dir;
		}
		else if (snake[0].dir == 2) {
			tmp.x = snake[0].x + 1;
			tmp.y = snake[0].y;
			tmp.dir = snake[0].dir;
		}
		else if (snake[0].dir == 3) {
			tmp.x = snake[0].x;
			tmp.y = snake[0].y - 1;
			tmp.dir = snake[0].dir;
		}
		else if (snake[0].dir == 4) {
			tmp.x = snake[0].x - 1;
			tmp.y = snake[0].y;
			tmp.dir = snake[0].dir;
		}
		
		//부딪혔는지 확인
		check = 0;
		if (tmp.x<1 || tmp.x>n || tmp.y<1 || tmp.y>n) break;
		for (i = 0; i < snake.size(); i++) {
			if (tmp.x == snake[i].x && tmp.y == snake[i].y) { check = 1; break; }
		}
		if (check) break;

		//방향 변경시
		if (k == t[cnt][1]) {
			if (t[cnt][2] == 1) {
				tmp.dir++;
				if (tmp.dir == 5) tmp.dir = 1;
			}
			else {
				tmp.dir--;
				if (tmp.dir == 0) tmp.dir = 4;
			}
			cnt++;
		}

		//뱀 꼬리 자를지 말지
		if (p[tmp.x][tmp.y] == 2) { //사과 먹었을때
			snake.insert(snake.begin(), tmp);
			p[tmp.x][tmp.y] = 0;
		}
		else {
			snake.insert(snake.begin(), tmp);
			snake.pop_back();
		}
	}

	printf("%d\n", k);
}