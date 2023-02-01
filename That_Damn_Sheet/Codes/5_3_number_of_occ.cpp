// Approach - 1
class Solution{
public:	
    int getStartIndex(int arr[], int n, int x) {
        int lo = 0, hi = n - 1;
        
        while(hi - lo > 1) {
            int mid = lo + (hi - lo)/2;
            if(arr[mid] < x) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        if(arr[lo] == x) return lo;
        else if(arr[hi] == x) return hi;
        return -1;
    }
	
	int getEndIndex(int arr[], int n, int x) {
	    int lo = 0, hi = n - 1;
	    
	    while(hi - lo > 1) {
	        int mid = lo + (hi - lo)/2;
	        if(arr[mid] > x) {
	            hi = mid - 1;
	        } else {
	            lo = mid;
	        }
	    }
	    
	    if(arr[hi] == x) return hi;
	    else if(arr[lo] == x) return lo;
	    return -1;
	}
	
	int count(int arr[], int n, int x) {
	    int startIndex = getStartIndex(arr, n, x);
	    int endIndex = getEndIndex(arr, n, x);
	    
	    if(startIndex == -1) return 0;
	    return (endIndex - startIndex + 1);
	}
};

// Approach - 2
// Using extra variable.
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