void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> temp;

    int i = 0, j = 0;
    while (i < A.size() and j < B.size()) {
        if (A[i] <= B[j]) {
            temp.push_back(A[i]);
            i++;
        }
        else if (A[i] > B[j]) {
            temp.push_back(B[j]);
            j++;
        }
    }

    while (i < A.size()) temp.push_back(A[i++]);
    while (j < B.size()) temp.push_back(B[j++]);

    A = temp;
}
