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
    
    ListNode*reverse(ListNode*head){
        
        ListNode* dummy=NULL;
        
        while(head!=NULL){
            ListNode* nex= head->next;
            head->next=dummy;
            dummy=head;
            head=nex;
        }
        
        return dummy;        
    }
    
    
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL or head->next==NULL){
            return true;
        }
        
        ListNode* slow=head;
        ListNode* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }       
        
        
        slow->next = reverse(slow->next);
        slow=slow->next;
        ListNode* temp=head;
        
        while(slow!=NULL){
            if(slow->val!=temp->val){
                return false;
            }
            temp=temp->next;
            slow=slow->next;
        }
        
        return true;
         
        
//         if(head==NULL or head->next==NULL){
//             return true;
//         }
        
//         ListNode* slow= head;
//         ListNode* fast=head;
        
//         while(fast->next!=NULL and fast->next->next!=NULL){
            
//             slow=slow->next;
//             fast=fast->next->next;
            
//         }
        
//         slow->next = reverselist(slow->next);
//         slow=slow->next;
        
        
//         while(slow!=NULL){
            
//             if(head->val != slow->val){
//                 return false;
//             }
            
//             head = head->next;
//             slow = slow->next;
//         }
//         return true;
//     }
    
    
//     ListNode* reverselist(ListNode* head){
        
//         ListNode* pre=NULL;
//         ListNode* next=NULL;
        
//         while(head!=NULL){
//             next = head->next;
//             head->next = pre;
//             pre = head;
//             head = next;
//         }
//         return pre;
        
        
    }
};