int getFirstSetBit(int num) {
    int pos = 0;
    while ((num & 1) == 0) {
        pos++;
        num = num >> 1;
    }
    return pos;
}

int *findTwoElement(int *arr, int n) {
    int *result = new int[2];
    int XOR = 0;

    // Xor all a[i]
    for (int i = 0; i < n; i++)
        XOR ^= arr[i];

    // Xor all (1..n)
    for (int i = 1; i <= n; i++)
        XOR ^= i;

    // Effectively, xor holds X ^ Y (Missing ^ Repeating)
    // Find the first set bit of XOR for segregation
    int ith_set_bit = getFirstSetBit(XOR);

    // Segregate based on ith_set_bit status
    int X = 0, Y = 0;

    for (int i = 0; i < n; i++) {
        if ((arr[i] & (1 << ith_set_bit)) > 0)
            X ^= arr[i];
        else
            Y ^= arr[i];
    }

    // Segregate (1..n) based on ith_set_bit status
    for (int i = 1; i <= n; i++) {
        if ((i & (1 << ith_set_bit)) > 0)
            X ^= i;
        else
            Y ^= i;
    }

    // Find which one is missing and repeating
    // Store repeating in X and missing in Y
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == X)
            count++;
    }

    if (count == 0) {
        // Means X is missing. put it in Y
        swap(X, Y);
    }

    // Store repeating in [0] and missing in [1]
    result[0] = X;
    result[1] = Y;

    return result;
}