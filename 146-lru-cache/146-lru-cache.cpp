class LRUCache {
public:
    
    class node{
    public:
        
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };
    
    
    unordered_map<int, node*>m;
    int cap;
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* newnode){
        node* temp = head->next;
        head->next=newnode;
        newnode->next=temp;
        temp->prev=newnode;
        newnode->prev=head;
    }
    
    
    
    
    void deletenode(node* delnode){
      
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;   
    }
    
    
    
    
    
    
    int get(int key) {
        
        if(m.find(key)!=m.end()){
            
            node* resnode=m[key];
            int res = resnode->val;
            deletenode(resnode);
            addnode(resnode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end()){
            node* existingNode=m[key];
            m.erase(key);
            deletenode(existingNode);
        }
        
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key, value));        
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */