int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // minimize the differences
    // https://www.youtube.com/watch?v=BlXTlC6_Xv4

    int result = INT_MAX;
    int i = 0, j = 0, k = 0;

    while (i < A.size() and j < B.size() and k < C.size()) {
        int currMax = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});

        if (A[i] <= B[j] and A[i]  <= C[k]) i++;
        else if (B[j] <= C[k] and B[j] <= A[i]) j++;
        else k++;

        result = min(result, currMax);
    }

    return result;
}
