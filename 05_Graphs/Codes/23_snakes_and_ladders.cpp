#include<bits/stdc++.h>
using namespace std;

int bfs(int src, int n, vector<int> adj[]) {
	queue<int> q;
	q.push(src);
	vector<int> vis(n + 1), dist(n + 1);
	vis[src] = 1;
	dist[src] = 0;

	while (q.empty() == false) {
		int node = q.front(); q.pop();

		for (int neigh : adj[node]) {
			if (vis[neigh] == false) {
				q.push(neigh);
				vis[neigh] = 1;
				dist[neigh] = dist[node] + 1;
				if (neigh == n) break;
			}
		}
	}

	return dist[n];
}

int min_dice_throws(int n, vector<pair<int, int> > snakes, vector<pair<int, int> > ladders) {
	// Calculate the jumps at any position in the board.
	vector<int> jumps(n + 1, 0);

	for (auto pr : snakes) {
		// Eg: Snake -> [17(h), 4(t)]
		// So if u reach 17 then ur new pos will be -> 4 (17 - 13)
		// shift at 17 = (4 - 17) = -13
		int shift = pr.second - pr.first;
		jumps[pr.first] = shift;
	}

	for (auto pr : ladders) {
		// Eg: [2, 15] -> shift = 15 - 2 = +13
		jumps[pr.first] = pr.second - pr.first;
	}

	// Now make a adj List corresponding to each pos in the board [1 - 36]
	// Populate the adjList
	// It will be a directed graph
	vector<int> adj[n + 1];

	for (int i = 1; i < n; i++) {
		for (int dice = 1; dice <= 6; dice++) {
			int src = i;
			int dest = src + dice + jumps[src];

			if (dest <= n) adj[src].push_back(dest);
		}
	}

	return bfs(1, n, adj);
}