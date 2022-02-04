// Various variations with subsequences. Constraints for given situation are:
// 1. Print in any order allowed
// 2. Choosing same number at different indices allowed.
// 3. Choosing same number at same index not allowed repeatedly.

#include <bits/stdc++.h>
using namespace std;

// Both positive and negative numbers allowed
void getAllWithSumk(int index, int n, vector<int> &arr, vector<int> &temp, int k) {

    if (index == n) {
        if (k == 0) {
            for (int val : temp)
                cout << val << " ";
            cout << "\n";
        }
        return;
    }

    temp.push_back(arr[index]);
    getAllWithSumk(index + 1, n, arr, temp, k - arr[index]);

    temp.pop_back();
    getAllWithSumk(index + 1, n, arr, temp, k);
}

// Refactored Way of printing all subsets with sum k.
void getAll(int index, int n, vector<int> &arr, vector<int> &temp, int k) {

    if (k == 0) {
        for (int val : temp)
            cout << val << " ";
        cout << "\n";
    }

    for (int i = index; i < n; i++) {
        temp.push_back(arr[i]);
        getAll(i + 1, n, arr, temp, k - arr[i]);
        temp.pop_back();
    }
}

// Prints any one subset with sum k.
bool getAnyOneWithSumk(int index, int n, vector<int> &arr, vector<int> &temp, int k) {

    if (k == 0) {
        for (int val : temp)
            cout << val << " ";
        cout << "\n";
        return true;
    }

    for (int i = index; i < n; i++) {
        temp.push_back(arr[i]);
        if (getAnyOneWithSumk(i + 1, n, arr, temp, k - arr[i]) == true)
            return true;
        temp.pop_back();
    }

    return false;
}

// Returns the count of all the subsets with sum k.
int countAllWithSumk(int index, int n, vector<int> &arr, int k) {

    if (index == n) {
        if (k == 0) return 1;
        else return 0;
    }

    int pickCurrent = countAllWithSumk(index + 1, n, arr, k - arr[index]);
    int ignoreCurrent = countAllWithSumk(index + 1, n, arr, k);

    return pickCurrent + ignoreCurrent;
}

int main() {
    vector<int> arr = {1, 4, 2, 1, 3, 0};
    // vector<int> arr = {1,1,1};

    int k = 4, n = arr.size();
    vector<int> temp, temp1, temp2;

    // Print All subsequences with sum k

    // getAllWithSumk(0, n, arr, temp, k);

    cout << "-----------------------------------\n";

    getAll(0, n, arr, temp1, k);

    // // Get any one subsequence with sum k
    // cout << "-----------------------------------\n";

    // getAnyOneWithSumk(0, n, arr, temp2, k);


    // Count all subsequences with sum k
    cout << "-----------------------------------\n";

    cout << countAllWithSumk(0, n, arr, k);

    return 0;
}
