#define ll long long

class Solution {
public:
    
    void Merge(ll low, ll mid, ll high, vector<int>&nums, ll &ans){
        
        ll i=low;
        ll k=low;
        ll j=mid+1;
        
        ll counter=0;
        while(i<=mid){
            while(j<=high &&  nums[i] > (ll)2*nums[j]){
                counter++;
                j++;
            }
            i++;
            ans+=counter;
        }
        
        
        i=low;
        k=low;
        j=mid+1;
        ll b[high+1];
        
        while(i<=mid && j<=high){
            
            if(nums[i]>nums[j]){
                
                b[k]=nums[j];
                k++;
                j++;
            }
            else{
                b[k]=nums[i];
                k++;
                i++;
            } 
        }
        
        while(i<=mid){
            b[k]=nums[i];
            i++;
            k++;
        }
        
        while(j<=high){
            b[k]=nums[j];
            j++;
            k++;
        }
        
        
        for(int i=low; i<=high; i++){
            nums[i]=b[i];
        } 
    }
    
    
    
    
    
    void mergeSort(ll i, ll j, vector<int>&nums, ll &ans){
        
        if(i<j){
            
            ll mid = i + (j-i)/2;
            
            mergeSort(i, mid, nums, ans);
            mergeSort(mid+1, j, nums, ans);
            
            Merge(i, mid, j, nums, ans);
        }
        
        
    }
    
    int reversePairs(vector<int>& nums) {
        
        int n=nums.size();
        ll ans=0;
        mergeSort(0, n-1, nums, ans);
        
        return ans;
      
    }
};