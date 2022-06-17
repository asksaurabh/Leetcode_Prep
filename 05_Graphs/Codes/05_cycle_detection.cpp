// Cycle Detection In Undirected Graph
// You need a parent to check cycle detection.
bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[]) {
	vis[node] = 1;

	for (int n : adj[node]) {
		if (vis[n] == 0) {
			bool isCyclePresentAhead = dfs(n, node, vis, adj);
			if (isCyclePresentAhead) return true;
		}

		else if (vis[n] == 1 and n != parent) return true;
	}

	return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
	// Form an adj
	vector<int> adj[n + 1];
	for (auto edge : edges) {
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}

	// Run a dfs over all the components
	vector<int> vis(n + 1, 0);
	bool isCycle = false;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			if (dfs(i, -1, vis, adj) == true) {
				isCycle = true;
				break;
			}
		}
	}

	return isCycle == true ? "Yes" : "No";
}


// BFS
#include<queue>
bool bfs(int node, vector<int> &vis, vector<int> adj[]) {
	queue<pair<int, int>> q;
	q.push({node, -1});
	vis[node] = 1;

	while (q.empty() == false) {
		int curr = q.front().first;
		int currParent = q.front().second;
		q.pop();

		for (int n : adj[curr]) {
			if (vis[n] == 0) {
				q.push({n, curr});
				vis[n] = 1;
			}
			else if (vis[n] == 1 and n != currParent) return true;
		}
	}

	return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
	// Form an adj
	vector<int> adj[n + 1];
	for (auto edge : edges) {
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}

	// Run a dfs over all the components
	vector<int> vis(n + 1, 0);
	bool isCycle = false;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			if (bfs(i, vis, adj) == true) {
				isCycle = true;
				break;
			}
		}
	}

	return isCycle == true ? "Yes" : "No";
}
