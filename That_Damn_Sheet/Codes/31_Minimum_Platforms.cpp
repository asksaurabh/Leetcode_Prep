// O(nlogn)
class Solution {
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        //  Select the first train
        int i = 1, j = 0, plat_count = 1;
        int res = 1;

        while (i < n and j < n) {
            // Arrival time of ith train is less than or equal to dep time of last train
            if (arr[i] <= dep[j]) {
                plat_count++;
                res = max(res, plat_count);
                i++;
            }

            else if (arr[i] > dep[j]) {
                plat_count--;
                j++;
            }
        }

        return res;
    }
};

// O(N) Solution
class Solution {
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Since we are only looping over time
        // And time ranges from [0..2359].

        vector<int> platform(2360, 0);
        int platform_needed = 1;

        for (int i = 0; i < n; i++) {
            // increment the platforms for arrival
            platform[arr[i]]++;

            // once train departs we decrease the platform count
            platform[dep[i] + 1]--;
        }

        for (int i = 1; i <= 2359; i++) {
            platform[i] = platform[i] + platform[i - 1];
            platform_needed = max(platform_needed, platform[i]);
        }

        return platform_needed;
    }
};