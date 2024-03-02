class Solution {
public:
    void dynamicApproach(int i, vector<int> &nums, int &maxEndingHere, int &minEndingHere, int &product) 
    {
        if (i == nums.size())
            return;
        int temp = maxEndingHere;
        maxEndingHere = max(nums[i], max(nums[i] * maxEndingHere, nums[i] * minEndingHere));
        minEndingHere = min(nums[i], min(nums[i] * temp, nums[i] * minEndingHere));
        product = max(product, maxEndingHere);
        dynamicApproach(i + 1, nums, maxEndingHere, minEndingHere, product);
    }
    int maxProduct(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        int product = nums[0];
        dynamicApproach(1, nums, maxEndingHere, minEndingHere, product);
        return product;
    }
};
