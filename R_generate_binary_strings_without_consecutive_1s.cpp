class Solution {
public:
    void generate(int n,string curr, vector<string> &ans){
        if(curr.length() == n){
            ans.push_back(curr);
            return;
        }

        generate(n,curr+'0',ans);
        if(curr.empty()|| curr.back()!= '1'){
            generate(n,curr+'1',ans);
        }

    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        generate(n,"",ans);
        return ans;
    }
};
