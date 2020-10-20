#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int maxSubArray(vector<int>& nums);

int main() {
    std::vector<int> nums;
    nums.push_back(-2);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(-3);
    int result = maxSubArray(nums);
    std::cout << result << endl;

    return 0;
}


int maxSubArray(vector<int>& nums) {
    int inputSize = nums.size();
    int maxSum = nums[0];
    int temp = 0;
    for (int i = 0; i < inputSize; i++) {
        temp = max(temp + nums[i], nums[i]); //or use the below commented code
        /**
        temp = temp + nums[i];
        if (temp < nums[i])
            temp = nums[i];
        **/
        if (temp > maxSum)
            maxSum = temp;
    }
    return maxSum;
}