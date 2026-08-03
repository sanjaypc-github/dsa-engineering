/*
Problem: Best Time to buy and sell stocks
Platform: LeetCode
Difficulty:Easy 

Approach 1: Brute force
Time Complexity:O(n^2)
Space Complexity:O(1)

----------------------------------

Approach 2: using a mathematical calculation and conditional constraints 1- for loop to find max , min value , best profit
Time Complexity:O(n)
Space Complexity:O(1) 

----------------------------------

*/
//brute force approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int res=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res=prices[j]-prices[i];
                maxi=max(maxi,res);
            }
        }
        return maxi;

    }
};

// optimal soln
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mini=INT_MAX;
        int proft=0;
        int maxi=0;
        int n= prices.size();
        for(int i=0;i<n;i++){
            mini=min(prices[i],mini);
            proft=prices[i]-mini;
            maxi=max(maxi,proft);

        }
        return maxi;
    }
};