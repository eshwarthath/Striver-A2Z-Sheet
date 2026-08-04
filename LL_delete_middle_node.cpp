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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            head = nullptr;
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next->next != nullptr && fast->next->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;

        return head;

    }
};
