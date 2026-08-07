class Solution {
public:
    void generate(int index, string &s, string curr, set<string> &ans){
        if(index == s.size()){
            if(curr == ""){
                return;
            }
            ans.insert(curr);
            return;
        }
        curr.push_back(s[index]);
        generate(index+1, s,curr,ans);

        curr.pop_back();
        generate(index+1 , s, curr, ans);

    }
    int distinctSubseqII(string s) {
        int MOD = 1000000007;
        set<string> ans;
        string curr ="";

        generate(0,s,curr,ans);

        int n = ans.size()%MOD;
        return n;

    }
};
