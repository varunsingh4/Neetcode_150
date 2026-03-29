class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char,int>m1;
        priority_queue<int>p1;
        vector<int>temp;
        for(int i=0;i<tasks.size();i++)
        {
            m1[tasks[i]]++;
        }
        for(auto it:m1)
        {
            p1.push(it.second);
        }
        int slot = n + 1 ; 
        while(!p1.empty())
        {
            int slot = n + 1 ; 
            temp.clear();
            while( slot > 0  && !p1.empty())
            {
                 
                int freq = p1.top();
                freq--;
                time++;
                if (freq > 0) {
                  temp.push_back(freq);
                }
                p1.pop();
                slot -- ;
            }
           
            for(int i = 0 ; i < temp.size() ; i ++ )
            {
                p1.push(temp[i]);
            }
             if(!p1.empty())
            {
                time = time + slot ; 

            }



        }
        
        return time ;

        
    }
};
