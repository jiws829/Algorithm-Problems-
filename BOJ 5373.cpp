/*
<5373 - 큐빙>
큐브를 각 상황에 맞게 돌려주면 된다.
단 뒷면이나 옆면을 회전할때는 뒤집혀서 바뀌게 되는 경우도 있는데
이를 고려하여 코딩해준다
*/
#include<stdio.h>

int n;
int p[6][3][3];
char ans[301][3];
int cnt;

void rotate(char x, char y) {
	int tmp[3];
	int t[3][3];
	int i, j;

	if (x == 'U') {
		if (y == '+') {
			for (i = 0; i < 3; i++) tmp[i] = p[2][0][i];
			for (i = 0; i < 3; i++) p[2][0][i] = p[5][0][i];
			for (i = 0; i < 3; i++) p[5][0][i] = p[3][0][i];
			for (i = 0; i < 3; i++) p[3][0][i] = p[4][0][i];
			for (i = 0; i < 3; i++) p[4][0][i] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[0][2 - j][i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[0][i][j] = t[i][j];
			}
		}
		if (y == '-') {
			for (i = 0; i < 3; i++) tmp[i] = p[2][0][i];
			for (i = 0; i < 3; i++) p[2][0][i] = p[4][0][i];
			for (i = 0; i < 3; i++) p[4][0][i] = p[3][0][i];
			for (i = 0; i < 3; i++) p[3][0][i] = p[5][0][i];
			for (i = 0; i < 3; i++) p[5][0][i] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[0][j][2 - i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[0][i][j] = t[i][j];
			}
		}
	}

	if (x == 'D') {
		if (y == '+') {
			for (i = 0; i < 3; i++) tmp[i] = p[2][2][i];
			for (i = 0; i < 3; i++) p[2][2][i] = p[4][2][i];
			for (i = 0; i < 3; i++) p[4][2][i] = p[3][2][i];
			for (i = 0; i < 3; i++) p[3][2][i] = p[5][2][i];
			for (i = 0; i < 3; i++) p[5][2][i] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[1][2 - j][i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[1][i][j] = t[i][j];
			}
		}
		if (y == '-') {
			for (i = 0; i < 3; i++) tmp[i] = p[2][2][i];
			for (i = 0; i < 3; i++) p[2][2][i] = p[5][2][i];
			for (i = 0; i < 3; i++) p[5][2][i] = p[3][2][i];
			for (i = 0; i < 3; i++) p[3][2][i] = p[4][2][i];
			for (i = 0; i < 3; i++) p[4][2][i] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[1][j][2 - i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[1][i][j] = t[i][j];
			}
		}
	}

	if (x == 'F') {
		if (y == '+') {
			for (i = 0; i < 3; i++) tmp[i] = p[0][2][i];
			for (i = 0; i < 3; i++) p[0][2][i] = p[4][2-i][2];
			for (i = 0; i < 3; i++) p[4][2-i][2] = p[1][0][2-i];
			for (i = 0; i < 3; i++) p[1][0][2-i] = p[5][i][0];
			for (i = 0; i < 3; i++) p[5][i][0] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[2][2 - j][i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[2][i][j] = t[i][j];
			}
		}
		if (y == '-') {
			for (i = 0; i < 3; i++) tmp[i] = p[0][2][i];
			for (i = 0; i < 3; i++) p[0][2][i] = p[5][i][0];
			for (i = 0; i < 3; i++) p[5][i][0] = p[1][0][2-i];
			for (i = 0; i < 3; i++) p[1][0][2-i] = p[4][2-i][2];
			for (i = 0; i < 3; i++) p[4][2-i][2] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[2][j][2 - i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[2][i][j] = t[i][j];
			}
		}
	}

	if (x == 'B') {
		if (y == '+') {
			for (i = 0; i < 3; i++) tmp[i] = p[0][0][i];
			for (i = 0; i < 3; i++) p[0][0][i] = p[5][i][2];
			for (i = 0; i < 3; i++) p[5][i][2] = p[1][2][2-i];
			for (i = 0; i < 3; i++) p[1][2][2-i] = p[4][2-i][0];
			for (i = 0; i < 3; i++) p[4][2-i][0] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[3][2 - j][i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[3][i][j] = t[i][j];
			}
		}
		if (y == '-') {
			for (i = 0; i < 3; i++) tmp[i] = p[0][0][i];
			for (i = 0; i < 3; i++) p[0][0][i] = p[4][2-i][0];
			for (i = 0; i < 3; i++) p[4][2-i][0] = p[1][2][2-i];
			for (i = 0; i < 3; i++) p[1][2][2-i] = p[5][i][2];
			for (i = 0; i < 3; i++) p[5][i][2] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[3][j][2 - i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[3][i][j] = t[i][j];
			}
		}
	}

	if (x == 'L') {
		if (y == '+') {
			for (i = 0; i < 3; i++) tmp[i] = p[0][i][0];
			for (i = 0; i < 3; i++) p[0][i][0] = p[3][2-i][2];
			for (i = 0; i < 3; i++) p[3][2-i][2] = p[1][i][0];
			for (i = 0; i < 3; i++) p[1][i][0] = p[2][i][0];
			for (i = 0; i < 3; i++) p[2][i][0] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[4][2 - j][i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[4][i][j] = t[i][j];
			}
		}
		if (y == '-') {
			for (i = 0; i < 3; i++) tmp[i] = p[0][i][0];
			for (i = 0; i < 3; i++) p[0][i][0] = p[2][i][0];
			for (i = 0; i < 3; i++) p[2][i][0] = p[1][i][0];
			for (i = 0; i < 3; i++) p[1][i][0] = p[3][2-i][2];
			for (i = 0; i < 3; i++) p[3][2-i][2] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[4][j][2 - i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[4][i][j] = t[i][j];
			}
		}
	}

	if (x == 'R') {
		if (y == '+') {
			for (i = 0; i < 3; i++) tmp[i] = p[0][i][2];
			for (i = 0; i < 3; i++) p[0][i][2] = p[2][i][2];
			for (i = 0; i < 3; i++) p[2][i][2] = p[1][i][2];
			for (i = 0; i < 3; i++) p[1][i][2] = p[3][2-i][0];
			for (i = 0; i < 3; i++) p[3][2-i][0] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[5][2 - j][i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[5][i][j] = t[i][j];
			}
		}
		if (y == '-') {
			for (i = 0; i < 3; i++) tmp[i] = p[0][i][2];
			for (i = 0; i < 3; i++) p[0][i][2] = p[3][2-i][0];
			for (i = 0; i < 3; i++) p[3][2-i][0] = p[1][i][2];
			for (i = 0; i < 3; i++) p[1][i][2] = p[2][i][2];
			for (i = 0; i < 3; i++) p[2][i][2] = tmp[i];

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) t[i][j] = p[5][j][2 - i];
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) p[5][i][j] = t[i][j];
			}
		}
	}
}

int main() {
	int m;
	int i, j, k;
	char c[3];

	scanf("%d", &n);

	while (n > 0) {
		n--;
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 3; j++) {
				for (k = 0; k < 3; k++) p[i][j][k] = i;
			}
		}

		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%s", c);

			rotate(c[0], c[1]);
		}
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (p[0][i][j] == 0) ans[cnt][j] = 'w';
				if (p[0][i][j] == 1) ans[cnt][j] = 'y';
				if (p[0][i][j] == 2) ans[cnt][j] = 'r';
				if (p[0][i][j] == 3) ans[cnt][j] = 'o';
				if (p[0][i][j] == 4) ans[cnt][j] = 'g';
				if (p[0][i][j] == 5) ans[cnt][j] = 'b';
			}
			cnt++;
		}
	}
	
	for (i = 0; i < cnt; i++) {
		for (j = 0; j < 3; j++) printf("%c", ans[i][j]);
		printf("\n");
	}

}