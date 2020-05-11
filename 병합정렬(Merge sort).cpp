#include<stdio.h>

void merge(int* p, int st, int mid, int en) {
	int i, j, k;
	int q[1001];

	i = st;
	j = mid + 1;
	k = st;

	while (i <= mid && j <= en) {
		if (p[i] <= p[j]) q[k++] = p[i++];
		else q[k++] = p[j++];
	}

	if (i > mid) {
		while (j <= en) q[k++] = p[j++];
	}
	else {
		while (i <= mid) q[k++] = p[i++];
	}

	for (i = st; i <= en; i++) p[i] = q[i];
}

void merge_sort(int *p, int st, int en) {
	if (st < en) {
		int mid = (st + en) / 2;
		merge_sort(p, st, mid);
		merge_sort(p, mid + 1, en);
		merge(p, st, mid, en);
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int n;
	int i;
	int p[1001];

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &p[i]);

	merge_sort(p, 0, n - 1);

	for (i = 0; i < n; i++) printf("%d ", p[i]);
}