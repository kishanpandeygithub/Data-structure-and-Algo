// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
class Solution {
public:
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();    // m
        int cols = mat[0].size(); // n

        vector<vector<int>> prifix(rows, vector<int>(cols, 0));
        // prifix[i][j] = sum of all the value from the top_left [0][0]
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prifix[i][j] = (i > 0 ? prifix[i - 1][j] : 0) +
                               (j > 0 ? prifix[i][j - 1] : 0) -
                               ((i > 0 && j > 0) ? prifix[i - 1][j - 1] : 0) +
                               mat[i][j];
            }
        }
        auto sumOfSqure =[&](int i ,int j ,int r2 ,int c2){
            int sum = prifix[r2][c2];
            sum-= (i>0? prifix[i-1][c2]:0);
            sum-= (j>0? prifix[r2][j-1]:0);
            sum+= ((i>0&& j>0)? prifix[i-1][j-1]:0);
            return sum;
        };
        int best = 0;
        for( int i =0;i< rows;i++){
            for(int j =0;j< cols;j++){

                //here the k represent the offset of the valeu that represent the maximum number of the squre which can be made
                for( int k =0;k< min(rows-i , cols-j);k++){
                    int r2 =i+k;
                    int c2 = j+k;
                    int sum =  sumOfSqure(i ,j , r2 , c2);
                    if(sum<= threshold){
                        best =max(best  ,k+1);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return best;
    }
};