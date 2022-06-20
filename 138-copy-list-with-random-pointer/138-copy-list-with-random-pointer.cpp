/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        
        //STEP 1
        Node* temp = head;
        Node* nex = head;
        while(temp!=NULL){
            nex = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nex;
            temp = nex;
        }
        
        
        //STEP 2
        temp = head;
        while(temp!=NULL){
            if(temp->random!=NULL){
                
                temp->next->random = temp->random->next;                
            }
             temp = temp->next->next;
        }
        
        //Step 3
        temp=head;
        Node* dummy=new Node(0);
        Node* copyFnl = dummy;
        
        while(temp!=NULL){
            nex = temp->next->next;
            copyFnl->next = temp->next;
            temp->next = nex;
            copyFnl=copyFnl->next;
            temp=nex;
        }
        return dummy->next;    
    }
};