class Solution {
public:
    int bs(int start, int end, int n, int* a) {
        // int pos = 0;
        while (start <= end) {
            int mid = (start + end) / 2;

            // If the middle element is smaller than its previous element, then it is the minimum element
            if (mid > 0 && a[mid] < a[mid - 1]) {
                return mid;
            }

            // If the middle is greater than its next element, then the next element is the minimum element
            if (mid < n - 1 && a[mid] > a[mid + 1]) {
                return mid + 1;
            }

            if (a[start] <= a[mid]) { // left array is sorted. So the pivot (min element) is on the right side
                start = mid + 1;
            } else { //right array is sorted. So the pivot (min element) is on the left side
                end = mid - 1;
            }
        }

        return 0; // the array has not been rotated
    }

    int findKRotation(int arr[], int n) {
        // code here
        // Check if K can be zero.
        // This means that if K = 0 no rotation
        // If K != 0 then it means that at K = N we get sorted arr again

        // Find the pos of the min element in rot sort arr
        int pos = bs(0, n - 1, n, arr);
        return pos;
    }

};