/*
Problem: Subsets
Platform: LeetCode
Difficulty:medium

Approach 1: Recursion(backtracking)
Time Complexity:O(n^2)
Space Complexity:O(1)

----------------------------------

Approach 2:Bit manupulation
Time Complexity:O(n)
Space Complexity:O(1)


*/
//recursion Approach
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx , vector<int>& nums ,  vector<int>& temp){
        if(idx==nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        solve(idx+1 ,nums,temp);

        temp.pop_back();
        solve(idx+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0,nums,temp);
        return ans;
    }
};

//bit manupulation approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int mask=0;mask<(1<<n);mask++){
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans; 
    }
};