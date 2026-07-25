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
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow== fast){

                slow = head; // finding the starting point but not necessary here
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
    
                }
                int count =1;
                slow = slow->next;
                while(slow != fast){
                    count++;
                    slow = slow->next;
                }
            return count;
        }
    }
    return 0;
    }
};
