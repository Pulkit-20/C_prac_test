#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i == 0 || nums[i-1] != nums[i]){
                int sum = -nums[i];
                int k = nums.size()-1;
                int l = i+1;
                while(l < k){
                    if(nums[l] + nums[k] == sum){
                        ans.push_back({nums[i], nums[l], nums[k]});
                        while(l < k &&  nums[l] == nums[l+1]){
                            l++;
                        }
                        while(l < k && nums[k] == nums[k-1]){
                            k--;
                        }
                        l++;
                        k--;
                    }
                    else if(nums[l] + nums[k] < sum){
                        l++;
                    }
                    else{
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};