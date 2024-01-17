#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int toSwap = -1;
        int n = nums.size();
        for(int i= n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                toSwap = i;
                break;
            }
        }

        for(int i =n-1;i>= toSwap && toSwap != -1; i--){
            if(nums[i]> nums[toSwap]){
                swap(nums[i],nums[toSwap]);
                break;
            }
        }
        reverse(nums.begin() + toSwap +1, nums.end());
    }
};