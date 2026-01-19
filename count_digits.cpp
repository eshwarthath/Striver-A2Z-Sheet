class Solution {
public:
    int countDigit(int n) {
        int digits = 0;
        for (i=0; i<n; i++){
            digits+=1;
        }
        return digits;
    }
};
int main(){
    Solution sr;
    string s[20];
    cin>>s;

    int n = stoi(s);

    sr.countDigit(s);

    return 0;

}
