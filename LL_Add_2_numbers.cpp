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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0); // it's like 0->sum->sum->nullptr where we took sum has head.
        ListNode* temp = dummy;

        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry)
        {
            int sum = carry;

            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; //suppose sum = 10 means carry = 10/10 which is 1.

            temp->next = new ListNode(sum % 10); // this creates new next node and then we store the sum.
            temp = temp->next; //we move to next new node.
        }

        return dummy->next;
    }
};
