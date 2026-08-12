/*
Problem: insert Intervals
Platform: LeetCode
Difficulty:medium

Approach 2:optimal
Time Complexity:O(n)
Space Complexity:O(n)


*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newarr) {
        int n=arr.size();
        int i=0;
        vector<vector<int>>ans;
        while(i<n && arr[i][1]<newarr[0]){
            ans.push_back(arr[i]);
            i++;
        }
        while(i<n && arr[i][0]<=newarr[1]){
            newarr[0]=min(newarr[0],arr[i][0]);
            newarr[1]=max(newarr[1],arr[i][1]);
            
            i++;
        }
        ans.push_back(newarr);
        while(i<n){
            ans.push_back(arr[i]);
            i++;
        }
        
        return ans;
    }
};