#include <iostream>
#include <concurrent_priority_queue.h>
#include <queue>
#include <vector>

using namespace std;

struct node {
	node *lchild;
	node *rchild;
	int record;

	node(node *l, node *r, int rc) : lchild(l), rchild(r), record(rc) {}
};

struct compare {
	bool operator()(const node& s1, const node& s2) {
		return s1.record < s2.record;
	}
};

priority_queue<node, vector<node>, compare> pq;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

node Tree(int n) {
	for (int i = 1; i <= n - 1; i++) {
		node least1 = pq.top();
		pq.pop();
		node least2 = pq.top();
		pq.pop();

		node pt = node(&least1, &least2, (least1.record + least2.record));
		pq.push(pt);
	}

	return pq.top();
}

int main() {
    init();

	int n = 6;

	pq.push(node(NULL, NULL, 2));
	pq.push(node(NULL, NULL, 3));
	pq.push(node(NULL, NULL, 5));
	pq.push(node(NULL, NULL, 7));
	pq.push(node(NULL, NULL, 9));
	pq.push(node(NULL, NULL, 13));

	node root = Tree(n);
	cout << root.record << "\n";
}
