/*
Problem: group anagram
Platform: LeetCode
Difficulty:medium

Approach 1: Brute force Approach
Time Complexity:O(n * nlog n)
Space Complexity:O(n*k)

----------------------------------

Approach 2: 
Time Complexity:O(n)
Space Complexity:O(1)


*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>> ans;
        int n=strs.size();
        for(string s:strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(s);
        }
        for( auto &it:mpp){
            ans.push_back(it.second);
        }
        return ans;

    }
};