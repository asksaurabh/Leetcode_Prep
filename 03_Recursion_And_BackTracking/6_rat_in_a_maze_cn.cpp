void solve(int row, int col, int n, vector<vector<int>> &maze, vector<vector<int>> &vis, vector<vector<int>> &res) {
    if (row == n - 1 and col == n - 1) {
        vis[row][col] = 1;
        vector<int> path;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                path.push_back(vis[i][j]);
            }
        }
        res.push_back(path);
        vis[row][col] = 0;
        return;
    }

    // DLRU
    vector<int> di = {1, 0, 0, -1}, dj = {0, -1, 1, 0};
    for (int index = 0; index < 4; index++) {
        int nexti = row + di[index];
        int nextj = col + dj[index];

        if (nexti >= 0 and nexti < n and nextj >= 0 and nextj < n and maze[nexti][nextj] == 1 and vis[nexti][nextj] == 0) {
            vis[row][col] = 1;
            solve(nexti, nextj, n, maze, vis, res);
            vis[row][col] = 0;
        }
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n) {
    vector<vector<int>> res;
    vector<vector<int>> visited(n, vector<int> (n, 0));
    if (maze[0][0] == 0) return res;

    solve(0, 0, n, maze, visited, res);
    return res;
}