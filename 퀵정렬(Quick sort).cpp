#include<stdio.h>

void quick_sort(int* p, int st, int en) {
	if (st >= en) return;  //원소가 1개인 경우

	int pivot = st;
	int i = pivot + 1;
	int j = en;
	int tmp;

	while (i <= j) {
		while (i <= en && p[i] <= p[pivot]) i++;
		while (j > st&& p[pivot] <= p[j]) j--;

		if (i > j) {
			tmp = p[j];
			p[j] = p[pivot];
			p[pivot] = tmp;
		}
		else {
			tmp = p[i];
			p[i] = p[j];
			p[j] = tmp;
		}
	}

	quick_sort(p, st, j - 1);
	quick_sort(p, j + 1, en);
}

int main() {
	freopen("input.txt", "r", stdin);

	int n;
	int i;
	int p[1001];

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &p[i]);

	quick_sort(p, 0, n - 1);

	for (i = 0; i < n; i++) printf("%d ", p[i]);
}