#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
        int i =0;
        int j=nums.size()-1;
        while(j>=i){
            int mid= i + (j - i) / 2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[i]<=nums[mid]){
                if(target < nums[mid] && target >= nums[i]){
                    j=mid-1;
                }else{
                    i=mid+1;
                }
            }else if(nums[j]>=nums[mid]){
                if(target > nums[mid] && target<=nums[j]){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }
        }
        return -1;
    } 

int main()
{
    vector<int> v={4,5,6,7,0,1,2};
    int target=0;
    cout<<search(v,target); 
    return 0;
}