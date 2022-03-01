// DFS Traversal
void dfs(int vertex, vector<int> &visited, vector<int> &path, vector<vector<int>> &graph) {
	visited[vertex] = 1;
	path.push_back(vertex);

	for (int neighbour : graph[vertex]) {
		if (visited[neighbour] == -1) {
			dfs(neighbour, visited, path, graph);
		}
	}
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &graph)
{
	vector<vector<int>> res;
	vector<int> visited(V, -1);

	for (int vertex = 0; vertex < V; vertex++) {
		vector<int> path;
		if (visited[vertex] == -1) {
			dfs(vertex, visited, path, graph);
			res.push_back(path);
		}
	}

	return res;
}