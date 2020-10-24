class Solution {
public:
    int uniquePaths(int m, int n) {
        int m_maxIndex = m - 1;
        int n_maxIndex = n - 1;
        
        return getWays(m_maxIndex, n_maxIndex);
    }


        int getWays(int i, int j) {
            int numWays;
            if (i == 0 && j == 1) {
                numWays = 1;
            }

            if (i == 1 && j == 0) {
                numWays = 1;
            }
            /**
            if (i == 1 && j == 1) {
                numWays = 2;
            }
            **/
            if(i == 0 && j > 1) //0th row
                return getWays(i, j-1);
            if (i > 0 && j > 0)//middle and bottom row and not in in the 0th column
                return getWays(i, j - 1) + getWays(i - 1, j);
            if (i > 1 && j == 0)//it is in the 0th column
                return getWays(i - 1, j);
        
            return numWays;
        }
};