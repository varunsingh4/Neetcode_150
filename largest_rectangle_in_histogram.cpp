class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s1;
        int max_area=0;
        int width=0;
        int area=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!s1.empty() && heights[s1.top()] > heights[i])
            {
              
                int top=s1.top();
                s1.pop();
                if(s1.empty())
                {
                    width=i;
                }
                else{
                     width=i-s1.top()-1;

                }
                area=heights[top]*width;
                max_area=max(max_area,area);
               
            }
            s1.push(i);
        }
        int n = heights.size();
        while (!s1.empty()) {
            int top = s1.top();
            s1.pop();

            int width;
            if (s1.empty())
                width = n;
            else
                width = n - s1.top() - 1;

            int area = heights[top] * width;
            max_area = max(max_area, area);
        }

        return max_area;
    }
};
