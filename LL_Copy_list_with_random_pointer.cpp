/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
            return NULL;

        Node* temp = head;

        // Step 1: Insert copy nodes in between original nodes
        while(temp != NULL) {

            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;

            temp = temp->next->next;
        }

        // Step 2: Copy random pointers
        temp = head;

        while(temp != NULL) {

            if(temp->random != NULL)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        // Step 3: Separate the two lists
        temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while(temp != NULL) {

            res->next = temp->next;
            temp->next = temp->next->next;

            res = res->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};
