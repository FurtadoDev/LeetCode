class Solution {
public:


	int uniquePaths(int m, int n) {
    int m_maxIndex = m - 1;
    int n_maxIndex = n - 1;
    vector<int> helpervector;
    helpervector.reserve(m*n);
    int vectorsize = m * n;
    for (int i = 0; i < vectorsize; i++) {
        helpervector.push_back(0);
    }
    if (m == 1 && n == 1) {
        return  1;
    }
    else {
        int tempIndex = 0;
        for (int i = 0; i <= m_maxIndex; i++) {//row number
            for (int j = 0; j <= n_maxIndex; j++) { //col number
                tempIndex = (n * i) + j;
                if (i == 0) {// we're in the top row
                    if (j == 0)
                        helpervector[tempIndex] = 0;
                    else if (j == 1)
                        helpervector[tempIndex] = 1;
                    else
                        helpervector[tempIndex] = helpervector[(n * i) + (j - 1)];
                }
                else {// we're not in the top row
                    if (j == 0) { //we're in the first column
                        if (i == 1)
                            helpervector[tempIndex] = 1;
                        else
                            helpervector[tempIndex] = helpervector[(n * (i - 1)) + j];
                    }
                    else {
                        helpervector[tempIndex] = helpervector[(n * i) + (j - 1)] + helpervector[(n * (i - 1)) + j];
                    }

                }

            }
        }
        int answer = helpervector[(m * n) - 1];
        helpervector.clear();
        return answer;
    }
    }

	/**
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
            
            if(i == 0 && j > 1) //0th row
                return getWays(i, j-1);
            if (i > 0 && j > 0)//middle and bottom row and not in in the 0th column
                return getWays(i, j - 1) + getWays(i - 1, j);
            if (i > 1 && j == 0)//it is in the 0th column
                return getWays(i - 1, j);
        
            return numWays;
        }
		**/
};