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
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL  or head->next==NULL){
            return NULL;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        
        while(fast->next  and fast->next->next){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                while(slow!=temp){
                    slow=slow->next;
                    temp=temp->next;
                }
                return temp;
            }
            
        }
        return NULL;


        
    }
};