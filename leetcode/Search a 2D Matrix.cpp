class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix.front().size();
        int low = 0;
        int high = m*n-1;
        while( low <= high )
        {
            int mid = low + (high - low)/2;
            if( matrix[mid/m][mid%m] == target ) return true;
            if( matrix[mid/m][mid%m] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
};