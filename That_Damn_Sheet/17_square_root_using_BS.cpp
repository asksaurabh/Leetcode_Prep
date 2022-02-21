// Find the square root of a number N upto P places.
// N = 10, P = 3 =>   O/p -> 3.162

#include <bits/stdc++.h>
using namespace std;

double sqaureRoot(int n, int p) {
    double ans = 0;

    // Find the integer part
    int start = 0, end = n;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid * mid == n) return mid;

        if (mid * mid <= n) {
            // Possible answer
            ans = (double)mid * 1.0;
            start = mid + 1;       // Try to get closer to the square root
        }

        else if (mid * mid > n)
            end = mid - 1;
    }

    // Now once I have the integer part stored in the ans, find the p decimal places
    // For each decimal place, I have 9 options.

    double inc = 0.1;
    for (int place = 1; place <= p; place++) {

        while (ans * ans <= n) {
            ans += inc;
        }

        // Take one step back. (as after inc ans may become large)
        ans = ans - inc;
        inc = inc / 10.0;
    }

    return ans;
}

int main() {
    int n, p;
    n = 10;
    p = 3;

    cout << sqaureRoot(n, p);
}


