#include<stdio.h>
#include<limits.h>
#include<vector>
using namespace std;

class node {
public:
	int index;
	int val;
	node(int index, int val) {
		this->index = index;
		this->val = val;
	}
};

struct adj {
	int to;
	int val;
}ad;

vector<node> heap;
vector<adj> p[20001];

void swap(node& a, node& b) {
	node tmp = a;
	a = b;
	b = tmp;
	return;
}

void push_heap(node a) {
	heap.push_back(a);
	int now = heap.size() - 1;

	while (1) {
		if (now == 0) break;
		if (heap[(now - 1) / 2].val > heap[now].val) {
			swap(heap[(now - 1) / 2], heap[now]);
			now = (now - 1) / 2;
		}
		else break;
	}
	return;
}

void pop_heap() {
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	int now = 0;

	while (1) {
		if (now * 2 + 2 < heap.size()) {
			if (heap[now].val < heap[now * 2 + 1].val && heap[now].val < heap[now * 2 + 2].val) break;

			if (heap[now * 2 + 1].val < heap[now * 2 + 2].val) {
				swap(heap[now], heap[now * 2 + 1]);
				now = now * 2 + 1;
			}
			else {
				swap(heap[now], heap[now * 2 + 2]);
				now = now * 2 + 2;
			}
		}
		else if (now * 2 + 1 < heap.size()) {
			if (heap[now].val < heap[now * 2 + 1].val) break;

			swap(heap[now], heap[now * 2 + 1]);
			now = now * 2 + 1;
		}
		else break;
	}

	return;
}

int main() {
	int v, e;
	int n;
	int i, j;
	int t[20001] = { 0, };
	int visited[20001] = { 0, };

	scanf("%d %d", &v, &e);
	scanf("%d", &n);
	for (i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ad.to = b;
		ad.val = c;
		p[a].push_back(ad);
	}

	for (i = 1; i <= v; i++) t[i] = INT_MAX;
	t[n] = 0;

	for (i = 1; i <= v; i++) {
		push_heap(node(i, t[i]));
	}

	while(!heap.empty()) {
		node tmp = heap[0];

		if (visited[tmp.index] == 1) {
			pop_heap();
			continue;
		}
		
		if (heap.empty() || tmp.val == INT_MAX) break;

		visited[tmp.index] = 1;

		for (j = 0; j < p[tmp.index].size(); j++) {
			if (t[tmp.index] + p[tmp.index][j].val < t[p[tmp.index][j].to]) {
				t[p[tmp.index][j].to] = t[tmp.index] + p[tmp.index][j].val;
				push_heap(node(p[tmp.index][j].to, t[p[tmp.index][j].to]));
			}
		}

		pop_heap();
	}

	for (i = 1; i <= v; i++) {
		if (t[i] == INT_MAX) printf("INF\n");
		else printf("%d\n", t[i]);
	}
	return 0;
}
