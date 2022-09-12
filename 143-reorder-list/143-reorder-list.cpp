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
    void reorderList(ListNode* head) {
        
        if(head==NULL or head->next==NULL or head->next->next==NULL){
            return;
        }
        
        stack<ListNode*>st;
        
        ListNode* temp1=head;
        int length=0;
        
        while(temp1){
            
            st.push(temp1);
            temp1=temp1->next;
            length++;
            
        }
        
        
        ListNode* temp2 = head; 
        
        for(int i=0; i<length/2 ; i++){
            
            ListNode* ele = st.top();
            st.pop();
            ele->next = temp2->next;
            temp2->next = ele;
            temp2=temp2->next->next;
            
        }
        
        temp2->next=NULL;

    }
};