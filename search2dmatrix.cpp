class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //core intuition and logic is that we have to perform linear binary search row by row
        //perform binary search in each row this is the most optmised way of doing this
        
        
            for(int i=0;i<matrix.size();i++)
            {
                int low=0;
                int high=matrix[0].size()-1;
                while(low<=high)
                {
                     int mid=low+(high-low)/2;
                    if(matrix[i][mid]== target)
                    {
                        return true;
                     }
                    if(matrix[i][mid] > target)
                    {
                    high=mid-1;
                    }
                    else{
                        low=mid+1;
                     }
                 }

               

            }
            return false;
            
        
       

    }
};
