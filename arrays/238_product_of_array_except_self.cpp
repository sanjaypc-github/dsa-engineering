/*
Problem: max Consecutive Ones
Platform: LeetCode
Difficulty:easy

Approach 1: Brute force Approach
Time Complexity:O(n^2)
Space Complexity:O(n)

----------------------------------

Approach 2:better approach
Time Complexity:O(n)
Space Complexity:O(n)
----------------------------------

Approach 3:optimal approach 
Time Complexity:O(n)
Space Complexity:O(1)
----------------------------------

*/
//better approach

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>lp(n);
        lp[0]=1;
        vector<int>rp(n);
        rp[n-1]=1;
        vector<int>ans(n);
        for(int i=1;i<n;i++){
            lp[i]=lp[i-1]*nums[i-1];
            
        }
        for(int i=n-2;i>=0;i--){
            rp[i]=rp[i+1]*nums[i+1];
            
        }
        for(int i=0;i<n;i++){
             ans[i]=lp[i]*rp[i];
           
        }
        return ans;

    }
};
/*using 3 for loops 
-one for calculating left prdt of index i : lp[i]=lp[i-1]*nums[i-1]
-one for right prdt for index i: rp[i]=rp[i+1]*nums[i+1]
-one for doing the prdt of both vector with index i and return ans vector
-note :- dont do push back in any vectors  whenit is asigned a size lp(n)
- just assign the value like lp[i]= ___ this is enough as we already assigned the size if we push back the n+1 value or size is created 
*/ 

//optimal solution 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int rp=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=rp;
            rp*=nums[i];
        }

        return ans;

    }
};
