int getReversedNumber(int num) {
    int reversedNumber = 0;
    while (num > 0) {
        reversedNumber = reversedNumber * 10 + num % 10;
        num /= 10;
    }
    return reversedNumber;
}
bool isPalindrome(int num) {
    int reversedNumber = getReversedNumber(num);
    return reversedNumber == num;
}

int Solution::solve(int A, int B, int C) {
    vector<int> pals;
    for (int i = A; i <= B; i++) {
        if (isPalindrome(i)) pals.push_back(i);
    }

    int i = 0, j = 0, n = pals.size();
    int count = 0;

    while (j < n) {
        while (j < n and pals[j] - pals[i] <= C) j++;
        count = max(count, j - i);
        i++;
    }

    count = max(count, j - i);
    return count;
}
