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
    ListNode* oddEvenList(ListNode* head) {
       
        if(head==NULL) return NULL;
        if(head->next==NULL or head->next==NULL) return head;
        
        
        
        ListNode* temp1=head;
        ListNode* temp2=head;
        temp2=temp2->next;
        ListNode* temp3=temp2;
        
        while(temp1->next && temp2->next){
            
            if(temp2->next!=NULL){
               temp1->next=temp2->next;
                temp1=temp1->next;  
            }
           
            if(temp1->next!=NULL){
                temp2->next=temp1->next;
                temp2=temp2->next;
            }
            
        }
        temp2->next=NULL;
        temp1->next=temp3;
        return head;
        
//         if(!head || !head->next || !head->next->next) return head;

//         ListNode *odd = head, *even = head->next, *even_head = head->next;
        
//         while(odd->next && even->next) {
//             odd->next = odd->next->next;
//             even->next = even->next->next;
//             odd = odd->next;
//             even = even->next;
//         }
        
//         odd->next = even_head;
//         return head;
        
    }
};