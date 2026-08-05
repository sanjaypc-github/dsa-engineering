/*
Problem: max Consecutive Ones
Platform: LeetCode
Difficulty:easy

Approach 1: Brute force Approach
Time Complexity:O(n^2)
Space Complexity:O(1)

----------------------------------

Approach 2: Kedans Algorithm
Time Complexity:O(n)
Space Complexity:O(1)


*/

// brute force approach- cause TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n=nums.size();
   
    int maxi=nums[0];
    for(int i=0;i<n;i++){
         int curr_sum=0;
        for(int j=i;j<n;j++){
            curr_sum+=nums[j];
            maxi=max(maxi,curr_sum);
        }
    }
    return maxi;
    }
};

//Kedans Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n=nums.size();
      int curr_sum=nums[0];
      int maxi=nums[0];
      for(int i=1;i<n;i++){
        curr_sum=max(nums[i],curr_sum+nums[i]);
        maxi = max(maxi,curr_sum);
      }
      return maxi;
    }
};