void dfs(int v, vector<int> &vis, vector<int> &path, vector<vector<int>> &adjList) {
    path.push_back(v);
    vis[v] = 1;

    for (int neigh : adjList[v]) {
        if (vis[neigh] == 0)
            dfs(neigh, vis, path, adjList);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &graph) {
    vector<vector<int>> res;
    vector<vector<int>> adjList(V);

//     Adjacency List Formation
    for (int i = 0; i < E; i++) {
        adjList[graph[i][0]].push_back(graph[i][1]);
        adjList[graph[i][1]].push_back(graph[i][0]);
    }

//     Do a DFS Traversal for all the components;
    int connectedComponents = 0;
//     res.push_back({connectedComponents});
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (vis[i] == 0) {
//             res[0][0]++;
            vector<int> path;
            dfs(i, vis, path, adjList);
            sort(path.begin(), path.end());
            res.push_back(path);
        }
    }

    return res;
}