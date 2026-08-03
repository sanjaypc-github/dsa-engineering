//sliding window approach TC : O(n)  SC:O(number of unique elements in the string)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0;
        unordered_map<int,int> mpp;
        int i=0;
        for(int j=0;j<n;j++){
            if(mpp.find(s[j])!=mpp.end()){
                i=max(i,mpp[s[j]]+1);
                

            }
            maxi=max(maxi,j-i+1);
            mpp[s[j]]=j;
        }
        return maxi;   
    }
};