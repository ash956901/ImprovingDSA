class Solution {
public:
    void merge(vector<int> &arr,int low ,int mid ,int high){
        vector<int> temp;
        int i=low;
        int j=mid+1;
        
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }   
        }
        
        while(i<=mid){
                temp.push_back(arr[i]);
                i++;
        }
        
        while(j<=high){
                temp.push_back(arr[j]);
                j++;
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
    int countPairs(vector<int> &arr,int low,int mid,int high){
        int count=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && arr[i]>(long long) 2*arr[right]){
                right++;
            }
            count+=(right-mid-1);
        }
        return count;
    }
    int mergeInversion(vector<int> &arr,int low ,int high){
        if(low>=high) return 0;
        int count=0;
        int mid=(low+high)/2;
        count+=mergeInversion(arr,low,mid);
        count+=mergeInversion(arr,mid+1,high);
        count+=countPairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& arr) {
         return mergeInversion(arr,0,arr.size()-1);
    }
};

