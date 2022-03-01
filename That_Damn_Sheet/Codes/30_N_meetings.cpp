class Solution
{
public:

    static bool compare(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first <= b.first;

        return a.second <= b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].first = start[i];
            arr[i].second = end[i];
        }

        sort(arr.begin(), arr.end(), compare);

        int currEndTime = arr[0].second;
        int meetCount = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i].first > currEndTime) {
                meetCount++;
                currEndTime = arr[i].second;
            }
        }

        return meetCount;
    }
};