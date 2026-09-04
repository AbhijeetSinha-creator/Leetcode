/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr = headA;
        unordered_map<ListNode*,bool> m;
        while(curr != NULL){
            m[curr] = 1;
            curr = curr->next;
        } 
        curr = headB;
        while(curr != NULL){
            if(m[curr] == 1) return curr;
            curr = curr->next;
        }
        return NULL;
    }
};