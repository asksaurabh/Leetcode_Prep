// T.C -> O(nlogn) + O(n * n)
// Optimize using Disjoint Set LATER.  [TO DO]

#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;  // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    static bool compare(struct Job a, struct Job b) {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) {

        // Idea is to sort the jobs acc to profit.
        // Now do the job on its last day so that u can fill days for less profit jobs later
        sort(arr, arr + n, compare);

        vector<int> deadline(101, -1);               // From constraints. As max deadline can be 100

        int countJobs = 0, maxProfit = 0;
        for (int i = 0; i < n; i++) {

            // Place the current job on last deadline if possible. Otherwise find the last deadline if taken
            for (int j = arr[i].dead; j >= 1; j--) {
                if (deadline[j] == -1) {
                    deadline[j] = arr[i].id;
                    countJobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        vector<int> res = {countJobs, maxProfit};
        return res;
    }
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--) {
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}


// } Driver Code Ends