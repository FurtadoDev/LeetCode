class Solution {
public:
    int maxProduct(vector<int>& nums) {
        size_t nums_size = nums.size();
        std::vector<int> max_prod(nums_size, 0);
        std::vector<int> min_prod(nums_size, 0);
        int maxProduct = 0;
        
        if(nums_size == 1) return nums[0];
            
        max_prod[0] = nums[0];
        min_prod[0] = nums[0];
        maxProduct = max_prod[0];
        for(size_t i = 1; i < nums_size; i++){
            max_prod[i] = max(max(nums[i], max_prod[i - 1] * nums[i]), min_prod[i - 1] * nums[i]);
            min_prod[i] = min(min(nums[i], min_prod[i - 1] * nums[i]), max_prod[i - 1] * nums[i]);
            
            if(max_prod[i] > maxProduct)
                maxProduct = max_prod[i];
        }
        
        return maxProduct;
    }
};