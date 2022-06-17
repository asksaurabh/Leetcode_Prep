// BFS
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
	vector<int> adj[v];
	vector<int> indegree(v, 0);
	for (auto edge : edges) {
		adj[edge[0]].push_back(edge[1]);
		indegree[edge[1]]++;
	}

	queue<int> q;
	for (int i = 0; i < v; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	vector<int> topo;
	while (q.empty() == false) {
		int node = q.front(); q.pop();
		topo.push_back(node);

		for (int n : adj[node]) {
			indegree[n]--;
			if (indegree[n] == 0) q.push(n);
		}
	}

	return topo;
}

// DFS
#include<stack>
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
	vis[node] = 1;

	for (int n : adj[node]) {
		if (vis[n] == 0)
			dfs(n, vis, adj, st);
	}

	st.push(node);
	return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
	// Write your code here
	vector<int> adj[n];
	for (auto edge : edges) {
		adj[edge[0]].push_back(edge[1]);
	}

	vector<int> vis(n, 0);
	vector<int> topo;
	stack<int> st;

	for (int i = 0; i < n; i++) {
		if (vis[i] == 0) {
			dfs(i, vis, adj, st);
		}
	}

	while (st.empty() == false) {
		topo.push_back(st.top());
		st.pop();
	}

	return topo;
}