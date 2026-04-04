class Solution {
public:
    int mySqrt(int x) {
        int low = 1 ; 
        int high =  x /2 ;
        int ans =  0 ; 
        if ( x < 2)
        {
             return x ;
        }
        while ( low <= high)
        {
            int mid = low + ( high - low) / 2 ;
            long long int sq = 1LL * mid * mid;
           
            if( sq ==  x) 
            {
                return  mid;
            }
            else if ( sq  < x)
            {
                 ans = mid;
                 low = mid + 1 ;

            }
            else{

                high = mid - 1 ; 

            }

        }
        return ans;
    }
};
