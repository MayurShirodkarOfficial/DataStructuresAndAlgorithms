#include <iostream>
#include <vector>
using namespace std;

class solution
{
private:
    void solve(vector<int> nums, vector<vector<int>> ans, int index)
    {
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = index; j < nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            solve(nums, ans, index + 1);
            // backtracking to prevent the inconsistency in the original string....
            //....as we are uing original string to maipulate here
            swap(nums[index], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};