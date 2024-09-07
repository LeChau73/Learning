#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int index = 0 , length = 0, larget_sum = 0, sum = 0;
        larget_sum = nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            sum = nums[i];
            for (int j = i + 1; j < nums.size() ; j++)
            {
                sum += nums[j];
                if (sum > larget_sum)
                {
                    larget_sum = sum;
                }
                if(nums[j] > larget_sum){
                    larget_sum = nums[j];
                }
            }
            
        }
        return larget_sum;
    }
};

int main() {
    vector<int> v{-2,1};
    Solution slu;
    cout << slu.maxSubArray(v);
}