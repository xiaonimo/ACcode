class Solution {
public:
    string reverseString(string s) {
        if (s.empty()) {
			return s;
		}
        string a = "";
		for (unsigned int i = s.size(); i > 0; --i) {
			a.append(1, s[i - 1]);
		}

		return a;
    }
};