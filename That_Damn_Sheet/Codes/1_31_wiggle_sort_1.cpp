// Approach 1: T.C -> O(nlogn), S.C -> O(1)
// Works on dictinct integers.
class Solution {
public:
	// arr: input array
	// n: size of array
	//Function to sort the array into a wave-like array.
	void convertToWave(vector<int>& arr, int n) {

		// a[0] >= a[1] <= a[2] >= a[3] <= a[4] >= a[5] <= a[6]

		sort(arr.begin(), arr.end());

		// Swap adjacent elements
		for (int i = 1; i < n; i += 2) {
			swap(arr[i], arr[i - 1]);
		}
	}
};

// Approach 2: T.C -> O(n), S.C -> O(1)
class Solution {
public:
	// arr: input array
	// n: size of array
	//Function to sort the array into a wave-like array.
	void convertToWave(vector<int>& arr, int n) {

		// a[0] >= a[1] <= a[2] >= a[3] <= a[4]

		// Focus on even positioned elements.
		// IF curr ele < prev odd ele -> swap
		// IF curr ele > next odd ele -> swap

		for (int i = 0; i < n; i += 2) {
			if (i > 0 and arr[i - 1] > arr[i])
				swap(arr[i - 1], arr[i]);
			if (i < n - 1 and arr[i] < arr[i + 1])
				swap(arr[i], arr[i + 1]);
		}

	}
};