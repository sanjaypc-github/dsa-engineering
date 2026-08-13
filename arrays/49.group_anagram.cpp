/*
Problem: group anagram
Platform: LeetCode
Difficulty:medium

Approach 1: Brute force Approach
Time Complexity:O(n * nlog n)
Space Complexity:O(n*k)

----------------------------------

Approach 2: optimal soln
Time Complexity:O(n* k)
Space Complexity:O(n* k)


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

//optimal soln
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(string word:strs){
            vector<int>freq(26,0);
            for(char c:word){
                freq[c-'a']++;
            }
            string key="";
            for(int it:freq){
                key+='#';
                key+=to_string(it);
            }
            mpp[key].push_back(word);

        }
        vector<vector<string>>ans;
        for(auto &it:mpp){
            ans.push_back(it.second);
        }
        return ans;

    }
};