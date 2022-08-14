int Solution::isValidSudoku(const vector<string> &matrix) {
    vector<unordered_set<char>> rows(9), cols(9), blocks(9);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // Validate only for filled cells
            if (matrix[i][j] != '.') {
                char ch = matrix[i][j];

                if (rows[i].count(ch) || cols[j].count(ch) || blocks[i / 3 * 3 + j / 3].count(ch))
                    return false;

                rows[i].insert(ch);
                cols[j].insert(ch);
                blocks[i / 3 * 3 + j / 3].insert(ch);
            }

        }
    }

    return true;
}
