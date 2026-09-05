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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        vector<int> v;
        ListNode *curr1 = head;
        ListNode *curr2 = head->next;
        while(curr2){
            if(curr2->val != curr1->val){
                v.push_back(curr1->val);
                curr1 = curr2;
                curr2 = curr2->next;
            }
            else{
                int x = curr1->val;
                while(curr1 != NULL && curr1->val == x){
                    curr1 = curr1->next;
                }
                if(curr1 == NULL) break;
                curr2 = curr1->next;
            }
        }
        if(curr2 == NULL && curr1 != NULL) v.push_back(curr1->val);
        if(v.size() ==  NULL) return NULL;
        curr1 = head;
        int i = 0;
        while(i < v.size()){
            curr1->val = v[i];
            if(i != v.size()-1) curr1 = curr1->next;
            i++;
        }
        curr1->next = NULL;
        return head;
    }
};