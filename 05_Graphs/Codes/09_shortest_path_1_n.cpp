// Approach 1: Make a directed unweighted graph and find the shortest path.
// T.C -> O(v + e)
class Solution {
public:
	int minimumStep(int n) {
		// Bfs on a directed graph
		vector<int> adj[n + 1];
		for (int i = 1; i <= n; i++) {
			int dest1 = i + 1, dest2 = 3 * i;

			if (dest1 <= n) adj[i].push_back(dest1);
			if (dest2 <= n) adj[i].push_back(dest2);
		}

		vector<int> vis(n + 1, 0), dist(n + 1, 0);
		queue<int> q;
		q.push(1);
		vis[1] = 1;
		dist[1] = 0;

		while (!q.empty()) {
			int node = q.front(); q.pop();

			for (int ngh : adj[node]) {
				if (vis[ngh] == 0) {
					q.push(ngh);
					vis[ngh] = 1;
					dist[ngh] = dist[node] + 1;

					if (ngh == n)
						break;
				}
			}
		}

		return dist[n];
	}
};

// Approach 2: Observation:
class Solution {
public:
	int minimumStep(int n) {
		//complete the function here
		if (n == 1) return 0;

		if (n % 3 == 0) {
			return 1 + minimumStep(n / 3);
		}

		else {
			return 1 + minimumStep(n - 1);
		}
	}
};

// Approach 3: Iterative
class Solution {
public:
	int minimumStep(int n) {
		//complete the function here
		int steps = 0;
		while (n != 1) {
			if (n % 3 == 0) n /= 3;
			else n--;

			steps++;
		}

		return steps;
	}
};