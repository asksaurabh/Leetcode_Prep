int Solution::solve(vector<int> &A, int K) {

    map<int, int> mp;
    int XOR = 0;
    int count = 0;

    for (int val : A) {
        XOR = XOR ^ val;

        if (XOR == K) count++;

        int Y = K ^ XOR;
        if (mp.find(Y) != mp.end())
            count += mp[Y];

        mp[XOR] += 1;
    }

    return count;
}
