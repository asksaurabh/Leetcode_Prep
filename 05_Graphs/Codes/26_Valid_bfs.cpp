#include <bits/stdc++.h>
using namespace std;

bool isValidBfs(int src, int n, vector<int> &seq, vector<int> adj[]) {
	vector<int> relativeOrder(n + 1);

	// Store the order in which vertices appear in required seq
	for (int i = 0; i < n; i++) {
		relativeOrder[seq[i]] = i;
	}

	// Sort the adj List of each node in order wanted in the sequence
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
			return relativeOrder[a] < relativeOrder[b];
		});
	}

	// Now run a normal bfs and record the bfs trav
	vector<int> vis(n + 1);
	queue<int> q;
	q.push(1); vis[1] = 1;
	vector<int> trav;

	while (q.empty() == false) {
		int node = q.front(); q.pop();
		trav.push_back(node);

		// Now since we have arranged each neighbour in each node such that it should appear in seq
		// Now even if we can't get the same seq then valid seq is not given to us
		for (int neigh : adj[node]) {
			if (vis[neigh] == 0) {
				q.push(neigh);
				vis[neigh] = 1;
			}
		}
	}

	// Now compare the traversals
	for (int i = 0; i < n; i++) {
		if (trav[i] != seq[i]) return false;
	}

	return true;
}

int main() {
	int n;
	cin >> n;
	vector<int> adj[n + 1];

	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> seq(n);
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	bool res = isValidBfs(1, n, seq, adj);
	res == true ? cout << "Yes" : cout << "No";
	return 0;
}