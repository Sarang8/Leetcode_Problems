//#define ll long long

class MinStack {
public:
    stack<long long>st;
    long long mini;
    
    
    MinStack() {
        while(st.empty()==false)  st.pop();
        mini=INT_MIN;
    }
    
    void push(int val) {
        
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<mini){  
                st.push( 2*(long long)val - mini );
                mini = val;
            }
            else{
                st.push(val);
            }
        }  
    }
    
    
    void pop() {
        
        if(st.empty()) return;
        
        
        long long ele=st.top();
        st.pop();
        
        if(ele<mini){
            mini = 2*mini - ele;
        }
    }
    
    
    int top() {
        if(st.empty()) return -1;
        
        long long ele = st.top();
        
        if(ele<mini){
            return mini;
        }
        return ele;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */