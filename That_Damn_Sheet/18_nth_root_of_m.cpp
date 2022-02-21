// T.C -> O(log (m * 10^d)) where d -> No of decimal places
double multiply(double number, int n) {
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
        ans = ans * number;
    return ans;
}

double findNthRootOfM(int n, long long m) {
    double start = 1;
    double end = m;
    double eps = 1e-7;

    while ((end - start) > eps) {
        double mid = (start + end) / 2.0;
        if (multiply(mid, n) < m)
            start = mid;
        else
            end = mid;
    }

    return start;
}
