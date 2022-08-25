#define ll long long

class Solution {
public:
    
    void MERGE(ll low, ll mid, ll high, vector<int>&nums, ll &rvrsPairCnt){
        
        ll i=low;
        ll j=mid+1;
        ll k=low;
        ll counter=0;
        
        while(i<=mid){
            while(j<=high && nums[i] > (ll)2*nums[j]){
                counter++;
                j++;
            }
            i++;
            rvrsPairCnt += counter;
        }
        
        ll temp[high+1];
        i=low;
        j=mid+1;
        k=low;
        
        while(i<=mid && j<=high){
            
            if(nums[i]<=nums[j]){
                temp[k]=nums[i];
                i++;
                k++;
            }
            else{
                temp[k]=nums[j];
                j++;
                k++;
            }
        }
        
        while(i<=mid){
            temp[k]=nums[i];
            i++;
            k++;
        }
        
        while(j<=high){
            temp[k]=nums[j];
            j++;
            k++;
        }
        
        
        for(int i=low; i<=high; i++){
            nums[i]=temp[i];
        }    
    }
    
    
    void mergeSort(ll low, ll high, vector<int>&nums, ll &rvrsPairCnt){
        
        if(low<high){
            
            ll mid = low + (high-low)/2;
            
            mergeSort(low, mid, nums, rvrsPairCnt);
            mergeSort(mid+1, high, nums, rvrsPairCnt);
            
            MERGE(low, mid, high, nums, rvrsPairCnt); 
        }
        
    }
    
    
    
    
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        ll rvrsPairCnt=0;
        mergeSort(0, n-1, nums, rvrsPairCnt);
        return rvrsPairCnt;
    }
};