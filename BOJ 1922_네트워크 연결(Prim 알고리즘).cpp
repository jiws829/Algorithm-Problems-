#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n, m;

vector<pair<int,int>> p[1001];
int visited[1001];

class lists {
public:
	int a, b, c;
	lists(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	void swap(lists &a, lists &b) {
		lists tmp = a;
		a = b;
		b = tmp;
	}
};
vector<lists> heap;

void addNode(int now, int i) {	
	heap.push_back(lists(now,p[now][i].first,p[now][i].second));

	int v = heap.size() - 1;

	while (v > 0) {
		if (heap[v].c < heap[(v - 1) / 2].c) {
			swap(heap[v], heap[(v - 1) / 2]);
			v = (v - 1) / 2;
		}
		else break;
	}
}

void popNode() {
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();

	int v = 0;
	while (1) {
		if (v * 2 + 2 < heap.size()) {
			if (heap[v].c < heap[v * 2 + 1].c && heap[v].c < heap[v * 2 + 2].c) break;
			else if (heap[v * 2 + 1].c < heap[v * 2 + 2].c) {
				swap(heap[v], heap[v * 2 + 1]);
				v = v * 2 + 1;
			}
			else {
				swap(heap[v], heap[v * 2 + 2]);
				v = v * 2 + 2;
			}
		}
		else if (v * 2 + 1 < heap.size()) {
			if (heap[v].c < heap[v * 2 + 1].c) break;
			else {
				swap(heap[v], heap[v * 2 + 1]);
				v = v * 2 + 1;
			}
		}
		else break;		
	}
}

int main() {
	int i;
	int answer = 0;
	int cnt = 0;

	cin >> n >> m;
	for (i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		p[a].push_back(make_pair(b, c));
		p[b].push_back(make_pair(a, c));
	}

	int now = 1;  //1번 노드를 시작점으로
	visited[1] = 1;
	cnt++;
	while (1) {
		if (cnt == n) break;

		for (i = 0; i < p[now].size(); i++) {
			addNode(now, i);
		}

		lists tmp = lists(0, 0, 0);
		while (1) {
			tmp = heap[0];
			popNode();

			if (visited[tmp.b] == 0) break;
		}

		answer += tmp.c;
		now = tmp.b;
		visited[now] = 1;
		cnt++;
	}

	cout << answer;
}