class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= leftMax) {
                    leftMax = height[l];
                } else {
                    ans += leftMax - height[l];
                }
                l++;
            } else {
                if (height[r] >= rightMax) {
                    rightMax = height[r];
                } else {
                    ans += rightMax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};

/*
INTUITION (O(n) time, O(1) space):

Water trapped at any index i depends on:
    min(max height to the left, max height to the right) - height[i]

Instead of storing leftMax[] and rightMax[] arrays,
we use two pointers and keep track of the maximum walls seen so far
from both ends.

Key idea:
- Water is always limited by the SHORTER boundary.
- So we always process the side with the smaller height.

Two pointers:
- l starts from the left, r starts from the right
- leftMax = highest wall seen so far from the left
- rightMax = highest wall seen so far from the right

At each step:
1) If height[l] < height[r]:
   - The left side is the limiting boundary.
   - There MUST exist a right wall >= height[l],
     so water at l depends only on leftMax.
   - If height[l] < leftMax, water = leftMax - height[l]
   - Move l forward.

2) Else:
   - The right side is the limiting boundary.
   - There MUST exist a left wall >= height[r],
     so water at r depends only on rightMax.
   - If height[r] < rightMax, water = rightMax - height[r]
   - Move r backward.

Each index is processed exactly once,
giving O(n) time and O(1) extra space.
*/
