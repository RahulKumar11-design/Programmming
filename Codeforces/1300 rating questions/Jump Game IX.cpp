#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pid_max(n,0);
        
        for(int i=1;i<n;i++){
            if(nums[pid_max[i-1]]>=nums[i]){
                pid_max[i] = pid_max[i-1];
            }else{
                pid_max[i] = i;
            }
        }

        int r = pid_max[n-1],rmin=nums[n-1],maxi;
        maxi = nums[r];
        vector<int> ans(n);
        ans[n-1] = maxi;

        for(int i=r;i<n-1;i++){
            rmin = min(rmin,nums[i]);

            ans[i] = maxi;
        }

        while(r>0){
            int l=pid_max[r-1],rmax;
            rmax = nums[l];

            if(rmax<=rmin){
                maxi = rmax;
            }

            for(int i=l;i<r;i++){
                rmin = min(rmin,nums[i]);

                ans[i] = maxi;
            }

            r = l;
        }

        return ans;
    }
};