/*************************************************************************
    > File Name: rectangleArea.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-04 20:01:33
 ************************************************************************/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        bool x_overlap = false;
        bool y_overlap = false;
        int x, y;
        if (E >= A && E <= C)
        {
            x_overlap = true;
            x = min(C, G) - E;
        }
        else if (A >= E && A <= G)
        {
            x_overlap = true;
            x = min(C, G) - A;
        }
        
        if (F >= B && F <= D)
        {
            y_overlap = true;
            y = min(D, H) - F;
        }
        else if (B >= F && B <= H)
        {
            y_overlap = true;
            y = min(D, H) - B;
        }
        
        if (x_overlap && y_overlap)
        {
            area -= x * y;
        }
        
        return area;
    }
};
