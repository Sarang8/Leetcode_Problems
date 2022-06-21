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
    struct compr{
       bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }
    } ;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, compr>minHeap;
        ListNode* head= new ListNode(0);
        ListNode* temp = head;
        
        for(int i=0; i<n; i++){
            if(lists[i]!=NULL)
              minHeap.push(lists[i]);
        }
        
        
        while(!minHeap.empty()){
            
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            temp->next = smallest;
            temp=temp->next;
            
            if(smallest->next){
                minHeap.push(smallest->next);
            }
        }
        return head->next;
        
    }
};