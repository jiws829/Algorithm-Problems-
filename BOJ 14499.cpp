#include<stdio.h>

int n, m, x, y, k;
int p[21][21];  //����
int t[1001];   //�̵��ϴ� ���  1:��  2:��  3:��  4:��
int dice[7];  //�ֻ��� 1:��  2:��  3:����  4:��  5:��  6:�Ʒ�

int main() {
	int i, j;
	int tmp[7];

	//�Է�
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) scanf("%d", &p[i][j]);
	}
	for (i = 1; i <= k; i++) scanf("%d", &t[i]);

	for (int kk = 1; kk <= k; kk++) {
		for (i = 1; i <= 6; i++) tmp[i] = dice[i];

		if (t[kk] == 1) {  //��
			if (y + 1 > m - 1) continue;
			y++;
			tmp[3] = dice[1];
			tmp[6] = dice[3];
			tmp[4] = dice[6];
			tmp[1] = dice[4];
		}
		else if (t[kk] == 2) {  //��
			if (y - 1 < 0) continue;
			y--;
			tmp[4] = dice[1];
			tmp[6] = dice[4];
			tmp[3] = dice[6];
			tmp[1] = dice[3];
		}
		else if (t[kk] == 3) {  //��
			if (x - 1 < 0) continue;
			x--;
			tmp[2] = dice[1];
			tmp[6] = dice[2];
			tmp[5] = dice[6];
			tmp[1] = dice[5];
		}
		else {  //��
			if (x + 1 > n - 1) continue;
			x++;
			tmp[5] = dice[1];
			tmp[6] = dice[5];
			tmp[2] = dice[6];
			tmp[1] = dice[2];
		}


		if (p[x][y] == 0) p[x][y] = tmp[6];
		else { tmp[6] = p[x][y]; p[x][y] = 0; }
		printf("%d\n", tmp[1]);

		for (i = 1; i <= 6; i++) dice[i] = tmp[i];
	}

}