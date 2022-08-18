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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL){
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = dummy;
        ListNode* nex = dummy;
        
        int length=0;
        
        while(curr->next!=NULL){
            length++;
            curr = curr->next; 
        }
         
        
        
        while(length>=2){
            
            curr = prev ->next;
            nex = curr->next;
            
            for(int i=1; i<2; i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            
            prev = curr;
            length=length-2;
        }
        
        return dummy->next;
    }
};