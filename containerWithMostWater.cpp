class Solution {
public:
    int maxArea(vector<int>& height) {
 
        int inputSize = height.size();
        size_t leftIndex = 0;
        size_t rightIndex = inputSize -1;
        int tempArea = 0;
        int maxArea = 0;
        while(leftIndex != rightIndex){
            if(rightIndex-leftIndex == 1){
                tempArea = 1 * min(height[leftIndex], height[rightIndex]);
                leftIndex++;
            }else{
                tempArea = (rightIndex-leftIndex) * min(height[leftIndex], height[rightIndex]);
                if(height[leftIndex] < height[rightIndex])
                    leftIndex++;
                else
                    rightIndex--;
            } 
            maxArea = max(maxArea, tempArea);
        }
        return maxArea;
    }
};