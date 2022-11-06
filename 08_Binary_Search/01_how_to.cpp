#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long int

int binarySearch(vector<int> &nums, int key) {

	int n = nums.size();
	int low = 0, high = n - 1;

	// Ensuring I have more than two elements to search from. For <= 2 I can manually compare

	while (high - low > 1) {
		int mid = low + (high - low) / 2;

		if (nums[mid] < key) low = mid + 1;
		else {
			high = mid;
		}
	}

	// In the end you have 2 elements. Do Simple comparison
	if (nums[low] == key) return low;
	else if (nums[high] == key) return high;
	else return -1;
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
		cout << binarySearch(nums, key) << "\n";
	}

	return 0;
}