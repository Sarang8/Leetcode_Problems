// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    
    //Function to insert heap.
    void insertHeap(int &num)
    {
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
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
        
    }
    
    //Function to return Median.
    double getMedian()
    {
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


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends