#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll INF = 1e17;

ll n, m;
vector<vector<ll>> adj;
vector<vector<ll>> cap;

vector<ll> parent;

ll bfs(ll src, ll sink) {
	parent.assign(n, -1);
	parent[src] = -2;
	queue<pair<ll, ll>> q;
	q.push({src, INF});

	while (!q.empty()) {
		auto [v, flow_to_v] = q.front(); q.pop();
		if (v == sink) {
			return flow_to_v;
		}

		for (ll out : adj[v]) {
			if (parent[out] == -1 && cap[v][out] > 0) {
				parent[out] = v;
				q.push({ out, min(flow_to_v, cap[v][out])});
			}
		}
	}
	return 0;
}

int main() {
	cin.tie()->sync_with_stdio();
	
	cin >> n >> m;
	adj.resize(n);
	cap.assign(n, vector<ll> (n, 0));
	vector<pair<ll, ll>> edges;

	for (ll i = 0; i < m; i++) {
		ll fr, to;
		cin >> fr >> to;
		fr--; to--;
		cap[fr][to] = 1;
		cap[to][fr] = 1;
		adj[fr].push_back(to);
		adj[to].push_back(fr);
	}
	
	ll flow = 0, new_flow = 0;
	ll src = 0, sink = n - 1;
	while ((new_flow = bfs(src, sink))) {
		flow += new_flow;

		ll v = sink;
		while (v != src) {
			ll prev = parent[v];
			cap[prev][v] -= new_flow;
			cap[v][prev] += new_flow;
			v = prev;
		}
	}
	
	cout << flow << endl;
	for (int fr = 0; fr < n; fr++) {
		for (auto to : adj[fr]) {
			if (parent[fr] != -1 && parent[to] == -1) {
				cout << fr + 1 << " " << to + 1 << endl;
			}
		}
	}
}
