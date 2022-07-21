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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head or left == right)
            return head;
        
        if(left==right){
            return head;
        }
        
        ListNode* temp=new ListNode();
        temp->next=head;
        ListNode* prev=temp;
        ListNode* curr=temp;
        ListNode* nex=temp;
        
        int cnt=1;
        
        while(cnt<left){
            prev=prev->next;
            cnt++;
        }
        
        //prev=temp;
        curr=prev->next;
        nex=curr->next;
            
            for(int i=1; i<=(right-left); i++){
                    
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next = nex;
                nex = curr->next;
            } 
        
        return temp->next;
        
        
    }
};