// Recursive Approach: T.C -> O(n^2)
void insertInSortedStack(stack<int> &st, int key) {
    if (st.empty() == true or st.top() <= key) {
        st.push(key);
        return;
    }

    int element = st.top();
    st.pop();

    insertInSortedStack(st, key);
    st.push(element);
}
void sortStack(stack<int> &st)
{
    if (st.empty() == true or st.size() == 1) return;

    int element = st.top();
    st.pop();

    sortStack(st);
    insertInSortedStack(st, element);
}

// Iterative Approach: T.C -> O(n^2)
void sortStack(stack<int> &input)
{
    stack<int> output;         // COntains elements in sorted decreasing order

    while (!input.empty()) {
        int element = input.top();
        input.pop();

        while (!output.empty() and output.top() > element) {
            input.push(output.top());
            output.pop();
        }

        output.push(element);
    }

    input = output;
}