#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;

// Assuming arr.size() > 0.
int lowerBound(vector<ll> &nums, ll key) {
	int lo = 0, hi = nums.size() - 1;

	while (hi - lo > 1) {
		int mid = lo + (hi - lo) / 2;
		if (nums[mid] < key) lo = mid + 1;
		else hi = mid;
	}

	if (nums[lo] == key) return lo;
	else if (nums[hi] == key) return hi;
	return -1;
}

int upperBound(vector<ll> &nums, ll key) {
	int lo = 0, hi = nums.size() - 1;

	while (hi - lo > 1) {
		int mid = lo + (hi - lo) / 2;
		if (nums[mid] > key) hi = mid - 1;
		else {
			lo = mid;
		}
	}

	if (nums[hi] == key) return hi;
	else if (nums[lo] == key) return lo;
	return -1;
}

int main() {

	FAST_IO;
	int t;
	cin >> t;

	while (t--) {
		ll size, key;
		cin >> size;
		vector<ll> nums(size);

		for (int i = 0; i < size; i++) {
			cin >> nums[i];
		}

		cin >> key;
		cout << lowerBound(nums, key) << "\n";
	}

	return 0;
}