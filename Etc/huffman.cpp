#include <iostream>
#include <concurrent_priority_queue.h>
#include <queue>
#include <vector>

using namespace std;

struct node {
	node *lchild;
	node *rchild;
	char symbol;
	int freq;

	node(node *l, node *r, char c, int rc) : lchild(l), rchild(r), symbol(c), freq(rc) {}
};

struct compare {
	bool operator()(const node& s1, const node& s2) {
		return s1.freq < s2.freq;
	}
};

priority_queue<node, vector<node>, compare> pq;

void init() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
}

node huffman(int n) {
	for (int i = 1; i <= n - 1; i++) {
		node least1 = pq.top();
		pq.pop();
		node least2 = pq.top();
		pq.pop();

		node pt = node(&least1, &least2, NULL, (least1.freq + least2.freq));
		pq.push(pt);
	}

	return pq.top();
}

int main() {
    init();

	int n = 6;

	pq.push(node(NULL, NULL, 'a', 16));
	pq.push(node(NULL, NULL, 'd', 17));
	pq.push(node(NULL, NULL, 'f', 25));
	pq.push(node(NULL, NULL, 'c', 12));
	pq.push(node(NULL, NULL, 'b', 5));
	pq.push(node(NULL, NULL, 'e', 10));

	node root = huffman(n);
	cout << root.freq << "\n";
}
