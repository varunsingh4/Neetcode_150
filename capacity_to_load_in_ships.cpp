class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0 ; 
        int no_of_days = 0 ;
        int current_load = 0 ; 
        for(int i = 0 ; i < weights.size(); i ++)
        {
            sum +=weights[i];
        }
        int low = *max_element(weights.begin(),weights.end());
        int high = sum ; 
        while( low < high)
        {
            int mid = low + ( high - low ) / 2 ;
            no_of_days = 1 ;
            int current_load = 0 ;
            for(int i = 0 ; i < weights.size() ; i ++ )
            {
                if( weights[i] + current_load  > mid )
                {
                    no_of_days ++ ;
                    current_load = 0 ;

                }
                current_load = current_load + weights[i];
 
            }
            if(no_of_days <= days)
            {
                high = mid ;

            }
            else{

                low = mid  + 1 ; 

            }

        }
        return low ;
        
    }
};
