#include <bits/stdc++.h>
#define N 200
using namespace std;

typedef long long ll;

ll INF = 1e9;
ll n, m, s, t, ss, tt;
int n1, n2, r, b;
string lcolor, rcolor;

int cap[N][N];
int cost[N][N];

set<pair<int, int>> edges;

void add_edge(int fr, int to, int capacity, int _cost) {
	cap[fr][to] += capacity;
	cost[fr][to] = _cost;
	edges.insert({fr, to});
}

void add_range_cap_edge(int fr, int to, int l, int r) {
	add_edge(ss, to, l, 0);
	add_edge(fr, tt, l, 0);
	add_edge(fr, to, r - l, 0);
}

int bford() {
	vector<int> prev(n, -1);
	vector<vector<int>> d(n, vector<int>(n, 0));

	for (auto [fr, to] : edges) {

	}
}

int main() {
	cin >> n1 >> n2 >> m >> r >> b ;
	cin >> lcolor >> rcolor;
	for (int i = 0; i <m; i++) {
		int fr, to;
		cin >> fr >> to;
		fr++; to++;
		to += n1;

		add_edge(fr, to, 1, b);
		add_edge(to, fr, 1, r);
	}
	
	ss = 0;
	s = 1;
	t = n1 + n2 + 2;
	tt = t + 1;
	n = tt + 1;

	// left side
	for (int i = 0; i < n1; i++) {
	    int u = i + 2;
		if (lcolor[i] == 'B') {
			add_range_cap_edge(s, u, 1, N);
		} else if (lcolor[i] == 'R') {
			add_range_cap_edge(u, t, 1, N);
		} else {
			add_edge(s, u, N, 0);
			add_edge(u, t, N, 0);
		}
	}
	
	// right side
	for (int i = 0; i < n2; i++) {
	    int u = n1 + 1;
		if (rcolor[i] == 'R') {
			add_range_cap_edge(s, u, 1, N);
		} else if (rcolor[i] == 'B') {
			add_range_cap_edge(u, t, 1, N);
		} else {
			add_edge(s, u, N, 0);
			add_edge(u, t, N, 0);
		}
	}

	add_edge(s, t, INF, 0);
	
	int cost = 0;
	int new_cost = 0;
	// shortest path flow increases
	while ((new_cost = bford())) {
		cost += new_cost;
	}
	
	// cout << cost << endl;
	
	// reconstruct an print the solution
	// for (int i = 0; i < m; i++) {
	// 	int [fr, to] = edges[i];
	// }
	
	return 0;
}
