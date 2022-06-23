// Approach 1: DFS
void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& matrix) {
	vis[i][j] = 1;

	int m = matrix.size(), n = matrix[0].size();
	//same row
	for (int col = 0; col < n; col++) {
		if (col != j and matrix[i][col] == 1 and vis[i][col] == 0) {
			dfs(i, col, vis, matrix);
		}
	}

	//same col
	for (int row = 0; row < m ; row++) {
		if (row != i and matrix[row][j] == 1 and vis[row][j] == 0) {
			dfs(row, j, vis, matrix);
		}
	}
}
int solve(vector<vector<int>>& matrix) {

	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> vis(m , vector<int> (n , 0));
	int comp = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0 and matrix[i][j] == 1) {
				comp++;
				dfs(i, j, vis, matrix);
			}
		}
	}

	return comp;
}

// Approach 2: DSU
int find(int node, int *parent) {
	if (node == parent[node]) return node;
	return parent[node] = find(parent[node], parent);
}

void Union(int u, int v, int* parent, int *rank) {
	int setu = find(u, parent);
	int setv = find(v, parent);

	if (setu != setv) {
		if (rank[setu] < rank[setv]) {
			parent[setu] = setv;
			rank[setv] += rank[setu];
		} else {
			parent[setv] = setu;
			rank[setu] += rank[setv];
		}
	}
}

int solve(vector<vector<int>>& matrix) {
	// Count all the elements in each component
	// Catch leader of the component and see its rank

	int m = matrix.size(), n = matrix[0].size();
	int parent[m * n];
	int rank[m * n];

	for (int i = 0; i < m * n; i++) {
		parent[i] = i;
		rank[i] = 1;
	}

	// Problem is how do u ID the nodes: 0, 1, 2, 3, 4... so that u can add edges
	// Use this: ID = (i * n) + j

	// Two nodes are connected to each other if they are in the same row or column.
	// Add edges of same rows
	for (int i = 0; i < m; i++) {
		int cellId = -1;
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 1) {
				if (cellId == -1) cellId = i * n + j;
				else {
					// cell id is set, so add node
					Union(cellId, i * n + j, parent, rank);
				}
			}
		}
	}

	// Add edges of same columns
	for (int j = 0; j < n; j++) {
		int cellId = -1;
		for (int i = 0; i < m; i++) {
			if (matrix[i][j] == 1) {
				if (cellId == -1) cellId = i * n + j;
				else Union(cellId, i * n + j, parent, rank);
			}
		}
	}

	// Find the leaders
	int comp = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 1 and find(i * n + j, parent) ==  i * n + j) comp++;
		}
	}

	return comp;
}