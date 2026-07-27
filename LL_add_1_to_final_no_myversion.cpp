/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* next = nullptr;

        while(temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;

        }
        return prev;
    }

    ListNode *addOne(ListNode *head) {
        head = reverse(head);
        
        ListNode* temp = head;
        int carry = 1;
        
        while(temp!=nullptr){
            temp->val = temp->val+ carry ;
            if(temp->val <10){
                carry = 0;
                break;
            }else{
                temp->val = 0;
                carry =1;
            }
            temp = temp->next;
        }

        if(carry ==1){
            head = reverse(head);
            ListNode* newhead = new ListNode(1);
            newhead->next = head;
            return newhead;
        }
        head = reverse(head);
        return head;
    }
};




