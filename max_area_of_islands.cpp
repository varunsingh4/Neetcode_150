class Solution {
public:
    int  area(vector<vector<int>>& grid,int i , int j ,int area_,int m,int n){
        if( i < 0 || j < 0 || i >= m || j >= n ||  grid[i][j] == 0)
        {
            return 0;
        }
        area_++;
        grid[i][j]=0;

       return 1+ area(grid,i+1,j,area_,m,n)+
        area(grid,i,j+1,area_,m,n)+
        area(grid,i-1,j,area_,m,n)+
        area(grid,i,j-1,area_,m,n);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area_=0;
        int max__=0;
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
             
                if(grid[i][j] == 1)
                {
                    int a = area(grid, i , j , area_, m , n);
                    max__=max(a,max__);

                }

            }
        }
        return max__;


        
    }
};
