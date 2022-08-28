vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    map<int, int> mp;
    vector<int> res;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    mp[A[0]]++;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] != A[i - 1]) mp[A[i]]++;
    }

    mp[B[0]]++;
    for (int i = 1; i < B.size(); i++) {
        if (B[i] != B[i - 1]) mp[B[i]]++;
    }

    mp[C[0]]++;
    for (int i = 1; i < C.size(); i++) {
        if (C[i] != C[i - 1]) mp[C[i]]++;
    }

    for (auto pr : mp) {
        if (pr.second > 1) res.push_back(pr.first);
    }

    return res;
}
