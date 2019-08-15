#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind {
private:
	vi p, rank;
public:
	UnionFind(int n) {
		rank.assign(n, 0); p.resize(n);
		for(int i = 0; i < n; ++i) p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if(!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	int op, a, b;
	cin >> n >> m;
	UnionFind uf(n + 1);
	for(int i = 0; i < m; ++i) {
		cin >> op >> a >> b;
		if(op == 1) {
			if(uf.isSameSet(a, b)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			uf.unionSet(a, b);
		}
	}
	return 0;
}
