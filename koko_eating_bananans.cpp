class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //intuition find search space and then see hour calculation how much can koko eat from pile
        int low=1;
        int max_=0;
        int high=*max_element(piles.begin(),piles.end());
        int k=0;
        while(low<high)
        {
             k=low+(high-low)/2;
            long long hours=0;
            for(int pile:piles)
            {
                hours=hours+(pile+k-1)/k;
            }
            if(hours > h)
            {
                low=k+1;
            }
            else{
                high=k;
            }
        }
        return low;

        

        
    }
};
