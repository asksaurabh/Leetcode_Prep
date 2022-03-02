// T.C -> O(n), S.C -> O(k)

vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int K) {

    vector<long long> res;
    queue<long long> q;
    long long i = 0, j = 0;

    while (j < N) {
        if (arr[j] < 0) {
            q.push(arr[j]);
        }

        if (j - i + 1 < K) {
            j++;
        }

        else if (j - i + 1 == K) {
            if (q.empty() == true) {
                res.push_back(0);
            }
            else {
                res.push_back(q.front());
            }

            if (arr[i] < 0)
                q.pop();

            i++, j++;
        }
    }

    return res;
}