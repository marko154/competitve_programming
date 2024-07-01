#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll INF = 1e9;

vector<vector<int>> adj;
vector<vector<int>> cap;
vector<int> parent;

int total;

int bfs(int src, int sink) {
	queue<pair<int, int>> q;
	q.push({src, INF});
	parent.assign(total, -1);
	parent[src] = -2;

	while (!q.empty()) {
		auto [v, flow_to_v] = q.front(); q.pop();
		if (v == sink) {
			return flow_to_v;
		}
		for (int out : adj[v]) {
			if (parent[out] == -1 && cap[v][out]>  0) {
				q.push({out, min(flow_to_v, cap[v][out])});
				parent[out] = v;
			}
		}
	}
	return 0;
}


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	int src = 0;
	// boys = 1, .., n
	// girls = n + 1, .., n + m
	int sink = n + m + 1;
	total = sink + 1;
	
	adj.resize(sink);
	cap.assign(total, vector<int>(total, 0));
	for (int i = 1; i <= n; i++) {
		cap[src][i] = 1;
		adj[src].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		cap[n + i][sink] = 1;
		adj[n + i].push_back(sink);
	}

	for (int i = 0; i < k; i++) {
		int fr, to;
		cin >> fr >> to;
		to += n;
		adj[fr].push_back(to);
		adj[to].push_back(fr);
		cap[fr][to] = 1;
	}

	int flow = 0, new_flow = 0;
	while ((new_flow = bfs(src, sink))) {
		flow += new_flow;
		int v = sink;
		while (v != src) {
			int prev = parent[v];
			cap[prev][v] -= new_flow;
			cap[v][prev] += new_flow;
			v = prev;
		}
	}

	cout << flow << endl;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (cap[n + i][j] == 1) {
				cout << j << " " << i << endl;
			}
		}
	}
	
	return 0;
}
