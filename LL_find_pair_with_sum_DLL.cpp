/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {

        vector<vector<int>> ans;

        if(head == NULL)
            return ans;

        ListNode* left = head;
        ListNode* right = head;

        // Move right to the last node
        while(right->next != NULL) {
            right = right->next;
        }

        // Two Pointer Approach
        while(left != right && left->prev != right) {

            int sum = left->val + right->val;

            if(sum == target) {
                ans.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            }
            else if(sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return ans;
    }
};
