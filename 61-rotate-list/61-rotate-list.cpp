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
    ListNode* rotateRight(ListNode* head, int k) {
        
        
        if(head==NULL){
            return head;
        }
        
        ListNode* temp = head;
        int len=1;
        
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        
        k = k%len;
        
        if(k==0){
            return head;
        }
        
        temp->next = head;   //LAST NODE POINT TO HEAd
        
        int reach = len - k;
        
        while(reach>0){
            temp = temp->next;
            reach--;
        }
        
        head = temp->next;
        temp->next = NULL;
        return head;
        
        
        
//         if(!head or !head->next or k==0){
//             return head;
//         }
        
//         //COMPUTE THE LENGTH
//         ListNode* temp=head;
//         int length=1;
        
//         while(temp->next!=NULL){
//             temp=temp->next;
//             length++;
            
//         }
        
//         temp->next=head;
        
//         k=k%length;
        
//         int k2 = length-k;
        
//         while(k2>0){
//             temp=temp->next;
//             k2--;
//         }
        
//         //make the node head and break connection
//         head=temp->next;
//         temp->next=NULL;    
        
        
//         return head;
        
   }
};