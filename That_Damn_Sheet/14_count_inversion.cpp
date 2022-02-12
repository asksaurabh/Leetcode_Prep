long long merge(long long *arr, long long *temp, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;
    long long count = 0;

    while (i <= mid and j <= end) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            count += (mid + 1) - i;         // (start of right subarray - curr i which is greater)
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];

    // In curr call u were operating btw indicies [start..end]
    for (int i = start; i <= end; i++)
        arr[i] = temp[i];

    return count;
}

long long mergeSort(long long *arr, long long *temp, int start, int end) {
    long long invCount = 0;
    if (end > start) {
        int mid = start + (end - start) / 2;

        invCount += mergeSort(arr, temp, start, mid);
        invCount += mergeSort(arr, temp, mid + 1, end);
        invCount += merge(arr, temp, start, mid, end);
    }

    return invCount;
}

long long getInversions(long long *arr, int n) {
    long long temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}