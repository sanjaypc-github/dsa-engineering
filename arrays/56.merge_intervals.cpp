/*
Problem: Merge Intervals
Platform: LeetCode
Difficulty:medium

Approach 1: brute force
Time Complexity:O(nlogn)-sorting * O(2n)-because we are skipping and vreaking most of the time
Space Complexity:O(n)

----------------------------------

Approach 2:optimal
Time Complexity:O(nlogn * n)
Space Complexity:O(n)


*/
//brute force
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int start =arr[i][0];
            int end=arr[i][1];
            if(!ans.empty() && end <=ans.back()[1]){
                continue;
            }
            for(int j=0;j<i+1;j++){
                if(arr[j][0]<=end){
                    end=max(end,arr[j][1]);
                }
                else{
                    break;
                }
            }
         ans.push_back({start,end});
        }
        return ans;
    }
};

//optimal approach
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || arr[i][0]>ans.back()[1]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],arr[i][1]);
            }
        }
        return ans;
    }
};