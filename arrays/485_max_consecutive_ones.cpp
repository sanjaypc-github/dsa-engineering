/*
Problem: max Consecutive Ones
Platform: LeetCode
Difficulty:easy

Approach 1: Brute force Approach
Time Complexity:O(n^3)
Space Complexity:O(1)

----------------------------------

Approach 2: Running Counter
Time Complexity:O(n)
Space Complexity:O(1)
----------------------------------

Approach 3:Sliding window Approach 
Time Complexity:O(n)
Space Complexity:O(1)
----------------------------------

*/
//brute force
using 3 for loops 

//Running counter
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                sum++;
                maxi=max(sum,maxi);
            }
            else{
                sum=0;
            }

        }
        return maxi;
    }
};

//Sliding window
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                continue;
            }
            if(j>0 &&nums[j]==1 && nums[j-1]==0){
                i=j;

            }
            maxi=max(maxi,j-i+1);

        }
        return maxi;
    }
};