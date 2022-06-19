#include <bits/stdc++.h>
using namespace std;

void bfs(int src, int n, vector<int> adj[]) {
	vector<int> vis(n + 1, 0), path(n + 1, -1);
	queue<int> q;
	q.push(src);

	vis[src] = 1;
	path[src] = 0;

	// Nodes are numbered from 1 to n
	while (q.empty() == false) {
		int node = q.front(); q.pop();

		for (int neigh : adj[node]) {
			if (vis[neigh] == 0) {
				q.push(neigh);
				vis[neigh] = 1;
				path[neigh] = node;            // Means neigh is reachable from node
				if (neigh == n) break;
			}
		}
	}

	if (path[n] == -1) {
		cout << "IMPOSSIBLE";
		return;
	}

	int count = 0;
	vector<int> res;
	int s = n;
	while (s != 0) {
		res.push_back(s);
		s = path[s];
		count++;
	}

	cout << count << "\n";
	reverse(res.begin(), res.end());
	for (int val : res) cout << val << " ";
}

int main() {
	int n, e;
	cin >> n >> e;

	vector<vector<int>> edges;
	vector<int> adj[n + 1];

	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(1, n, adj);
	return 0;
}