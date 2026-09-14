class Solution {
public:
    void insert(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        insert(st,x);
        st.push(temp);

    }

    void reverseStack(stack<int> &st) {
        if(st.empty()){
            return;
        }
        int temp = st.top();
        st.pop();

        reverseStack(st);

        insert(st,temp);
    }
    
};
