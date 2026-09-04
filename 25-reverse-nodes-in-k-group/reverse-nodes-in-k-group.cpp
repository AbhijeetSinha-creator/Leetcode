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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *curr = head;
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        count = count - (count % k);
        ListNode *first = new ListNode(0);
        first->next = head;
        head = first;
        while(count){
            ListNode* second = first->next;
            ListNode *prev = first;
            curr = first->next;
            ListNode *future;
            for(int i=1;i<=k && count;i++){
                future = curr->next;
                curr->next = prev;
                prev = curr;
                curr = future;
                count--;
            }
            first->next = prev;
            second->next = curr;
            first = second;
            second = curr;
        }
        curr = head;
        head = head->next;
        delete curr;
        return head;
    }
};