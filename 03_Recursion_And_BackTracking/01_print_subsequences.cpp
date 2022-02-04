#include <iostream>
#include <vector>
using namespace std;

// T.C -> O(2^n) func calls + O(1)-> T.C of each call
void getSubsequences(int index, vector<int> &arr, vector<int> &result, int n) {

	if (index >= n) {
		// Reach the end of array, print the result
		if (result.size() == 0) {
			cout << "NULL SET\n";
			return;
		}

		for (int val : result)
			cout << val << " ";
		cout << endl;
		return;
	}

	// Select the current element
	result.push_back(arr[index]);

	// Print all subsequences starting with current element
	getSubsequences(index + 1, arr, result, n);

	// remove current element
	result.pop_back();

	// Print all subsequences without current element.
	getSubsequences(index + 1, arr, result, n);
}

int main() {

	// Print all subsequences of arr
	vector<int> arr = {30, 10, 20};
	vector<int> result;

	getSubsequences(0, arr, result, arr.size());
	return 0;
}