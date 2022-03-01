#include<bits/stdc++.h>
struct Interval {
    int start;
    int end;
};
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<Interval> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].start = start[i];
        arr[i].end = finish[i];
    }

    sort(arr.begin(), arr.end(), [&](struct Interval a, struct Interval b) {
        return a.end <= b.end;
    });

    int currEndTime = arr[0].end;
    int activityCount = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= currEndTime) {
            activityCount++;
            currEndTime = arr[i].end;
        }
    }

    return activityCount;
}