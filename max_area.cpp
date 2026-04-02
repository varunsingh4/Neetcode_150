class Solution {
public:
    int area(vector<vector<int>>& grid, int i , int j , int m , int n)
    {
        if( i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
        {
            return 0;
        }
        grid[i][j] = 0;

        return 1+ area( grid , i+1 , j , m , n ) +area( grid , i   , j+1 , m , n ) +area( grid , i-1 , j , m , n) +area( grid , i   , j-1, m , n);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = 0;
        for( int i = 0 ; i < m ; i++)
        {
            for( int j = 0 ; j < n ; j++)
            {
                if ( grid [i][j] == 1 )
                {
                   int area_ =  area( grid, i , j , m , n );
                   max_area  =  max( max_area , area_ );
                }

            }  
        }
        return max_area;
        
    }
};
