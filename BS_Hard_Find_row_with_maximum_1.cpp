class Solution {
  public:   
  
  int lowerbound(vector<int> &arr, int n, int x){
        int low =0; int high = n-1; int ans = n;
        while(low<=high){
            int mid = (low + high)/2;
            if(arr[mid]>= x){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
  }

  int rowWithMax1s(vector < vector < int >> & mat) {
        int n = mat.size(); // it counts the rows;
        int m = mat[0].size(); // it counts how many elements that is coulms;

        int index =-1;
        int maxcount =0;
        for(int i=0; i<n; i++){

            int countones = m - lowerbound(mat[i], m, 1);

            if(countones>maxcount){
                maxcount = countones;
                index =i;
            }
        }
        return index;
  }
};
