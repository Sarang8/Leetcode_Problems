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
        
//         ListNode* slow=head;
//         ListNode* fast=head;
//         ListNode* pre=new ListNode(0);
//         pre->next=slow;
        
//         if(head==NULL or head->next==NULL){
//             return NULL;
//         }
        
//         int len=0;
//         ListNode* temp=head;
//         while(temp){
//             len++;
//             temp=temp->next;
//         }
        
//         while(fast->next && fast->next->next){
            
//             slow=slow->next;
//             pre=pre->next;
//             fast=fast->next->next;
//         }
        
//         if(len%2==0){
//             slow->next=slow->next->next;
//         }
//         else{
//             pre->next=slow->next;
//         }
        
//         return head;
        
        if(head==NULL or head->next==NULL){
            return NULL;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre;
        
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        pre->next=slow->next;
        return head;
        
        
    }
};