// Time Complexity -> O(V ^ m). For each vertex I have to try m possible colors.

// Returns T/F if it is possible to color current vertex with current col?
bool isPossibleToColor(int vertex, int col, vector<int> &color, vector<vector<int>> &graph) {
    // Idea is all the neighbours for current vertex should not have this col.
    int V = graph.size();
    for (int neighbour = 0; neighbour < V; neighbour++) {
        if (graph[vertex][neighbour] == 1) {
            if (col == color[neighbour]) return false;
        }
    }

    return true;
}

bool colorGraph(int vertex, vector<vector<int>> &graph, int m, vector<int> &color, int V) {
    if (vertex == V) return true;

    // try to color the current vertex with one of the m colors
    for (int col = 1; col <= m; col++) {

        // Color only if it is possible to color the current vertex with current col(color)
        if (isPossibleToColor(vertex, col, color, graph)) {
            color[vertex] = col;

            // Now by choosing the current col for the current vertex, if u are able to
            // strike the right color combo for the whole graph
            // (Means ur chosen col for current vertex is right)

            if (colorGraph(vertex + 1, graph, m, color, V) == true)
                return true;

            // Now if it was wrong, try another col
            color[vertex] = -1;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &graph, int m) {
    int V = graph.size();
    vector<int> color(V + 1, -1);
    int vertex = 0;

    bool res = colorGraph(vertex, graph, m, color, V);
    return res == true ? "YES" : "NO";
}