class Solution {
public:
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int first(int *arr, int st, int end, int x) {
		int in = -1;
		while (st <= end) {
			int mid = st + (end - st) / 2;
			if (arr[mid] == x) {
				in = mid;
				end = mid - 1;
			}
			if (arr[mid] < x) st = mid + 1;
			else end = mid - 1;
		}
		return in;
	}

	int last(int *arr, int st, int end, int x) {
		int in = -1;
		while (st <= end) {
			int mid = st + (end - st) / 2;
			if (arr[mid] == x) {
				in = mid;
				st = mid + 1;
			}
			else if (arr[mid] < x) st = mid + 1;
			else end = mid - 1;
		}
		return in;
	}

	int count(int arr[], int n, int x) {
		// code here
		int f = first(arr, 0, n - 1, x);
		int l = last(arr, 0, n - 1, x);

		if (f == -1 and l == -1) return 0;
		return l - f + 1;
	}
};