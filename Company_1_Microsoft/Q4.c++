#include<bits/stdc++.h>
using namespace std;
// 4.You are given an integer array nums of length n. Return maximum length of Rotation Function.
// https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,sum2=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum2+=(i*nums[i]);
        }
        int ans = sum2;
        for(int i=nums.size()-1;i>=0;i--){
            sum2 =sum2+sum-(nums.size()*nums[i]);
            ans=max(ans,sum2);
        }
        return ans;
    }
};