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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp=head;
        
        int length=0;
        
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        
        if(length==n){
            return head->next;
        }
        
        int reach = length - n ;
        //int reach = frmStart-1;
        temp=head;
        
        while(reach>1){
            temp=temp->next;
            reach--;
        }
        
        temp->next =temp->next->next;
        
        return head;
    }
};