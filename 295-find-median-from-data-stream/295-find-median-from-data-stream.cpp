class MedianFinder {
public:
    
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxHeap.size()==0){
            maxHeap.push(num);
        }
        
        else if(maxHeap.size()==minHeap.size()){
            if(num>=minHeap.top()){
                
                int temp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
            else if(num<minHeap.top()){
                maxHeap.push(num);
            }   
        }
        
        
        else{
            if(minHeap.size()==0){
                
                if(num<=maxHeap.top()){
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
                else{
                        minHeap.push(num);
                    }
            }
            else if(num>=minHeap.top()){
                    minHeap.push(num);
                }
            else 
            {
                if(num<maxHeap.top()){
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
                else
                    minHeap.push(num);   

                
            }
        }
        return;
    }
    
    
    
    
    double findMedian() {
        
        int ls = maxHeap.size();
        int rs = minHeap.size();
        
        if(ls==rs){
            return ((double)(maxHeap.top()) + (double)(minHeap.top()))/2.0; 
        }
        else{
            return maxHeap.top();
        }
        
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */