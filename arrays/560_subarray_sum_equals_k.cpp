/*
Problem: max Consecutive Ones
Platform: LeetCode
Difficulty:easy

Approach 1: Brute force Approach
Time Complexity:O(n^2)
Space Complexity:O(1)

----------------------------------

Approach 2:Prefix sum + hashmap
Time Complexity:O(n)
Space Complexity:O(n)
----------------------------------


*/

//brute force

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                  cnt++;  
                }

            }
        }
        return cnt;
    }
};

//better approach

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pref_sum=0;
        int cnt=0;
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            pref_sum+=nums[i];
            int rem=pref_sum-k;
            cnt+=mpp[rem];
            mpp[pref_sum]+=1;
        }
        return cnt;
    }
};