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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* lesser = new ListNode (0);
        ListNode* greater = new ListNode (0);
        ListNode* lesserHead=lesser;
        ListNode* greaterHead=greater;
        
        while(head){
            
            if(head->val<x){
                lesser->next=head;
                lesser=lesser->next;
            }
            else{
                greater->next=head;
                greater=greater->next;
            }
            
            head=head->next;   
        }
        
        lesser->next=greaterHead->next;
        greater->next=NULL;
        return lesserHead->next;
    }
};