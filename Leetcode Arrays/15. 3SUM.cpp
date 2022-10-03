/*Link Of Question : https://leetcode.com/problems/3sum/
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Note: The solution set must not contain duplicate triplets.
*/
//Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        /* Now fix the first element one by one and find the
       other two elements */
        for(int i=0;i<n-2;i++)
        {
        /* To find the other two elements, start two index
        variables from two corners of the vector and move
        them toward each other */
            int l=i+1,
                r=n-1;
            if (i > 0 && nums[i] == nums[i - 1]) /* Skipping as we will get same set of solutions */
                continue;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                { 
                    ans.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1])l++;/* Skipping as we will get same set of solutions */
                    while(l<r && nums[r]==nums[r-1])r--;/* Skipping as we will get same set of solutions */
                    l++;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0)l++;
                else r--;
            }

        }

        return ans;
    }
};
/*
Sample Input : nums = [-1,0,1,2,-1,-4]
Sample output : [[-1,-1,2],[-1,0,1]]
Time Complexity : O(N*N)
Space Complexity : O(1)
*/


// ALTER CODE-->

// Runtime: 82 ms
// Memory Usage: 21.9 MB

class Solution {
public:
    
    #define pb push_back
    vector<vector<int>> ans;
    void th_sum(vector<int> &nums){
        for(int i =0 ; i<nums.size()-2 ; i++){
            if(i==0 || nums[i] != nums[i-1]){
                //is upar wale se i repeat nhi hoga
                int j = i+1;
                int k = nums.size()-1;
                while(j<k){
                    int sum_of_3 = nums[i]+nums[j]+nums[k];
                 /*condition no. 1*/   if(sum_of_3==0){
                        ans.pb({nums[i],nums[j],nums[k]});
                        while(j<k and nums[j]==nums[j+1]){
                            j++;
                        }
                        while(j<k and nums[k]==nums[k-1]){
                            k--;
                        }
                        j++;
                        k--;
                    }
                /*condition no. 2*/ else if(sum_of_3<0){
                    j++;
                }
                    else{
                        k--;
                    }
                }
            }
        } 
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        th_sum(nums);
        return ans;
    }
};
