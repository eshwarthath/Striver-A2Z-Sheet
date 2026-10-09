class Solution {
public:
    bool isPalindrome(string s, int index, int i) {
        while (index < i) {
            if (s[index] != s[i])
                return false;
            index++;
            i--;
        }
        return true;
    }

    void solve(string s, int index, vector<string>& temp,
               vector<vector<string>>& ans) {
        
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1)); // gives the substring

                solve(s, i + 1, temp, ans);

                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, 0, temp, ans);

        return ans;
    }
};
