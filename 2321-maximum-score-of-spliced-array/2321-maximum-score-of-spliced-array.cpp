class Solution {
public:
    
    long long kadane(vector<long long>a){
        
        int n = a.size();
        long long maxi= INT_MIN;
        long long CurrSum=0;
        
        for(int i=0; i<n; i++){
            CurrSum+=a[i];
            
            maxi =max(maxi, CurrSum);
            
            if(CurrSum<0){
                CurrSum=0;
            }
        }
        return maxi;
    }
    
    
    long long Getsum(vector<int>v){
        long long sum = 0;
        for(int i=0; i<v.size(); i++){
            sum+=v[i];
        }
        return sum;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        int n= nums1.size();
        vector<long long>diff1(n);
        vector<long long>diff2(n);
        
        for(int i=0 ;i<n; i++){
            diff1[i] = nums1[i]-nums2[i];
            diff2[i] = nums2[i]-nums1[i]; 
        }
        
        long long s1 = Getsum(nums1) + kadane(diff2);
        long long s2 = Getsum(nums2) + kadane(diff1);
        
        return max(s1,s2);
     
    }
};