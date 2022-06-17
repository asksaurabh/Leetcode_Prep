#include<queue>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    if (vertex == 0) return {};
//     AdjList formation
    vector<vector<int>> adjList(vertex, vector<int> (vertex));
    for (auto pr : edges) {
        adjList[pr.first][pr.second] = 1;
        adjList[pr.second][pr.first] = 1;
    }

//     Run a BFS Traversal for all the components
    vector<int> trav;
    vector<int> vis(vertex, 0);

    for (int i = 0; i < vertex; i++) {
        if (vis[i] == 0) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty()) {
                int currNode = q.front();
                q.pop();

                trav.push_back(currNode);
                for (int i = 0; i < vertex; i++) {
                    if (vis[i] == 0 and adjList[currNode][i] == 1) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
    }

    return trav;
}