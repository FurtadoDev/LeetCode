#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int inputSize = nums.size();
        vector<int> results;

        std::unordered_map<int, int> hashmap;
        for (int i = 0; i < inputSize; i++) {
            int num1 = nums[i];
            int num2 = target - nums[i];
            if (hashmap.find(num2) != hashmap.end()) {
                result.push_back(i); //index1
                result.push_back(hashmap[num2]); //index2
                break;
            }
            else {
                hashmap[num1] = i;
            }
        }
        return result;
    }
        
};