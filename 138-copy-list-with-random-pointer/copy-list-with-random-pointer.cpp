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
        // Creating Copy of LL without random pointer
        Node *headcopy = NULL;
        Node *tailcopy = NULL;
        Node *temp = head;
        while(temp != NULL){
            if(headcopy == NULL){
                headcopy = new Node(temp->val);
                tailcopy = headcopy;
            }
            else{
                tailcopy->next = new Node(temp->val);
                tailcopy = tailcopy->next;
            }
            temp = temp->next;
        }
        temp = head;
        tailcopy = headcopy;
        // Storing node address of original LL with its corresponding node address of copied LL in unordered map
        unordered_map<Node*, Node*> m;
        while(temp != NULL){
            m[temp] = tailcopy;
            tailcopy = tailcopy->next;
            temp = temp->next;
        }
        // Assigning to random pointer in copied LL
        temp = head;
        tailcopy = headcopy;
        while(temp != NULL){
            tailcopy->random = m[temp->random];
            tailcopy = tailcopy->next;
            temp = temp->next;
        }
        return headcopy;
    }
};