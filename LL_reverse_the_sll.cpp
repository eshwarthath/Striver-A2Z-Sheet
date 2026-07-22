/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* next = nullptr;

        while(temp!=nullptr){
            next = temp->next;    // Store the next node

            temp->next = prev;    // Reverse the link

            prev = temp;          // Move prev forward

            temp = next;          // Move curr forward
        }
        return prev;
    }
};
