// Approach 1:
// time complexity -> 4^(n*n) -> for every cell (total -> n*n) I have 4 options.

class Solution {
public:

    void getPath(int i, int j, vector<vector<int>> &graph, int n, vector<string> &res,
                 string path, vector<vector<int>> &visited) {

        if (i == n - 1 and j == n - 1) {
            res.push_back(path);
            return;
        }

        // For getting Lexicographic order -> Traverse in DLRU

        // Down -> (D)
        if (i + 1 < n and visited[i + 1][j] == -1 and graph[i + 1][j] == 1) {
            path.push_back('D');
            visited[i][j] = 1;
            getPath(i + 1, j, graph, n, res, path, visited);
            path.pop_back();
            visited[i][j] = -1;
        }

        // Left -> (L)
        if (j - 1 >= 0 and visited[i][j - 1] == -1 and graph[i][j - 1] == 1) {
            path.push_back('L');
            visited[i][j] = 1;
            getPath(i, j - 1, graph, n, res, path, visited);
            path.pop_back();
            visited[i][j] = -1;
        }

        // Right -> (R)
        if (j + 1 < n and visited[i][j + 1] == -1 and graph[i][j + 1] == 1) {
            path.push_back('R');
            visited[i][j] = 1;
            getPath(i, j + 1, graph, n, res, path, visited);
            path.pop_back();
            visited[i][j] = -1;
        }

        // Up -> (U)
        if (i - 1 >= 0 and visited[i - 1][j] == -1 and graph[i - 1][j] == 1) {
            path.push_back('U');
            visited[i][j] = 1;
            getPath(i - 1, j, graph, n, res, path, visited);
            path.pop_back();
            visited[i][j] = -1;
        }


    }

    vector<string> findPath(vector<vector<int>> &graph, int n) {
        // Your code goes here
        vector<string> res;
        vector<vector<int>> visited(n, vector<int> (n, -1));
        string path = "";

        if (graph[0][0] == 1)
            getPath(0, 0, graph, n, res, path, visited);

        return res;
    }
};

// APPROACH 2:
// time complexity -> 4^(n*n) -> for every cell (total -> n*n) I have 4 options.

class Solution {
public:

    void getPath(int i, int j, vector<vector<int>> &graph, int n, vector<string> &res,
                 string path, vector<vector<int>> &visited, vector<int> &di, vector<int> &dj) {

        if (i == n - 1 and j == n - 1) {
            res.push_back(path);
            return;
        }

        string direction = "DLRU";

        for (int index = 0; index < 4; index++) {
            int nexti = i + di[index];
            int nextj = j + dj[index];

            if (nexti >= 0 and nexti < n and nextj >= 0 and nextj < n and
                    visited[nexti][nextj] == -1 and graph[nexti][nextj] == 1) {

                path.push_back(direction[index]);
                visited[i][j] = 1;

                getPath(nexti, nextj, graph, n, res, path, visited, di, dj);

                path.pop_back();
                visited[i][j] = -1;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &graph, int n) {
        // Your code goes here
        vector<string> res;
        vector<vector<int>> visited(n, vector<int> (n, -1));
        string path = "";
        vector<int> di = {1, 0, 0, -1};
        vector<int> dj = {0, -1, 1, 0};

        if (graph[0][0] == 1)
            getPath(0, 0, graph, n, res, path, visited, di, dj);

        return res;
    }
};
