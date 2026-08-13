/*
Problem: valid anagram
Platform: LeetCode
Difficulty:easy

Approach 1: Brute force Approach
Time Complexity:O(nlogn)
Space Complexity:O(1)

----------------------------------
Approach 2: Better approach
Time Complexity:O(n+m)=O(1) assume n==m(size)
Space Complexity:O(26)+O(26)=O(1) -2 freq vectors

----------------------------------

Approach 2: optimal soln
Time Complexity:O(1)
Space Complexity:O(1)- one vector -freq


*/
//brute force 
class Solution {
public:
    bool isAnagram(string s, string t) {
      sort(s.begin(),s.end());
      sort(t.begin(),t.end());
      if(s==t){
        return true;
      }
      else{
        return false;
      }
    }
};
//better approach 
 vector<int> freq1(26,0);
    for(char c:s){
        freq1[c-'a']++;
    }
    vector<int> freq2(26,0);
    for(char c:t){
        freq2[c-'a']++;
    }
    if(freq1==freq2){
        return true;
    }
    else{
        return false;
    }
//optimal solution
class Solution {
public:
    bool isAnagram(string s, string t) {

     vector<int> freq(26,0);
    for(char c:s){
        freq[c-'a']++;
    }
    for(char c:t){
        freq[c-'a']--;
    }
    for(int x:freq){
        if(x!=0){
            return false;
        }

    }
    return true;
    }
};

