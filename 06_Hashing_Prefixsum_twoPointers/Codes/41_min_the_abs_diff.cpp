int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    // https://www.youtube.com/watch?v=BlXTlC6_Xv4

    int i = 0, j = 0, k = 0;
    int res = INT_MAX;
    while (i < A.size() and j < B.size() and k < C.size()) {
        int diff = max({ abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]) });

        if (A[i] <= B[j] and A[i] <= C[k]) i++;
        else if (B[j] <= A[i] and B[j] <= C[k]) j++;
        else k++;

        res = min(res, diff);
    }

    return res;
}
