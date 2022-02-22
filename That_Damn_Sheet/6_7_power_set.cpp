// T.C -> O(n * 2^n) + O(N log N) where N = 2^n
class Solution {
public:
	vector<string> AllPossibleStrings(string s) {
		vector<string> res;
		int n = s.length();

		// There are total of 2^n subsets
		for (int i = 0; i < (1 << n); i++) {
			int subset = i;
			string str = "";

			// Indicies lies from 0..n-1
			for (int j = 0; j < n; j++) {
				int isBitSet = (subset & (1 << j));
				if (isBitSet > 0)
					str += s[j];
			}

			if (str != "")
				res.push_back(str);
		}

		sort(res.begin(), res.end());
		return res;
	}
};