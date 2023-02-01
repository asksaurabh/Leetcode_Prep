// Approach - 1
#include <bits/stdc++.h> 
int ceilingInSortedArray(int n, int x, vector<int> &arr){
    
    int lo = 0;
    int hi = n - 1;

    while(hi - lo > 1) {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    if(arr[lo] >= x) return arr[lo];
    else if(arr[hi] >= x) return arr[hi];
    return -1;
}

// Approach - 2
// Using extra variable.
#include <bits/stdc++.h> 
int ceilingInSortedArray(int n, int x, vector<int> &arr){
    
    int lo = 0;
    int hi = n - 1;
    int ans = -1;

    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] < x) {
            lo = mid + 1;
        } else {
            ans = arr[mid];
            hi = mid - 1;
        }
    }

    return ans;
}
