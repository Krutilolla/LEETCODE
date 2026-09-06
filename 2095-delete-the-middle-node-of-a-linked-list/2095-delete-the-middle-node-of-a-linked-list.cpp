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
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return NULL;
        }
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        ListNode* n = head;
        ListNode* m = head->next;
        while(n->next!=NULL && m->next!=NULL &&  m->next->next!=NULL){
            m = m->next->next;
            n = n->next;
        }
        n->next = n->next->next;
        return head;
    }
};