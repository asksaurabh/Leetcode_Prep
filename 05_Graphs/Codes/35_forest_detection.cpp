int find(int node, int *parent) {
    if (node == parent[node]) return node;

    return parent[node] = find(parent[node], parent);
}

void Union(int u, int v, int *parent, int *rank) {
    int parentu = find(u, parent);
    int parentv = find(v, parent);

    if (parentu != parentv) {
        if (rank[parentu] < rank[parentv]) {
            parent[parentu] = parentv;
            rank[parentv] += rank[parentu];
        } else {
            parent[parentv] = parentu;
            rank[parentu] += rank[parentv];
        }
    }
}

// detect whether there is a cycle in the undirected graph
// If cycle found -> Not a tree.
bool solve(vector<vector<int>>& edges) {
    // Assuming u,v lies btw [0, 100000]
    int parent[100001];
    int rank[100001];

    for (int i = 0; i < 100001; i++) {
        parent[i] = i;
        rank[i] = 1;
    }

    for (auto edge : edges) {
        int u = edge[0], v = edge[1];

        int parentu = find(u, parent);
        int parentv = find(v, parent);

        if (parentu == parentv) return false;

        // otherwise Connect them
        Union(u, v, parent, rank);
    }

    return true;
}