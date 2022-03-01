#include<bits/stdc++.h>
void bfs(int vertex, vector<int> &visited, vector<int> &res, vector<vector<int>> &adjList) {
    queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        res.push_back(currNode);

        for (int i = 0; i < adjList.size(); i++) {
            if (adjList[currNode][i] == 1 and visited[i] == -1) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    vector<vector<int>>  adjList(V, vector<int> (V));

    for (auto pr : edges) {
        int src = pr.first, dest = pr.second;
        adjList[src][dest] = 1;
        adjList[dest][src] = 1;
    }

    vector<int> res;
    vector<int> visited(V, -1);

    // Run for all components
    for (int vertex = 0; vertex < V; vertex++) {
        if (visited[vertex] == -1)
            bfs(vertex, visited, res, adjList);
    }

    return res;
}