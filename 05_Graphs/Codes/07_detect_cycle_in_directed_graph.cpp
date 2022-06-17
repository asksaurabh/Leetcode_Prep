// BFS
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
	vector<int> adj[n + 1];
	vector<int> topo, indegree(n + 1, 0);
	for (auto edge : edges) {
		adj[edge.first].push_back(edge.second);
		indegree[edge.second]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (q.empty() == false) {
		int node = q.front();
		q.pop();

		topo.push_back(node);
		for (int n : adj[node]) {
			indegree[n]--;
			if (indegree[n] == 0) q.push(n);
		}
	}

	return topo.size() == n ? false : true;
}

// DFS
bool dfs(int node, vector<int> &currPath, vector<int> &vis, vector<int> adj[]) {
	vis[node] = 1;
	currPath[node] = 1;

	for (int n : adj[node]) {
		if (vis[n] == 0) {
			bool isCycleInNeighbor = dfs(n, currPath, vis, adj);
			if (isCycleInNeighbor) return true;
		}
		else if (vis[n] == 1 and currPath[n] == 1) return true;
	}

	currPath[node] = 0;
	return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
	vector<int> vis(n + 1, 0);
	vector<int> adj[n + 1];
	for (auto pr : edges) {
		adj[pr.first].push_back(pr.second);
	}

	vector<int> currPath(n + 1, 0);
	for (int i  = 1; i <= n; i++) {
		if (vis[i] == 0) {
			if (dfs(i, currPath, vis, adj) == true) return true;
		}
	}

	return false;
}