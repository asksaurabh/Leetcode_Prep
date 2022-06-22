#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1e9 + 7;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	vector<int> in(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}

	queue<int> q;

	// Pruning -> Make sure only when u start from 1 u reach n.
	// Removing the false starts

	for (int i = 2; i <= n; i++)
		if (in[i] == 0) q.push(i);

	while (q.empty() == false) {
		int node = q.front(); q.pop();
		for (int n : adj[node]) {
			in[n]--;
			if (in[n] == 0 and n != 1) q.push(n);
		}
	}

	vector<ll> dp(n + 1);
	// dp[i] store no of ways to get to a paticular vertex i

	dp[1] = 1;
	q.push(1);

	while (q.empty() == false) {
		int node = q.front(); q.pop();
		for (int n : adj[node]) {
			in[n]--;
			dp[n] = dp[n] + dp[node];
			dp[n] %= mod;
			if (in[n] == 0) q.push(n);
		}
	}

	cout << dp[n];
	return 0;
}
