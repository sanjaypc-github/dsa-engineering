/*
Problem: Rotate Array
Platform: LeetCode
Difficulty:Medium 

Approach 1: Better 
Time Complexity:O(n)
Space Complexity:O(n)

----------------------------------

Approach 2: using reverse with the k values (3 reverse is used)
Time Complexity:O(n)
Space Complexity:O(1) as only 2 variables are used 

----------------------------------

*/
//optimal 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

//better approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[(i+k)%n]=nums[i];
        }
        nums=temp;
    }
};

