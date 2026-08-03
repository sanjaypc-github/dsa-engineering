/*
Problem: Missing Numberr
Platform: LeetCode
Difficulty:easy

Approach 1:  sum formula n*(n+1)/2
Time Complexity:O(n)
Space Complexity:O(1)

----------------------------------

Approach 2: using the hashset 
Time Complexity:O(n)
Space Complexity:O(n)
----------------------------------

Approach 3:using xor
Time Complexity:O(n)
Space Complexity:O(1)
----------------------------------

*/
//Approach 1 - sum formula n*(n+1)/2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        int tot =0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
        }

        
        return sum-tot;
    }
};

//using the hashset 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> st;
        int n= nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<=n;i++){
            if(st.count(i)!=1){
                return i;
            }
        }
        return 0;
    }
};

//using xor
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // xor of all numbers + its index from 0 to n gives the remaining 
        int xr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xr ^= i;
            xr ^= nums[i];
        }
        xr^=n;
        
        return xr;
    }
};