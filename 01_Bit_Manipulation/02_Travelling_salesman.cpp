// Given n cities and distances between every pair of cities, Problem is to find the shortest route such that you visit every city exactly once and returns to the starting point.
#include <bits/stdc++.h>
using namespace std;

int shortestRoute(vector<vector<int>> &graph, int visited, int currCity, int n) {

	if (visited == ((1 << n) - 1)) {
		// return the cost of last city(curr city) back to the source
		return graph[currCity][0];
	}

	int minDist = INT_MAX;
	// Try all possible neighbours
	for (int neighbour = 0; neighbour < n; neighbour++) {

		// Visit the unvisited neighbours
		if ((visited & (1 << neighbour)) == 0) {

			int subProblem = graph[currCity][neighbour] + shortestRoute(graph, visited | (1 << neighbour), neighbour, n);

			minDist = min(minDist, subProblem);
		}
	}

	return minDist;
}

int optimized(vector<vector<int>> &graph, int visited, int currCity, int n, vector<vector<int>> &dp) {

	if (visited == ((1 << n) - 1)) {
		// return the cost of last city(curr city) back to the source
		return graph[currCity][0];
	}

	if (dp[visited][currCity] != -1) return dp[visited][currCity];

	int minDist = INT_MAX;
	// Try all possible neighbours
	for (int neighbour = 0; neighbour < n; neighbour++) {

		// Visit the unvisited neighbours
		if ((visited & (1 << neighbour)) == 0) {

			int subProblem = graph[currCity][neighbour] + optimized(graph, visited | (1 << neighbour), neighbour, n, dp);

			minDist = min(minDist, subProblem);
		}
	}

	return dp[visited][currCity] = minDist;
}

int main() {

	// Graph of 0..n-1 cities with distances between each pair of city.
	int n = 4;
	vector<vector<int>> graph = {
		{0, 20, 42, 25},
		{20, 0, 30, 34},
		{42, 30, 0, 10},
		{25, 34, 10, 0}
	};

	int visited = 1;         // mark source = 0 as visited. ->> 0001
	cout << shortestRoute(graph, visited, 0, n) << "\n";


	// Optimized code
	visited = 1;
	// As visited has 2^n different states(depending upon which state is marked).
	// So size(dp) -> [2^n][n].

	vector<vector<int>> dp(1 << n, vector<int> (n, -1));
	cout << optimized(graph, visited, 0, n, dp) << "\n";

}