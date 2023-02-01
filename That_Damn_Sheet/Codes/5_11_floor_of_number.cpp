// Approach - 1:
#include <bits/stdc++.h> 

int floorSearch(vector<int> &arr, int X, int N)
{
    int lo = 0;
    int hi = N - 1;

    while(hi - lo > 1) {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] > X) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }

    if(arr[hi] <= X) return arr[hi];
    else if(arr[lo] <= X) return arr[lo];
    return -1; 
}

// Approach - 2:
// using extra variable
#include <bits/stdc++.h> 

int floorSearch(vector<int> &arr, int X, int N)
{
    int lo = 0;
    int hi = N - 1;
    int ans = -1;

    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] > X) {
            hi = mid - 1;
        } else {
            ans = arr[mid];
            lo = mid + 1;
        }
    }

    return ans;
}