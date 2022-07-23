class Solution {
public:
    void Merge(vector<pair<int,int>>&v, vector<int>&count, int left, int mid, int right){
        
        int i=left;
        int k=0;
        int j=mid+1;
        vector<pair<int,int>>temp(right-left+1);
        
        
        while(i<=mid && j<=right){
            
            
            if((v[i].first<=v[j].first)){
                temp[k] = v[j];
                k++;
                j++;
            }
            else {
                count[v[i].second]+= right-j+1;
                temp[k]=v[i];
                k++;
                i++;
            }

        }
        
        while(i<=mid){
            temp[k]=v[i];
            k++;
            i++;
        }
        
        while(j<=right){
            temp[k]=v[j];
            k++;
            j++;
        }
        
        for(int i=left; i<=right; i++){
            v[i] = temp[i-left];
        }
        
    }
    
    
    void mergeSort(vector<pair<int,int>>&v, int left, int right, vector<int>&count){
        
        if(left<right){
            
            int mid = left+ (right-left)/2;
            
            mergeSort(v, left,mid,count);
            mergeSort(v, mid+1, right, count);
            Merge(v,count, left, mid, right);
        }
        
        
        
    }
    
    
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<pair<int,int>>v(n);
        
        for(int i=0; i<n;i++){
            v[i] = {nums[i], i};
        }
        
        vector<int>count(n,0);
        mergeSort(v, 0, n-1, count);
        return count;
        
//     void merge(vector<int> &count, vector<pair<int, int>> &v, int low, int mid, int high)
//     {
//         vector<pair<int, int>> temp(high - low + 1);
        
//         int i = low;
//         int j = mid + 1;
//         int k = 0;

//         while (i <= mid && j <= high)
//         {

//             if (v[i].first <= v[j].first)
//             {
//                 temp[k++] = v[j++];
//             }

//             else
//             {
// //             it means all elements to right will be smaller bcz here we're sorting in decending format
//                 count[v[i].second] += high - j + 1;
//                 temp[k++] = v[i++];
//             }
//         }

//         while (i <= mid)
//         {
//             temp[k++] = v[i++];
//         }

//         while (j <= high)
//         {
//             temp[k++] = v[j++];
//         }
        
// //         changing the original array
        
//         for (int i = low; i <= high; i++)
//         {
//             v[i] = temp[i - low];
//         }
//     }

//     void mergeSort(vector<int> &count, vector<pair<int, int>> &v, int low, int high)
//     {
// //      simple merge sort no change at all
//         if (low < high)
//         {
//             int mid = low + (high - low) / 2;
//             mergeSort(count, v, low, mid);
//             mergeSort(count, v, mid + 1, high);
//             merge(count, v, low, mid, high);
//         }
//     }

//     vector<int> countSmaller(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<pair<int, int>> v(n);
// //          we'll have to also maintain the index to increse the count
        
//         for (int i = 0; i < n; i++)
//         {
//             // pair<int, int> p;
//             // p.first = nums[i];
//             // p.second = i;
//             // v[i] = p;
//             v[i] = {nums[i], i};
//         }

//         vector<int> count(n, 0);
//         mergeSort(count, v, 0, n - 1);
//         return count;
        
    }
};