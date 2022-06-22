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

// Approach 2: Another Way
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

void solve() {

	int n, m; cin >> n >> m;

	vector <vector <int>> adj (n + 1, vector <int>());
	vector <int> indeg (n + 1, 0);
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back (y);
		indeg[y]++;
	}

	// Remove the dependency as well as count only those paths which starts with one.
	queue <int> q;
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) q.push (i);

	int ans = 0;
	vector <int> dp (n + 1, 0);
	dp[1] = 1;

	while (q.size()) {
		int node = q.front (); q.pop ();

		for (auto nbr : adj[node]) {
			dp[nbr] = (dp[nbr] + dp[node]) % mod;
			indeg[nbr]--;
			if (indeg[nbr] == 0)
				q.push (nbr);
		}

		if (indeg[n] == 0)
			break;
	}

	cout << dp[n] << endl;
}


int main() {

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
